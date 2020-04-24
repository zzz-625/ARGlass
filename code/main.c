/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 18/12/7 5:31p $
 * @brief    Access ARGlass version 1.0 .
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"

//#define  BIT_16_TRANSFER

bmm050_t bmm050;

void delay_ms(int ms)
{
	int i = 0;
	for (i = 0;i<ms; i++)
		CLK_SysTickDelay(1000);
}

void SYS_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable external 12MHz HXT, 32KHz LXT and HIRC */
	CLK_EnableXtalRC(CLK_PWRCTL_HIRC_EN_Msk);
	
    /* Waiting for clock ready */
	CLK_WaitClockReady(CLK_CLKSTATUS_HIRC_STB_Msk);

	CLK_EnableXtalRC(CLK_PWRCTL_LIRC_EN_Msk);
	CLK_WaitClockReady( CLK_CLKSTATUS_LIRC_STB_Msk);
    /*  Set HCLK frequency 42MHz */
    CLK_SetCoreClock(42000000);

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HIRC, CLK_UART_CLK_DIVIDER(1));

    /* Enable IP clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Select IP clock source */
    CLK_SetModuleClock(USBD_MODULE, 0, CLK_USB_CLK_DIVIDER(2));
    /* Enable IP clock */
    CLK_EnableModuleClock(USBD_MODULE);
    
    CLK_SetModuleClock(WDT_MODULE, 0, 0);
	CLK_EnableModuleClock(WDT_MODULE);
	
    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init Uart I/O Multi-function                                                                              */
    /*---------------------------------------------------------------------------------------------------------*/
    SYS->PA_H_MFP &= ~(SYS_PA_H_MFP_PA14_MFP_Msk | SYS_PA_H_MFP_PA15_MFP_Msk);
    SYS->PA_H_MFP = (SYS_PA_H_MFP_PA14_MFP_UART0_RX | SYS_PA_H_MFP_PA15_MFP_UART0_TX);

    /* Lock protected registers */
    SYS_LockReg();
}

void GPIO_Init(void)
{
	GPIO_SetMode(PB, BIT15, GPIO_PMD_OUTPUT);
	PB15 = 1;
	
	//set vsync
	GPIO_SetMode(PA, BIT1, GPIO_PMD_INPUT);
	
	//lt7211 iic
    GPIO_SetMode(PA, BIT4, GPIO_PMD_OPEN_DRAIN);
    GPIO_SetMode(PA, BIT5, GPIO_PMD_OPEN_DRAIN);
	
	//l-p sensor iic
	GPIO_SetMode(PA, BIT10, GPIO_PMD_OPEN_DRAIN);
    GPIO_SetMode(PA, BIT11, GPIO_PMD_OPEN_DRAIN);
	
	/*set PB10 as GPIO Open-Dain output*/
	GPIO_SetMode(PB, BIT10, GPIO_PMD_OPEN_DRAIN);
	
	/*set PC2 as GPIO Push-Pull Output*/
	GPIO_SetMode(PA, BIT6, GPIO_PMD_OUTPUT);
	PA6 = 1;
    
	/* set PA9 as gpio output low*/
	GPIO_SetMode(PA, BIT9, GPIO_PMD_OUTPUT);
}


void USB_Init(void)
{
	uint32_t i;
	uint8_t *ptr;
	uint8_t *ptr1;
    //config usb begin
    USBD_Open(&gsInfo, HID_ClassRequest, NULL);

    /* Endpoint configuration */
    HID_Init();
    NVIC_EnableIRQ(USBD_IRQn);
    USBD_Start();
    //config usb end
}

void Interrupt_Init()
{
	Backlight_Interrupt_Init();
	Mode_Change_Interrupt_Init();
	
	PS_Interrupt_Init();
}

void WDT_IRQHandler(void)
{
	SYS_UnlockReg();
	// WDT timeout flag set
    if(WDT_GET_TIMEOUT_INT_FLAG())
    {
        // Reset WDT and clear time out flag
        WDT_CLEAR_TIMEOUT_INT_FLAG();
        printf("Reset WDT counter\n");
		WDT_RESET_COUNTER();
	}
	SYS_LockReg();
}

/* Main */
int main(void)
{
    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART to 115200-8n1 for print message */
    UART_Open(UART0, 115200);
	
		
    printf("\n+------------------------------------------------------------------------+\n");
    printf("|                       FIH ARGlass version 1.0                          |\n");
    printf("+------------------------------------------------------------------------+\n");
	

	
	USB_Init();
	
    Ecx335af_spi2_init();
    
#ifdef BIT_16_TRANSFER
    SPI_Open(SPI_OLED_PORT, SPI_MASTER, SPI_MODE_3, 16, 800000);
#else
	SPI_Open(SPI_OLED_PORT, SPI_MASTER, SPI_MODE_3, 8, 800000);
#endif
    SPI_SET_LSB_FIRST(SPI_OLED_PORT);

	GPIO_Init();	

    Imu_Spi1_Init();

	init_imu_chip(&bmm050);
	//read_imu_chip_id();
    
	Hid_Transfer_Data();
		
    Interrupt_Init();
	i2c_alsps_init();
	
    printf("[OK]\n");
	
	#if 0
	while(!PA1)
	{
		//printf("====111====PA1 = %d\n",PA1);
		//delay_ms(1);
	}
	delay_ms(800);
	#endif
	Ecx335af_Power_On();
	
	#if 0
    Read_Ecx335af_reg();
    #endif
		
	//BrightHandler();
	
	mcu_version_init();
	
	/* ecx335af calibration when power on begin*/
	Get_Vcali_From_Data_Flash();
	Set_Value_To_Ecx335af();
	/*ecx335af calibration when power on end*/
	
#ifdef ALSPS_SENSOR_OPEN
	AlspsPro();
#endif	
	
	
	data_flash.dl_flags = get_dl_flag();
	printf("dl_flag = %d \n",data_flash.dl_flags);
	if ((1 != data_flash.dl_flags)&&(0 != data_flash.dl_flags))
	{
		dl_flag_init();
		set_dl_flag();
	}
	else if (1 == data_flash.dl_flags)
	{
		set_boot_flags();
	}
	
	SYS_UnlockReg();
	// WDT timeout every 2^14 WDT clock, enable system reset, ensble wake up system
    WDT_Open(WDT_TIMEOUT_2POW16, 0, TRUE, FALSE);
	
	WDT_EnableInt();
    NVIC_EnableIRQ(WDT_IRQn);
	SYS_LockReg();
	
	while(1)
    {
		SYS_UnlockReg();
		WDT_RESET_COUNTER();
		SYS_LockReg();
    }
}


/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/


