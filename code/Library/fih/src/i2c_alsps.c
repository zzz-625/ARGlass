
#include "i2c_alsps.h"
#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"

enum event_type {
    far,
    near,
};
#define BL_LED_OFF	0
#define BL_LED_ON		1

int current = BL_LED_OFF;

int ALP_WriteI2C_Byte(uint8_t RegAddr, uint8_t Data)
{
	return LP_WriteI2C_Byte((SY3096PS_I2C_ADDRESS<<1),RegAddr,Data);
}

uint8_t ALP_ReadI2C_Byte(uint8_t RegAddr)
{
	 return LP_ReadI2C_Byte((SY3096PS_I2C_ADDRESS<<1), RegAddr);
}

void sy3096ps_set_threshold(uint8_t ht, uint8_t lt)
{
    ALP_WriteI2C_Byte(REG_PS_TH, ht);
    ALP_WriteI2C_Byte(REG_PS_TL, lt);
}

/*----------i2c_alsps_init----------*/

void i2c_alsps_init()
{
	ALP_WriteI2C_Byte(SOFTWARE_RESET,0x00);
	
	ALP_WriteI2C_Byte(REG_CON1,INTR_TYPE|WAIT_TIME|DRIVE_CURR|PRST);
	
	if(INTR_TYPE == PXS_PITYPE_WINDOW)
	{
		sy3096ps_set_threshold(NEAR_THRES, 0);
	}
	else if (INTR_TYPE == PXS_PITYPE_EVENT)
	{
		sy3096ps_set_threshold(NEAR_THRES, FAR_THRES);
	}
	
}

/*-------Interrupt_Init---------*/

void PS_Interrupt_Init(void)
{
    //Configure PB12 as Input mode pull-up and enable interrupt by low level trigger
    GPIO_SetMode(PB, BIT12, GPIO_PMD_INPUT);
    //GPIO_ENABLE_PULL_UP(PB, BIT12);
    GPIO_EnableInt(PB, 12, GPIO_INT_BOTH_EDGE);
    NVIC_EnableIRQ(GPABC_IRQn);
}
/*----enable-----*/

void sy3096ps_enable(int enable)
{
	if(1 == enable)
	{
		if (INTR_TYPE == PXS_PITYPE_WINDOW)
		{
			 sy3096ps_set_threshold(NEAR_THRES, 0);
		}
    else if (INTR_TYPE == PXS_PITYPE_EVENT)
		{
       sy3096ps_set_threshold(NEAR_THRES, FAR_THRES);
		}
		ALP_WriteI2C_Byte(REG_CON0, AP_EN_PS);
	}
	else
        ALP_WriteI2C_Byte(REG_CON0, 0x00);
}

/*----sy3096ps_read_ps-----*/

uint8_t sy3096ps_read_ps(void)
{
	 return  ALP_ReadI2C_Byte(REG_PS_DATA);     
}	

/*----sy3096ps_clear_interrupt-----*/

void sy3096ps_clear_interrupt(void)
{
    ALP_WriteI2C_Byte(CLEAR_PXS_FLAG, 0x00);
}

/*----sy3096ps_process_data-----*/

int sy3096ps_process_data(void)
{
    int ret = -1;

    uint8_t ps = sy3096ps_read_ps();

    if (ps > NEAR_THRES)
		{
        if (INTR_TYPE == PXS_PITYPE_WINDOW)
				{
            sy3096ps_set_threshold(255, FAR_THRES);
            sy3096ps_clear_interrupt();
        }

        ret = near;
    }
    else if (ps < FAR_THRES)
		{
        if (INTR_TYPE == PXS_PITYPE_WINDOW)
				{
            sy3096ps_set_threshold(NEAR_THRES, 0);
            sy3096ps_clear_interrupt();
        }

        ret = far;
    }

    return ret;
}

int Check_VendorID(void)
{
	uint8_t ID_data;

  ID_data = ALP_ReadI2C_Byte(0x00);
	
	#ifdef PS_SENOSR_DDEUG
  printf("check ps ID_data = %x\n",ID_data);
	#endif
	
	return (ID_data == 0x27);
}

void AlspsPro(void)
{
	int test= -1;
	
	#ifdef ALS_SENSOR_OPEN
	
	if(Check_ALS_ID())
  #endif
	{
		#ifdef PS_SENSOR_OPEN
		
		if(Check_VendorID())
		#endif
		{
			#ifdef PS_SENSOR_OPEN
			
			sy3096ps_process_data();
			sy3096ps_enable(1);
			#endif
			
			#ifdef ALS_SENSOR_OPEN
				
			sy3079as_enable(1);	
			#endif
			
			
			 #ifdef ALS_SENSOR_OPEN
				
					sy3079as_process_data();
				
				 #endif
			
		 }
	 }
}











