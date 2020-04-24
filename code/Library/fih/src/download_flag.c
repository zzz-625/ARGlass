#include <stdio.h>
#include "Nano100Series.h"
#include "download_flag.h"
#include "fih_arg.h"


void dl_flag_init(void)
{
	data_flash.dl_flags = 0;
	
	printf("[dl_flag_init] download flags = %d \n",data_flash.dl_flags);
}

void set_boot_flags(void)
{
	uint32_t   au32Config[2];

	SYS_UnlockReg();
	
	FMC_Open();
    if (FMC_ReadConfig(au32Config, 2) < 0)
    {
        printf("\nRead User Config failed!\n");
    }
	FMC_ENABLE_CFG_UPDATE();
	

    au32Config[0] &= 0xFFFFFF4F;
	
	printf("au32Config[0] = %x\n",au32Config[0]);
	

	if (FMC_WriteConfig(au32Config, 2) < 0)
	{
        printf("FMC_WriteConfig fail \n");
	}

	//Perform chip reset to make new User Config take effect
    SYS->IPRST_CTL1 = SYS_IPRST_CTL1_CHIP_RST_Msk;

    /* Disable FMC ISP function */
    FMC_Close();

    /* Lock protected registers */
    SYS_LockReg();
}

int get_dl_flag(void)
{
	int8_t dl_flag;
	SYS_UnlockReg();
	
	FMC_Open();
	
	dl_flag = FMC_Read(DATA_FLASH_VER_BASE+24);
	
	printf("[get_dl_flag] data_flash.dl_flags = %d , dl_flag = %d\n",data_flash.dl_flags,dl_flag);
	
	/* Disable FMC ISP function */
    FMC_Close();

    /* Lock protected registers */
    SYS_LockReg();
	
	return dl_flag;
}
void set_dl_flag(void)
{
	SYS_UnlockReg();
	
	FMC_Open();
	#if 0
	uint32_t    u32Addr;
	for (u32Addr = DATA_FLASH_DL_FLAG_BASE; u32Addr < DATA_FLASH_DL_FLAG_END; u32Addr += FMC_FLASH_PAGE_SIZE)
    {
        printf("set_dl_flag  Flash test address: 0x%x    \n", u32Addr);
        // Erase page
        FMC_Erase(u32Addr);
	}
	#endif
	printf("[set_dl_flag] data_flash.dl_flags = %d \n",data_flash.dl_flags);
	
	//NVIC_DisableIRQ(GPABC_IRQn);
	//NVIC_DisableIRQ(GPDEF_IRQn);
	//NVIC_DisableIRQ(USBD_IRQn);
	
	FMC_Write(DATA_FLASH_VER_BASE+24, data_flash.dl_flags);
	
	//NVIC_EnableIRQ(GPABC_IRQn);
	//NVIC_EnableIRQ(GPDEF_IRQn);
	//NVIC_EnableIRQ(USBD_IRQn);
	
	/* Disable FMC ISP function */
    FMC_Close();

    /* Lock protected registers */
    SYS_LockReg();
}