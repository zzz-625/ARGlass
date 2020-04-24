
#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"

/**********write************/
int ALS_WriteI2C_Byte(uint8_t RegAddr, uint8_t Data)
{
	return LP_WriteI2C_Byte((SY3079AS_I2C_ADDRESS<<1),RegAddr,Data);
}

/**********read************/
uint8_t ALS_ReadI2C_Byte(uint8_t RegAddr)
{
	 return LP_ReadI2C_Byte((SY3079AS_I2C_ADDRESS<<1), RegAddr);
}

/**********write num************/
int ALS_WriteI2C_ByteN(uint8_t RegAddr, uint8_t *P_Data,uint16_t N)
{
	return LP_WriteI2C_ByteN((SY3079AS_I2C_ADDRESS<<1),  RegAddr,  P_Data,  N);
}

/**********read num************/
int ALS_ReadI2C_ByteN(uint8_t RegAddr, uint8_t *p_data, uint16_t N)
{
	 LP_ReadI2C_ByteN((SY3079AS_I2C_ADDRESS<<1), RegAddr, p_data, N);
}

/**********read sensor data************/
uint16_t sy3096ps_read_als(void)
{
		uint16_t als = 0;
		ALS_ReadI2C_ByteN(REG_ALS_DATA_L,(uint8_t*)&als,2);
	
	  #ifdef ALS_SENOSR_DDEUG
    printf("als data = %d\n",als); 
#endif	
		return 	als;
}	

/********ALS_init***********/
int Check_ALS_ID(void)
{
	uint8_t Als_ID;

  Als_ID = ALS_ReadI2C_Byte(0x00);

  #ifdef ALS_SENOSR_DDEUG	
  printf("ID_data = %x\n",Als_ID);
	#endif
	
	return (Als_ID == 0x21);
}

/****************set threshold*************/
void sy3079as_set_threshold(uint16_t ht, uint16_t lt)
{
    ALS_WriteI2C_ByteN(REG_INT_TL_L, (uint8_t*)&lt, 2);
    ALS_WriteI2C_ByteN(REG_INT_TH_L, (uint8_t*)&ht, 2);
}

/****************enable*************/
void sy3079as_enable(int enable)
{
    if(1 == enable){
        sy3079as_set_threshold(ALS_TH, ALS_TL);
        ALS_WriteI2C_Byte(REG_ALs_CON2, ALS_RANGE);
        ALS_WriteI2C_Byte(REG_ALs_CON1, ALS_EN | ALS_PRST);
    }
    else
        ALS_WriteI2C_Byte(REG_ALs_CON1, 0x00);
}

/****************clear_interrupt*************/
void sy3079as_clear_interrupt(void)
{
    uint8_t ret = 0;
	
    ALS_WriteI2C_Byte(REG_ALs_CON1, ret);//eason
}

/****************process_data*************/
uint32_t sy3079as_process_data(void)
{
    uint16_t als = sy3096ps_read_als();
    uint32_t lux;
    lux = (uint32_t)als;
    lux *= CAL_LUX_TARGET;
    lux /= cali_adc;
	
	  #ifdef ALS_SENOSR_DDEUG
	  printf("lux %d\n",lux);
	  #endif
    return lux;
}

void sy3079_u32_swap(uint32_t *x, uint32_t *y)
{
    uint32_t temp = *x;
    *x = *y;
    *y = temp;
}

void sy3079_bubble_sort_u32(uint32_t* array, int arysize)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < arysize; i++)
        for (j = i+1; j < arysize; j++)
            if (array[i] > array[j])
                sy3079_u32_swap(array + i, array + j);
}

uint32_t sy3079as_als_calibration(void)
{
    int i = 0;
	  int status = -1;
    uint8_t cfg1 = 0;
    int arysize = 10;
    uint32_t als_data[arysize], sum_of_data = 0;

    cfg1 = ALS_ReadI2C_Byte(REG_ALs_CON1);//eason

    sum_of_data = 0;
    /* ALS On */
    ALS_WriteI2C_Byte(REG_ALs_CON1, ALS_EN | ALS_PRST);
    delay_ms(250);

    for (i=0; i < arysize; i++) {
        uint16_t als_adc = 0;
        status = ALS_ReadI2C_ByteN(REG_ALS_DATA_L, (uint8_t*)&als_adc, 2);
        als_data[i] = (uint32_t)als_adc;
        if (ALS_RANGE < ALS_RANGE_400MS_0)
            delay_ms(200);
        else
            delay_ms(400);
    }

    /* als adc sorting */
    sy3079_bubble_sort_u32(als_data, arysize);

    /* als data averaging */
    for (i = 3; i < 8; i++)
        sum_of_data += als_data[i];

    cali_adc = sum_of_data/(arysize-5);

    /* Restore CFG1 data */
    ALS_WriteI2C_Byte(REG_ALs_CON1, cfg1);
    
    return cali_adc;
}

void ALs_Pro(void)
{
	if(Check_ALS_ID())
	{
	  sy3079as_enable(1);
	   while(1)
		 {
				delay_ms(200);
			 
				sy3079as_process_data();
			 
		 }
		 sy3079as_enable(0);
	 }
}







