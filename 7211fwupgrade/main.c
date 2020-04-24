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

	//lt7211 iic
    GPIO_SetMode(PA, BIT4, GPIO_PMD_OPEN_DRAIN);
    GPIO_SetMode(PA, BIT5, GPIO_PMD_OPEN_DRAIN);
	/*set PB10 as GPIO Open-Dain output*/
	GPIO_SetMode(PB, BIT10, GPIO_PMD_OPEN_DRAIN);

	/* set PA9 as gpio output low*/
	GPIO_SetMode(PA, BIT9, GPIO_PMD_OUTPUT);
}



/* Main */
int main(void)
{
    uint32_t nError = 0;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();

    /* Init UART to 115200-8n1 for print message */
    UART_Open(UART0, 115200);
	
		
    printf("\n+------------------------------------------------------------------------+\n");
    printf("|                       FIH ARGlass version 1.0                          |\n");
    printf("+------------------------------------------------------------------------+\n");
	

	
    Ecx335af_spi2_init();
    
#ifdef BIT_16_TRANSFER
    SPI_Open(SPI_OLED_PORT, SPI_MASTER, SPI_MODE_3, 16, 800000);
#else
	SPI_Open(SPI_OLED_PORT, SPI_MASTER, SPI_MODE_3, 8, 800000);
#endif
    SPI_SET_LSB_FIRST(SPI_OLED_PORT);
	
    //printf("\n+------------------------------------------------------------------------+\n");
    //printf("|                       FIH ARGlass version 1.0                           |\n");
    //printf("+------------------------------------------------------------------------+\n");

	GPIO_Init();

	Ecx335af_Power_On();
    #if 1
    Read_Ecx335af_reg();
    #endif

	
    printf("[OK]\n");


	LT7211_Firmware_Upgrade();

	
    if(nError == 0)
        printf("[OK]\n");
    else
        printf("[FAIL]\n");

    while(1);
}


/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/


