#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"

static uint8_t s_EcxInit[130] = {
0x0e,0x00,0x40,0xa0,0x5f,0x80,0x00,0x40,0x00,0x56,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xc0,0x40,0x40,0x80,0x40,0x40,0x40,0x0a,0x5d,0x22,0x10,
0x60,0x44,0x20,0x29,0x61,0x00,0x00,0x00,0x40,0x58,0x28,0x00,0x00,0x00,0x19,0x1a,
0x44,0x0d,0x0e,0xff,0x00,0x24,0xdd,0x00,0x05,0x04,0x35,0x07,0x5d,0x0a,0xe6,0x03,
0x5d,0x00,0x01,0x7b,0x00,0x17,0x76,0x00,0x76,0x00,0x5a,0x00,0x0a,0x5d,0x0a,0x5d,
0x00,0x0a,0x41,0x00,0x51,0x0a,0x38,0x40,0x62,0x2f,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xe8,0x03,
0x00,0x4e,0x4e,0x00,0x41,0x27,0x85,0x30,0x06,0x36,0x80,0x25,0x47,0x61,0x00,0x00,
0x01,0x81
};

void Spi_WriteReg_1(uint8_t reg, uint8_t u8Value)
{
    // CS: active
    OLED_CS1 = 0;
	OLED_CS2 = 1;
    // send Command: register num
#ifdef BIT_16_TRANSFER
    SPI_WRITE_TX(SPI_OLED_PORT, (reg << 8 | u8Value));
#else
    SPI_WRITE_TX(SPI_OLED_PORT, reg);
    SPI_TRIGGER(SPI2);
    while(SPI_IS_BUSY(SPI_OLED_PORT));
    SPI_WRITE_TX(SPI_OLED_PORT, u8Value);
#endif

	SPI_TRIGGER(SPI2);

    // wait tx finish
    while(SPI_IS_BUSY(SPI_OLED_PORT));

    // /CS: de-active
	OLED_CS1 = 1;
}
void Spi_WriteReg_2(uint8_t reg, uint8_t u8Value)
{
    // CS: active
	OLED_CS1 = 1;
	OLED_CS2 = 0;
    // send Command: register num
#ifdef BIT_16_TRANSFER
    SPI_WRITE_TX(SPI_OLED_PORT, (reg << 8 | u8Value));
#else
    SPI_WRITE_TX(SPI_OLED_PORT, reg);
    SPI_TRIGGER(SPI2);
    while(SPI_IS_BUSY(SPI_OLED_PORT));
    SPI_WRITE_TX(SPI_OLED_PORT, u8Value);
#endif

	SPI_TRIGGER(SPI2);

    // wait tx finish
    while(SPI_IS_BUSY(SPI_OLED_PORT));

    // /CS: de-active
	OLED_CS2 = 1;
}
uint8_t Spi_ReadReg_1(uint8_t reg)
{
	uint8_t ReturnValue;
    // /CS: active
    OLED_CS1 = 0;
	OLED_CS2 = 1;

#ifdef BIT_16_TRANSFER
	SPI_WRITE_TX(SPI_OLED_PORT, (0x80 << 8 | 0x01));
#else
    SPI_WRITE_TX(SPI_OLED_PORT, 0x80);
    SPI_TRIGGER(SPI2);
    while(SPI_IS_BUSY(SPI_OLED_PORT));
    SPI_WRITE_TX(SPI_OLED_PORT, 0x01);
#endif
	SPI_TRIGGER(SPI2);
	while(SPI_IS_BUSY(SPI_OLED_PORT));
    OLED_CS1 = 1;
    delay_ms(1);
    OLED_CS1 = 0;
#ifdef BIT_16_TRANSFER
	SPI_WRITE_TX(SPI_OLED_PORT, (0x81 << 8 | reg));
#else
    SPI_WRITE_TX(SPI_OLED_PORT, 0x81);
    SPI_TRIGGER(SPI2);
    while(SPI_IS_BUSY(SPI_OLED_PORT));
    SPI_WRITE_TX(SPI_OLED_PORT, reg);
#endif
	SPI_TRIGGER(SPI2);
	while(SPI_IS_BUSY(SPI_OLED_PORT));

    OLED_CS1 = 1;
    delay_ms(1);
    OLED_CS1 = 0;

#ifdef BIT_16_TRANSFER
	SPI_WRITE_TX(SPI_OLED_PORT, 0x81aa);
#else
    SPI_WRITE_TX(SPI_OLED_PORT, 0x81);
    SPI_TRIGGER(SPI2);
    while(SPI_IS_BUSY(SPI_OLED_PORT));
    SPI_WRITE_TX(SPI_OLED_PORT, 0xaa);
#endif
	SPI_TRIGGER(SPI2);
	while(SPI_IS_BUSY(SPI_OLED_PORT));

	OLED_CS1 = 1;

	ReturnValue = (SPI_READ_RX(SPI_OLED_PORT));

    return ReturnValue;
}
uint8_t Spi_ReadReg_2(uint8_t reg)
{
	uint8_t ReturnValue;
    // /CS: active
    OLED_CS1 = 1;
	OLED_CS2 = 0;

#ifdef BIT_16_TRANSFER
	SPI_WRITE_TX(SPI_OLED_PORT, (0x80 << 8 | 0x01));
#else
    SPI_WRITE_TX(SPI_OLED_PORT, 0x80);
    SPI_TRIGGER(SPI2);
    while(SPI_IS_BUSY(SPI_OLED_PORT));
    SPI_WRITE_TX(SPI_OLED_PORT, 0x01);
#endif
	SPI_TRIGGER(SPI2);
	while(SPI_IS_BUSY(SPI_OLED_PORT));
    OLED_CS2 = 1;
    delay_ms(1);
    OLED_CS2 = 0;
#ifdef BIT_16_TRANSFER
	SPI_WRITE_TX(SPI_OLED_PORT, (0x81 << 8 | reg));
#else
    SPI_WRITE_TX(SPI_OLED_PORT, 0x81);
    SPI_TRIGGER(SPI2);
    while(SPI_IS_BUSY(SPI_OLED_PORT));
    SPI_WRITE_TX(SPI_OLED_PORT, reg);
#endif
	SPI_TRIGGER(SPI2);
	while(SPI_IS_BUSY(SPI_OLED_PORT));

    OLED_CS2 = 1;
    delay_ms(1);
    OLED_CS2 = 0;

#ifdef BIT_16_TRANSFER
	SPI_WRITE_TX(SPI_OLED_PORT, 0x81aa);
#else
    SPI_WRITE_TX(SPI_OLED_PORT, 0x81);
    SPI_TRIGGER(SPI2);
    while(SPI_IS_BUSY(SPI_OLED_PORT));
    SPI_WRITE_TX(SPI_OLED_PORT, 0xaa);
#endif
	SPI_TRIGGER(SPI2);
	while(SPI_IS_BUSY(SPI_OLED_PORT));

	OLED_CS2 = 1;

	ReturnValue = (SPI_READ_RX(SPI_OLED_PORT));

    return ReturnValue;
}
void step_1(void)
{
	Spi_WriteReg_1(0x02,0x40);
	Spi_WriteReg_1(0x04,0x5f);
	Spi_WriteReg_1(0x6d,0x04);
	Spi_WriteReg_1(0x6f,0x03);
	Spi_WriteReg_1(0x71,0x4e);
	Spi_WriteReg_1(0x72,0x4e);
	delay_ms(1);	
	Spi_WriteReg_2(0x02,0x40);
	Spi_WriteReg_2(0x04,0x5f);
	Spi_WriteReg_2(0x6d,0x04);
	Spi_WriteReg_2(0x6f,0x03);
	Spi_WriteReg_2(0x71,0x4e);
	Spi_WriteReg_2(0x72,0x4e);
}

