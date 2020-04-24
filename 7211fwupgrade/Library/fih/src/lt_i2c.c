#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"


/**外部变量 --------------------------------------------------*/


/**私有函数 ---------------------------------------------------*/
static void iic_delay(void);
static FlagStatus ack;

/**公有函数 ---------------------------------------------------*/
/**
	* @brief				IIC start
	* @param				None
	* @retval 			 	None
	* @note					当SCL处于高电平状态时，SDA出现一个下降沿
									即产生IIC启动信号
	*/
static void iic_start(void)
{
	LT_IIC_SCL(GPIO_PIN_SET);
	/** SDA High->Low */
	LT_IIC_SDA(GPIO_PIN_SET);
	iic_delay();
	LT_IIC_SDA(GPIO_PIN_RESET);
	iic_delay();
	LT_IIC_SCL(GPIO_PIN_RESET); //Pull down and prepare send data
	iic_delay();
}	
	
/**
	* @brief				IIC stop
	*	@param				None
	* @retval 			None
	* @note					当SCL处于高电平状态时，SDA出现一个下上升沿
									即产生IIC停止信号
	*/	
static void	iic_stop(void)
{
	LT_IIC_SCL(GPIO_PIN_RESET);
	iic_delay();
	/** SDA Low -> High */
	LT_IIC_SDA(GPIO_PIN_RESET);
	iic_delay();
	
	LT_IIC_SCL(GPIO_PIN_SET);
	iic_delay();
	LT_IIC_SDA(GPIO_PIN_SET);
	iic_delay();
}
	
/**
	* @brief				IIC send 1 byte
	*	@param				byte
	* @retval 			None
	* @note					
	*/	
static void iic_sendbyte(uint8_t byte)
{
	uint8_t bit_cnt;
	
	/** send bit[7] of byte */
	for(bit_cnt = 0; bit_cnt < 8; bit_cnt++)
	{
		LT_IIC_SCL(GPIO_PIN_RESET);	
		if( (byte<<bit_cnt) & 0x80)
		{
			LT_IIC_SDA(GPIO_PIN_SET);
		}
		else
		{
			LT_IIC_SDA(GPIO_PIN_RESET);
		}
		iic_delay();
		LT_IIC_SCL(GPIO_PIN_SET);
		iic_delay();
	}
	LT_IIC_SCL(GPIO_PIN_RESET);
	iic_delay();	
	LT_IIC_SDA(GPIO_PIN_SET);
	iic_delay();
	LT_IIC_SCL(GPIO_PIN_SET);
	iic_delay();
	if(LT_IIC_SDA_IS_HIGH())
	{
		ack = RESET;
	}
	else
	{
		ack = SET;
	}

}

/**
	* @brief				IIC Read 1 byte
	*	@param				None
	* @retval 			read byte
	* @note					
	*/
static uint8_t iic_readbyte(void)
{
	uint8_t bit_cnt;
	uint8_t recv_value = 0;
	
	LT_IIC_SDA(GPIO_PIN_SET);
	for(bit_cnt = 0; bit_cnt < 8; bit_cnt++)
	{
		LT_IIC_SCL(GPIO_PIN_RESET);
		iic_delay();
		LT_IIC_SCL(GPIO_PIN_SET);
		recv_value <<= 1;
		if( LT_IIC_SDA_IS_HIGH() )
		{
			recv_value  |= 0x01;
		}	
		iic_delay();
	}
	LT_IIC_SCL(GPIO_PIN_RESET);
	iic_delay();
	return recv_value;
}
		
/**
	* @brief				IIC Wait ack
	*	@param				None
	* @retval 			ack status 0:ack; 1:no-ack;
	* @note					
	*/		

/**
	* @brief				iic ack
	*	@param				None
	* @retval 			None
	* @note					When get read data, reply ack
	*/	
static void iic_ack(void)
{
	LT_IIC_SDA(GPIO_PIN_RESET);
	iic_delay();
	LT_IIC_SCL(GPIO_PIN_SET);
	iic_delay();
	LT_IIC_SCL(GPIO_PIN_RESET);
	iic_delay();
	LT_IIC_SDA(GPIO_PIN_SET);
}

/**
	* @brief				iic nack
	*	@param				None
	* @retval 			None
	* @note					When get read data, reply nack
	*/	
