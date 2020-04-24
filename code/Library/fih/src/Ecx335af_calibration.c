#include <stdio.h>
#include "stdint.h"
#include "Nano100Series.h"
#include "fih_arg.h"



void Set_Vcali_To_Data_Flash(void)
{
	SYS_UnlockReg();

    /* Enable FMC ISP function */
    FMC_Open();
	
	uint32_t    u32Addr;
	for (u32Addr = DATA_FLASH_CALI_BASE; u32Addr < DATA_FLASH_CALI_END; u32Addr += FMC_FLASH_PAGE_SIZE)
    {
	#ifdef OLED_CALI_DEBUG
        printf("Set_Vcali_To_Data_Flash Flash test address: 0x%x    \n", u32Addr);
	#endif

        // Erase page
        FMC_Erase(u32Addr);
	}
	
	data_flash.cali_flag = FMC_Read(DATA_FLASH_CALI_BASE);
	
	if (1 !=data_flash.cali_flag)
	{
		data_flash.cali_flag = 1;
		FMC_Write(DATA_FLASH_CALI_BASE, data_flash.cali_flag);
	}
	
	FMC_Write(DATA_FLASH_CALI_BASE + 4, data_flash.h1);
	FMC_Write(DATA_FLASH_CALI_BASE + 8, data_flash.v1);
	FMC_Write(DATA_FLASH_CALI_BASE + 12, data_flash.h2);
	FMC_Write(DATA_FLASH_CALI_BASE + 16, data_flash.v2);
	
#ifdef OLED_CALI_DEBUG
		printf("[set] cali_flag = %d, left[%d : %d],right[%d : %d]\n", \
			data_flash.cali_flag, data_flash.h1, data_flash.v1, data_flash.h2, data_flash.v2);
#endif
	
lexit:

    /* Disable FMC ISP function */
    FMC_Close();

    /* Lock protected registers */
    SYS_LockReg();
#ifdef OLED_CALI_DEBUG
    printf("\Set_Vcali_To_Data_Flash Completed.\n");
#endif
}


void Get_Vcali_From_Data_Flash(void)
{
	SYS_UnlockReg();

    /* Enable FMC ISP function */
    FMC_Open();
	
	data_flash.cali_flag = FMC_Read(DATA_FLASH_CALI_BASE);
	if (1 == data_flash.cali_flag)
	{
		data_flash.h1 = FMC_Read(DATA_FLASH_CALI_BASE+4);
		data_flash.v1 = FMC_Read(DATA_FLASH_CALI_BASE+8);
		data_flash.h2 = FMC_Read(DATA_FLASH_CALI_BASE+12);
		data_flash.v2 = FMC_Read(DATA_FLASH_CALI_BASE+16);
	}
	else
	{
		data_flash.h1 = 0;
		data_flash.v1 = 0;
		data_flash.h2 = 0;
		data_flash.v2 = 0;
	}
	
#ifdef OLED_CALI_DEBUG
		printf("[get] cali_flag = %d, left[%d : %d],right[%d : %d]\n", \
			data_flash.cali_flag, data_flash.h1, data_flash.v1, data_flash.h2, data_flash.v2);
#endif
		
lexit:

    /* Disable FMC ISP function */
    FMC_Close();

    /* Lock protected registers */
    SYS_LockReg();
#ifdef OLED_CALI_DEBUG
    printf("\nGet_Vcali_From_Data_Flash Completed.\n");
#endif
}

void Horizontal_orbit_adjustment(int8_t h1, int8_t h2)
{
	uint8_t bRead = 0;

	bRead = Spi_ReadReg_1(0x02);
	bRead |= (h1 &0x1f);
	
#ifdef OLED_CALI_DEBUG
	printf("h1 = %d, bRead = 0x%x\n",h1,bRead);
#endif
	Spi_WriteReg_1(0x02, bRead);
	
	delay_ms(5);
	
	bRead = Spi_ReadReg_2(0x02);
	bRead |= (h2 &0x1f);
	
#ifdef OLED_CALI_DEBUG
	printf("h2 = %d, bRead = 0x%x\n",h2,bRead);
#endif
	Spi_WriteReg_2(0x02, bRead);
}

void Vertical_orbit_adjustment(int8_t v1, int8_t v2)
{
	uint8_t bRead = 0;

	bRead = Spi_ReadReg_1(0x03);
	bRead |= (v1 &0x1f);
	
#ifdef OLED_CALI_DEBUG
	printf("v1 = %d, bRead = 0x%x\n",v1,bRead);
#endif
	Spi_WriteReg_1(0x03, bRead);
	
	delay_ms(5);
	
	bRead = Spi_ReadReg_2(0x03);
	bRead |= (v2 &0x1f);
	
#ifdef OLED_CALI_DEBUG
	printf("v2 = %d, bRead = 0x%x\n",v2,bRead);
#endif
	Spi_WriteReg_2(0x03, bRead);
}

void Set_Value_To_Ecx335af(void)
{
	Horizontal_orbit_adjustment(data_flash.h1, data_flash.h2);
	Vertical_orbit_adjustment(data_flash.v1, data_flash.v2);
}

void Ecx335af_Calibration(void)
{
	Set_Vcali_To_Data_Flash();
	Set_Value_To_Ecx335af();
}

void Ecx335af_Calibration_test(void)
{
	for (int i = -15; i < 16; i++)
	{
		data_flash.h1=data_flash.h2=data_flash.v1=data_flash.v2=i;
		Ecx335af_Calibration();
		Get_Vcali_From_Data_Flash();
	#ifdef OLED_CALI_DEBUG
		printf("[main] cali_flag = %d, left[%d : %d],right[%d : %d]\n", \
			data_flash.cali_flag, data_flash.h1, data_flash.v1, data_flash.h2, data_flash.v2);
	#endif
	}
}
