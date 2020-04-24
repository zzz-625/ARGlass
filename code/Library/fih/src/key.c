#include "Nano100Series.h"
#include "fih_arg.h"

void Mode_Change_Interrupt_Init(void)
{
    //Configure PE5 as Input mode pull-up and enable interrupt by low level trigger
    GPIO_SetMode(PE, BIT5, GPIO_PMD_INPUT);
    //GPIO_ENABLE_PULL_UP(PE, BIT5);
    GPIO_EnableInt(PE, 5, GPIO_INT_LOW);
    NVIC_EnableIRQ(GPDEF_IRQn);
}

void Backlight_Interrupt_Init(void)
{
	//config PC1 as interrupt for backlight down begin
    GPIO_SetMode(PC, BIT1, GPIO_PMD_INPUT);
    //GPIO_ENABLE_PULL_UP(PE, BIT5);
    GPIO_EnableInt(PC, 1, GPIO_INT_LOW);
    NVIC_EnableIRQ(GPABC_IRQn);
    
    //config PC0 as interrupt for backlight high begin
    GPIO_SetMode(PC, BIT0, GPIO_PMD_INPUT);
    //GPIO_ENABLE_PULL_UP(PE, BIT5);
    GPIO_EnableInt(PC, 0, GPIO_INT_LOW);
    NVIC_EnableIRQ(GPABC_IRQn);
}

void GPDEF_IRQHandler(void)
{
    uint32_t reg;
    /* To check if PE.5 interrupt occurred */
    if(GPIO_GET_INT_FLAG(PE, BIT5))
    {
        delay_ms(5);
        GPIO_CLR_INT_FLAG(PE, BIT5);
	#ifdef KEY_DEBUG
        printf("Change Mode INT occurred. \n");
	#endif
		Change_Mode();
        while(!PE5);
    }
    else
    {
        /* Un-expected interrupt. Just clear all PORTD, PORTE and PORTF interrupts */
        reg = PD->ISRC;
        PD->ISRC = reg;
        reg = PE->ISRC;
        PE->ISRC = reg;
        reg = PF->ISRC;
        PF->ISRC = reg;
        printf("Un-expected interrupts. \n");
    }
}
void GPABC_IRQHandler(void)
{
    uint32_t reg;
		if(GPIO_GET_INT_FLAG(PB, BIT12))
		{ 
			if(PB12 == 1)
			{
				Ecx335af_Power_Off();
				
				#ifdef PS_SENOSR_DDEUG
				printf("Interrupt Far\n");
				#endif
			}
			else if(PB12 == 0)
			{
				Ecx335af_Power_On();
				
				#ifdef PS_SENOSR_DDEUG
				printf("Interrupt Near\n");
				#endif
			}
		}
    /* To check if PB.5 interrupt occurred */
    if(GPIO_GET_INT_FLAG(PC, BIT0))
    {   
        delay_ms(5);
        GPIO_CLR_INT_FLAG(PC, BIT0);
	#ifdef KEY_DEBUG
        printf("brignt ++ INT occurred. \n");
	#endif
        Bright_Strong();
        while(!PC0);
    }
    else if(GPIO_GET_INT_FLAG(PC, BIT1))
    {
        delay_ms(5);
        GPIO_CLR_INT_FLAG(PC, BIT1);
	#ifdef KEY_DEBUG
        printf("brignt -- INT occurred. \n");
	#endif
        Bright_Weak();
        while(!PC1);
    }
    else
    {
        /* Un-expected interrupt. Just clear all PORTA, PORTB, PORTC interrupts */
        reg = PA->ISRC;
        PA->ISRC = reg;
        reg = PB->ISRC;
        PB->ISRC = reg;
        reg = PC->ISRC;
        PC->ISRC = reg;
        printf("Un-expected interrupts. \n");
    }
}