void step_2(void)
{
	Spi_WriteReg_1(0x00,0x0f);
	delay_ms(1);
	Spi_WriteReg_2(0x00,0x0f);
}

void step_3(void)
{
	Spi_WriteReg_1(0x01,0x01);
	delay_ms(1);
	Spi_WriteReg_2(0x01,0x01);
}

void step_4(void)
{
	Spi_WriteReg_1(0x04,0x3f);
	delay_ms(1);	
	Spi_WriteReg_2(0x04,0x3f);
}
void step_5(void)
{
	//LCD 1
	Spi_WriteReg_1(0x71,0x46);
	Spi_WriteReg_1(0x72,0x46);
	delay_ms(1);
	Spi_WriteReg_2(0x71,0x46);
	Spi_WriteReg_2(0x72,0x46);
}
void step_6(void)
{
	//LCD 1
	Spi_WriteReg_1(0x6D,0x00);
	Spi_WriteReg_1(0x6F,0x00);
	Spi_WriteReg_1(0x71,0x00);
	Spi_WriteReg_1(0x72,0x00);
	delay_ms(1);	
	Spi_WriteReg_2(0x6D,0x00);
	Spi_WriteReg_2(0x6F,0x00);
	Spi_WriteReg_2(0x71,0x00);
	Spi_WriteReg_2(0x72,0x00);
}