static void iic_nack(void)
{
	LT_IIC_SDA(GPIO_PIN_SET);
	iic_delay();
	LT_IIC_SCL(GPIO_PIN_SET);
	iic_delay();
	LT_IIC_SCL(GPIO_PIN_RESET);
	iic_delay();
}

/**
	* @brief				Cehck status of IIC Bus
	*	@param				device_addr
	* @retval 			ack_status
	* @note					Master send device address, if receive ack, slave attached; else no slave
	*/	

/**私有函数----------------------------------------------------------*/
/**
	* @brief				delay for iic
	*	@param				None
	* @retval 			None
	* @note					Adjust IIC speed
	*/	
static void iic_delay()
{
	uint8_t delay  = 6;
	while(delay--);

}

/**
	* @brief				iic write byte funtion
	*	@param				device address, reg address, data, number
	* @retval 			result
	* @note					
	*/	
static uint8_t iic_write_byte(uint8_t sla, uint8_t suba, uint8_t *s, uint8_t Num)
{
	uint16_t i;
	iic_start();
	iic_sendbyte(sla);
	if(ack == RESET)
	{
	}
	iic_sendbyte(suba);
	if(ack == RESET)
	{
	}
	for(i=0; i<Num; i++)
	{
		iic_sendbyte(*s);
		if(ack == RESET)
		{
		}
		s++;
	}
	iic_stop();
	return 1;
}

/**
	* @brief				iic read byte funtion
	*	@param				device address, reg address, data, number
	* @retval 			result
	* @note					
	*/
static uint8_t iic_read_byte(uint8_t sla,uint8_t suba,uint8_t *s, uint16_t Num)
{
	uint16_t i;
	iic_start();
	iic_sendbyte(sla);	
	iic_sendbyte(suba);
	iic_delay();
	LT_IIC_SCL(GPIO_PIN_RESET);
	iic_delay();
	iic_delay();		
	iic_start();
	iic_sendbyte(sla+1);
	if(ack==RESET)
	{
		*s = 0x00;
	}	
	for(i=0; i<Num-1; i++)
	{
		*s = iic_readbyte();
		iic_ack();
		s++;
	}
	*s = iic_readbyte();
	iic_nack();
	iic_stop();
	return 1;
}


/**
	* @brief				HDMI Write IIC
	*	@param				None
	* @retval 			None
	* @note					Get slave whether ack
	*/	
int LT_WriteI2C_Byte(uint8_t RegAddr, uint8_t Data)
{
	return iic_write_byte(LT7211, RegAddr, &Data, 1);	
}

int LT_WriteI2C_ByteN(uint8_t RegAddr, uint8_t *P_Data, uint16_t N)
{
	return iic_write_byte(LT7211, RegAddr, P_Data, N);	
}		

/**
	* @brief				HDMI Read IIC
	*	@param				None
	* @retval 			None
	* @note					Get slave whether ack
	*/	
uint8_t LT_ReadI2C_Byte(uint8_t RegAddr)
{
	uint8_t p_data=0;
	if(iic_read_byte(LT7211, RegAddr, &p_data, 1) != 1 )
	{
			return 0;
	}
	return p_data;
}

int LT_ReadI2C_ByteN(uint8_t RegAddr, uint8_t *p_data, uint16_t N)
{
	if( iic_read_byte(LT7211, RegAddr, p_data, N) != 1)
	{
		return 0;
	}
	return 1;
}

void LtChipID(void)
{
    uint8_t i,j;
	LT_WriteI2C_Byte(0xff,0x80);
	LT_WriteI2C_Byte(0xee,0x01);
	LT_WriteI2C_Byte(0xff,0xa0);

	i = LT_ReadI2C_Byte(0x00);
	j = LT_ReadI2C_Byte(0x01);
#ifdef LT_IIC_DEBUG
    printf("chip id is ox %x, %x\n",i,j);
#endif
}

void LT_Read_Mode(void)
{
    uint8_t i,j;
	LT_WriteI2C_Byte(0xff,0x80);
	LT_WriteI2C_Byte(0xee,0x01);
	LT_WriteI2C_Byte(0xff,0xa0);

	i = LT_ReadI2C_Byte(0x43);
	j = LT_ReadI2C_Byte(0x1D);
#ifdef LT_IIC_DEBUG
    printf("gpio 1 is  %x, mode is %x\n",j,i);
#endif
}