void step_6_1(void)
{
	Spi_WriteReg_1(0x03,0x20);
	delay_ms(1);
	Spi_WriteReg_2(0x03,0x20);
}

void ECX_PwrSv_1(void)
{
	//LCD 1
	Spi_WriteReg_1(0x00,0x0e);
	delay_ms(1);
	Spi_WriteReg_2(0x00,0x0e);
}

void ECX_PwrSv_2(void)
{
	//LCD 1
	Spi_WriteReg_1(0x01,0x00);
	delay_ms(1);
	Spi_WriteReg_2(0x01,0x00);
}

void Ecx335af_spi2_init(void)
{
    SYS_UnlockReg();
    
 	CLK_SetModuleClock(SPI2_MODULE, CLK_CLKSEL2_SPI2_S_PLL, 1);	//0-->1   
    
    CLK_EnableModuleClock(SPI2_MODULE);
    
    
    /* Set multi function pin for SPI2 */
    SYS->PB_L_MFP &= ~(SYS_PB_L_MFP_PB5_MFP_Msk | SYS_PB_L_MFP_PB6_MFP_Msk | SYS_PB_L_MFP_PB7_MFP_Msk);
	SYS->PB_L_MFP = (SYS_PB_L_MFP_PB5_MFP_SPI2_SCLK | SYS_PB_L_MFP_PB6_MFP_SPI2_MISO0 | SYS_PB_L_MFP_PB7_MFP_SPI2_MOSI0);
    
    SYS_LockReg();
	
	//for spi2 begin
	GPIO_SetMode(PA, BIT8, GPIO_PMD_OUTPUT);
	GPIO_SetMode(PB, BIT4, GPIO_PMD_OUTPUT);
	OLED_CS1 = 1;
	OLED_CS2 = 1;
    //for spi2 end
}

void Ecx335af_Init(void)
{
    uint32_t i = 0;
	for (i = 0; i < 130; i++)
	{
        Spi_WriteReg_1(i, s_EcxInit[i]);
	}
	for (i = 0; i < 130; i++)
	{
		Spi_WriteReg_2(i, s_EcxInit[i]);
	}		
}
void Ecx335af_Power_On(void)
{
    OLED_RESET = 1;
	#if 0
    delay_ms(200);
	OLED_RESET = 0;
	delay_ms(200);
	OLED_RESET = 1;
	#endif
    delay_ms(20);

	Ecx335af_Init();
	
	delay_ms(1);
	step_1();
	delay_ms(10);
	step_2();
	delay_ms(20);
	step_3();
	delay_ms(100);
	step_4();
	delay_ms(20);
	step_5();
	delay_ms(20);
	step_6();
	delay_ms(20);
	step_6_1();
	BrightHandler();//eason
}

void Ecx335af_Power_Off(void)
{
	ECX_PwrSv_1();
	ECX_PwrSv_2();
	OLED_RESET = 0;
	
}
void Ecx335af_Power_Saving(void)
{
	ECX_PwrSv_1();
	ECX_PwrSv_2();
}

void Ecx335af_Exit_Power_Saving(void)
{
	step_2();
	step_3();
}
void Read_Ecx335af_reg(void)
{
	uint32_t ret, i = 0;
	for(i = 0; i < 130; i++)
    {
        ret = Spi_ReadReg_1(i);
		delay_ms(20);
	#ifdef OLED_SPI_DEBUG
        printf("LCD 1  reg = %x, val = %x\n",i,ret);
	#endif
    }
    for(i = 0; i < 130; i++)
    {
        ret = Spi_ReadReg_2(i);
		delay_ms(20);
	#ifdef OLED_SPI_DEBUG
        printf("LCD 2  reg = %x, val = %x\n",i,ret);
	#endif
    }
}
void Change_Mode(void)
{
	//Ecx335af_Power_Off();
	
	CHANGE_MODE = ~(CHANGE_MODE);
#ifdef KEY_DEBUG
	printf("CHANGE_MODE level is %d \n",CHANGE_MODE);
#endif
	#if 0
	delay_ms(100);
	while(!PA1)
	{
		//printf("====444====PA1 = %d\n",PA1);
		//delay_ms(1);
	}
	delay_ms(50);
	Ecx335af_Power_On();
	//Read_Ecx335af_reg();
	#endif

}
