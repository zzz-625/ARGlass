/**************************************************************************//**
 * @file     hid_mouse.c
 * @brief    NANO100 series USBD driver Sample file
 * @version  2.0.0
 * @date     22, Sep, 2014
 *
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

/*!<Includes */
#include <stdio.h>
#include <string.h>
#include "Nano100Series.h"
//#include "hid_transfer.h"
#include "fih_arg.h"

uint8_t volatile g_u8EP2Ready = 0;

void USBD_IRQHandler(void)
{
    uint32_t u32IntSts = USBD_GET_INT_FLAG();
    uint32_t u32State = USBD_GET_BUS_STATE();

//------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_FLDET)
    {
        // Floating detect
        USBD_CLR_INT_FLAG(USBD_INTSTS_FLDET);

        if (USBD_IS_ATTACHED())
        {
            /* USB Plug In */
            USBD_ENABLE_USB();
        }
        else
        {
            /* USB Un-plug */
            USBD_DISABLE_USB();
        }
    }

//------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_BUS)
    {
        /* Clear event flag */
        USBD_CLR_INT_FLAG(USBD_INTSTS_BUS);

        if (u32State & USBD_STATE_USBRST)
        {
            /* Bus reset */
            USBD_ENABLE_USB();
            USBD_SwReset();
        }
        if (u32State & USBD_STATE_SUSPEND)
        {
            /* Enable USB but disable PHY */
            USBD_DISABLE_PHY();
        }
        if (u32State & USBD_STATE_RESUME)
        {
            /* Enable USB and enable PHY */
            USBD_ENABLE_USB();
        }
    }

//------------------------------------------------------------------
    if(u32IntSts & USBD_INTSTS_WAKEUP)
    {
        /* Clear event flag */
        USBD_CLR_INT_FLAG(USBD_INTSTS_WAKEUP);
    }

    if (u32IntSts & USBD_INTSTS_USB)
    {
        // USB event
        if (u32IntSts & USBD_INTSTS_SETUP)
        {
            // Setup packet
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_SETUP);

            /* Clear the data IN/OUT ready flag of control end-points */
            USBD_STOP_TRANSACTION(EP0);
            USBD_STOP_TRANSACTION(EP1);

            USBD_ProcessSetupPacket();
        }

        // EP events
        if (u32IntSts & USBD_INTSTS_EP0)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP0);
            // control IN
            USBD_CtrlIn();
        }

        if (u32IntSts & USBD_INTSTS_EP1)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP1);

            // control OUT
            USBD_CtrlOut();
        }

        if (u32IntSts & USBD_INTSTS_EP2)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP2);
            // Interrupt IN
            EP2_Handler();
        }

        if (u32IntSts & USBD_INTSTS_EP3)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP3);
            // Interrupt OUT
            EP3_Handler();
        }

        if (u32IntSts & USBD_INTSTS_EP4)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP4);
        }

        if (u32IntSts & USBD_INTSTS_EP5)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP5);
        }

        if (u32IntSts & USBD_INTSTS_EP6)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP6);
        }

        if (u32IntSts & USBD_INTSTS_EP7)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP7);
        }
    }
}

unsigned int EP3_READY;
void EP2_Handler(void)  /* Interrupt IN handler */
{
		//printf("EP2_Handler\n");
    //HID_SetInReport();
}

void EP3_Handler(void)  /* Interrupt OUT handler */
{
    //uint8_t *ptr;
	
		//printf("EP3_Handler\n");
		EP3_READY = 1;
		Hid_Transfer_Data();
    /* Interrupt OUT */
    //ptr = (uint8_t *)(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP3));
    //HID_GetOutReport(ptr, USBD_GET_PAYLOAD_LEN(EP3));
    //USBD_SET_PAYLOAD_LEN(EP3, EP3_MAX_PKT_SIZE);
}


/*--------------------------------------------------------------------------*/
/**
  * @brief  USBD Endpoint Config.
  * @param  None.
  * @retval None.
  */
void HID_Init(void)
{
    /* Init setup packet buffer */
    /* Buffer range for setup packet -> [0 ~ 0x7] */
    USBD->BUFSEG = SETUP_BUF_BASE;

    /*****************************************************/
    /* EP0 ==> control IN endpoint, address 0 */
    USBD_CONFIG_EP(EP0, USBD_CFG_CSTALL | USBD_CFG_EPMODE_IN | 0);
    /* Buffer range for EP0 */
    USBD_SET_EP_BUF_ADDR(EP0, EP0_BUF_BASE);

    /* EP1 ==> control OUT endpoint, address 0 */
    USBD_CONFIG_EP(EP1, USBD_CFG_CSTALL | USBD_CFG_EPMODE_OUT | 0);
    /* Buffer range for EP1 */
    USBD_SET_EP_BUF_ADDR(EP1, EP1_BUF_BASE);

    /*****************************************************/
    /* EP2 ==> Interrupt IN endpoint, address 1 */
    USBD_CONFIG_EP(EP2, USBD_CFG_EPMODE_IN | INT_IN_EP_NUM);
    /* Buffer range for EP2 */
    USBD_SET_EP_BUF_ADDR(EP2, EP2_BUF_BASE);

    /* EP3 ==> Interrupt OUT endpoint, address 2 */
    USBD_CONFIG_EP(EP3, USBD_CFG_EPMODE_OUT | INT_OUT_EP_NUM);
    /* Buffer range for EP3 */
    USBD_SET_EP_BUF_ADDR(EP3, EP3_BUF_BASE);
    /* trigger to receive OUT data */
    USBD_SET_PAYLOAD_LEN(EP3, EP3_MAX_PKT_SIZE);

}

void HID_ClassRequest(void)
{
    uint8_t buf[8];
		int i = 0;

    USBD_GetSetupPacket(buf);

	for(i=0; i<8; i++)
	{
	#ifdef USB_HID_DEBUG
		printf("buf[i] = %x,", buf[i]);
	#endif
    }
#ifdef USB_HID_DEBUG
	printf("\n");
#endif
		
	if (buf[0] & 0x80)   /* request data transfer direction */
    {
	#ifdef USB_HID_DEBUG
		printf("Device to host, buf[1] = %x\n", buf[1]);
	#endif
        // Device to host
        switch (buf[1])
        {
        case GET_REPORT:
//             {
//                 break;
//             }
        case GET_IDLE:
//             {
//                 break;
//             }
        case GET_PROTOCOL:
//            {
//                break;
//            }
        default:
        {
            /* Setup error, stall the device */
            USBD_SetStall(0);
            break;
        }
        }
    }
    else
    {
	#ifdef USB_HID_DEBUG
		printf("Host to device, buf[1] = %x\n", buf[1]);
	#endif
        // Host to device
        switch (buf[1])
        {
        case SET_REPORT:
        {
            if (buf[3] == 3)
            {
                /* Request Type = Feature */
                USBD_SET_DATA1(EP1);
                USBD_SET_PAYLOAD_LEN(EP1, 0);
            }
            break;
        }
        case SET_IDLE:
        {
            /* Status stage */
            USBD_SET_DATA1(EP0);
            USBD_SET_PAYLOAD_LEN(EP0, 0);
            break;
        }
        case SET_PROTOCOL:
//             {
//                 break;
//             }
        default:
        {
            // Stall
            /* Setup error, stall the device */
            USBD_SetStall(0);
            break;
        }
        }
    }
}

/***************************************************************/
#define HID_CMD_SIGNATURE   0x43444948

/* HID Transfer Commands */
#define HID_CMD_NONE     0x00
#define HID_CMD_ERASE    0x71
#define HID_CMD_READ     0xD2
#define HID_CMD_WRITE    0xC3
#define HID_CMD_TEST     0xB4

#define PAGE_SIZE        2048
#define TEST_PAGES       4
#define SECTOR_SIZE      4096
#define START_SECTOR     0x10

typedef __packed struct
{
    uint8_t u8Cmd;
    uint8_t u8Size;
    uint32_t u32Arg1;
    uint32_t u32Arg2;
    uint32_t u32Signature;
    uint32_t u32Checksum;
} CMD_T;

CMD_T gCmd;

static uint8_t  g_u8PageBuff[PAGE_SIZE] = {0};    /* Page buffer to upload/download through HID report */
static uint32_t g_u32BytesInPageBuf = 0;          /* The bytes of data in g_u8PageBuff */
static uint8_t  g_u8TestPages[TEST_PAGES * PAGE_SIZE] = {0};    /* Test pages to upload/download through HID report */

int32_t HID_CmdEraseSectors(CMD_T *pCmd)
{
    uint32_t u32StartSector;
    uint32_t u32Sectors;

    u32StartSector = pCmd->u32Arg1 - START_SECTOR;
    u32Sectors = pCmd->u32Arg2;

    printf("Erase command - Sector: %d   Sector Cnt: %d\n", u32StartSector, u32Sectors);

    /* TODO: To erase the sector of storage */
    memset(g_u8TestPages + u32StartSector * SECTOR_SIZE, 0xFF, sizeof(uint8_t) * u32Sectors * SECTOR_SIZE);

    /* To note the command has been done */
    pCmd->u8Cmd = HID_CMD_NONE;

    return 0;
}


int32_t HID_CmdReadPages(CMD_T *pCmd)
{
    uint32_t u32StartPage;
    uint32_t u32Pages;
	uint32_t u32Pages_T;

    u32StartPage = pCmd->u32Arg1;
    u32Pages     = pCmd->u32Arg2;

	u32Pages_T   = u32Pages - 2;

	printf("Read command - Start page: %d    Pages Numbers: %d\n", u32StartPage, u32Pages_T);

	if(u32Pages_T)
    {
        /* Update data to page buffer to upload */
        /* TODO: We need to update the page data if got a page read command. (0xFF is used in this sample code) */
        memcpy(g_u8PageBuff, g_u8TestPages, sizeof(g_u8PageBuff));
        g_u32BytesInPageBuf = PAGE_SIZE;

        /* The signature word is used as page counter */
        pCmd->u32Signature = 1;

        /* Trigger HID IN */
        USBD_MemCopy((uint8_t *)(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP2)), (void *)g_u8PageBuff, EP2_MAX_PKT_SIZE);
        USBD_SET_PAYLOAD_LEN(EP2, EP2_MAX_PKT_SIZE);
        g_u32BytesInPageBuf -= EP2_MAX_PKT_SIZE;
    }

    return 0;
}


int32_t HID_CmdWritePages(CMD_T *pCmd)
{
    uint32_t u32StartPage;
    uint32_t u32Pages;

    u32StartPage = pCmd->u32Arg1;
    u32Pages     = pCmd->u32Arg2;

    printf("Write command - Start page: %d    Pages Numbers: %d\n", u32StartPage, u32Pages);
    g_u32BytesInPageBuf = 0;

    /* The signature is used to page counter */
    pCmd->u32Signature = 0;

    return 0;
}


int32_t gi32CmdTestCnt = 0;
int32_t HID_CmdTest(CMD_T *pCmd)
{
    int32_t i;
    uint8_t *pu8;

    pu8 = (uint8_t *)pCmd;
    printf("Get test command #%d (%d bytes)\n", gi32CmdTestCnt++, pCmd->u8Size);
    for(i=0; i<pCmd->u8Size; i++)
    {
        if((i&0xF) == 0)
        {
            printf("\n");
        }
        printf(" %02x", pu8[i]);
    }

    printf("\n");


    /* To note the command has been done */
    pCmd->u8Cmd = HID_CMD_NONE;

    return 0;
}


uint32_t CalCheckSum(uint8_t *buf, uint32_t size)
{
    uint32_t sum;
    int32_t i;

    i = 0;
    sum = 0;
    while(size--)
    {
        sum+=buf[i++];
    }

    return sum;

}


int32_t ProcessCommand(uint8_t *pu8Buffer, uint32_t u32BufferLen)
{
    uint32_t u32sum;

    USBD_MemCopy((uint8_t *)&gCmd, pu8Buffer, u32BufferLen);
		printf("ProcessCommand --- gCmd.u8Cmd = %x !\n",gCmd.u8Cmd);

    /* Check size */
    if((gCmd.u8Size > sizeof(gCmd)) || (gCmd.u8Size > u32BufferLen))
        return -1;

    /* Check signature */
    if(gCmd.u32Signature != HID_CMD_SIGNATURE)
        return -1;

    /* Calculate checksum & check it*/
    u32sum = CalCheckSum((uint8_t *)&gCmd, gCmd.u8Size);
    if(u32sum != gCmd.u32Checksum)
        return -1;

    switch(gCmd.u8Cmd)
    {
		case HID_CMD_ERASE:
    {
        HID_CmdEraseSectors(&gCmd);
        break;
    }
    case HID_CMD_READ:
    {
        HID_CmdReadPages(&gCmd);
        break;
    }
    case HID_CMD_WRITE:
    {
        HID_CmdWritePages(&gCmd);
        break;
    }
    case HID_CMD_TEST:
    {
        HID_CmdTest(&gCmd);
        break;
    }
    default:
		{
				printf("default!\n");
        return -1;
		}
    }
	
    return 0;
}


void HID_GetOutReport(uint8_t *pu8EpBuf, uint32_t u32Size)
{
    uint8_t  u8Cmd;
    uint32_t u32StartPage;
    uint32_t u32Pages;
    uint32_t u32PageCnt;

    /* Get command information */
    u8Cmd        = gCmd.u8Cmd;
    u32StartPage = gCmd.u32Arg1;
    u32Pages     = gCmd.u32Arg2;
    u32PageCnt   = gCmd.u32Signature; /* The signature word is used to count pages */


    /* Check if it is in the data phase of write command */
    if((u8Cmd == HID_CMD_WRITE) &&  (u32PageCnt < u32Pages))
    {
        /* Process the data phase of write command */

        /* Get data from HID OUT */
        USBD_MemCopy(&g_u8PageBuff[g_u32BytesInPageBuf], pu8EpBuf, EP3_MAX_PKT_SIZE);
        g_u32BytesInPageBuf += EP3_MAX_PKT_SIZE;

        /* The HOST must make sure the data is PAGE_SIZE alignment */
        if(g_u32BytesInPageBuf >= PAGE_SIZE)
        {
            printf("Writing page %d\n", u32StartPage + u32PageCnt);
            /* TODO: We should program received data to storage here */
            memcpy(g_u8TestPages + u32PageCnt * PAGE_SIZE, g_u8PageBuff, sizeof(g_u8PageBuff));
            u32PageCnt++;

            /* Write command complete! */
            if(u32PageCnt >= u32Pages)
            {
                u8Cmd = HID_CMD_NONE;

                printf("Write command complete.\n");
            }

            g_u32BytesInPageBuf = 0;

        }

        /* Update command status */
        gCmd.u8Cmd        = u8Cmd;
        gCmd.u32Signature = u32PageCnt;
    }
    else
    {
        /* Check and process the command packet */
        if(ProcessCommand(pu8EpBuf, u32Size))
        {
            printf("Unknown HID command!\n");
        }
    }
}

void HID_SetInReport(void)
{
    uint32_t u32StartPage;
    uint32_t u32TotalPages;
    uint32_t u32PageCnt;
    uint8_t *ptr;
    uint8_t u8Cmd;

    u8Cmd        = gCmd.u8Cmd;
    u32StartPage = gCmd.u32Arg1;
    u32TotalPages= gCmd.u32Arg2;
    u32PageCnt   = gCmd.u32Signature;

    /* Check if it is in data phase of read command */
    if(u8Cmd == HID_CMD_READ)
    {
        /* Process the data phase of read command */
        if((u32PageCnt >= u32TotalPages) && (g_u32BytesInPageBuf == 0))
        {
            /* The data transfer is complete. */
            u8Cmd = HID_CMD_NONE;
            printf("Read command complete!\n");
        }
        else
        {
            if(g_u32BytesInPageBuf == 0)
            {
                /* The previous page has sent out. Read new page to page buffer */
                /* TODO: We should update new page data here. (0xFF is used in this sample code) */
                printf("Reading page %d\n", u32StartPage + u32PageCnt);
                memcpy(g_u8PageBuff, g_u8TestPages + u32PageCnt * PAGE_SIZE, sizeof(g_u8PageBuff));

                g_u32BytesInPageBuf = PAGE_SIZE;

                /* Update the page counter */
                u32PageCnt++;
            }

            /* Prepare the data for next HID IN transfer */
            ptr = (uint8_t *)(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP2));
            USBD_MemCopy(ptr, (void *)&g_u8PageBuff[PAGE_SIZE - g_u32BytesInPageBuf], EP2_MAX_PKT_SIZE);
            USBD_SET_PAYLOAD_LEN(EP2, EP2_MAX_PKT_SIZE);
            g_u32BytesInPageBuf -= EP2_MAX_PKT_SIZE;
        }
    }

    gCmd.u8Cmd        = u8Cmd;
    gCmd.u32Signature = u32PageCnt;

}

/* HID Transfer Commands */
#define HID_CMD_IMU     0x01
#define HID_CMD_V     0x02
#define HID_CMD_PL      0x03
#define HID_CMD_DL      0x04

typedef __packed struct {
	uint8_t u8Command;
	uint8_t cmd_status;

	uint16_t u16Buffer_Gy_X;
	uint16_t u16Buffer_Gy_Y;
	uint16_t u16Buffer_Gy_Z;
	uint16_t u16Buffer_Ac_X;
	uint16_t u16Buffer_Ac_Y;
	uint16_t u16Buffer_Ac_Z;
	float s16Buffer_Ma_X;
	float s16Buffer_Ma_Y;
	float s16Buffer_Ma_Z;

	uint8_t Key_status;

	uint8_t u8BL;

	int8_t i8Cal_h1;
	int8_t i8Cal_v1;
	int8_t i8Cal_h2;
	int8_t i8Cal_v2;
	
	//uint8_t u8Buffer[63];
} HID_T;

HID_T hCmd;

typedef __packed struct {
	uint8_t u8Command_r;
	uint8_t cmd_status_r;
	uint8_t u8Buffer_r[62];
} HID_T_R;

HID_T_R hCmdR;

//int32_t HID_CmdImuData(HID_T *pCmd)
int32_t HID_CmdImuData(HID_T_R *pCmd_r,HID_T *pCmd)
{
	uint8_t i = 0;

	bmg160_gyro_data gy_xyz;	
	bma2x2_acc_data acc_xyz;
	bmm050_mag_data mag_xyz;

	Imu_Gyro_Raw(&gy_xyz);
	Imu_Acc_Raw(&acc_xyz);
	Imu_Mag_Raw(&mag_xyz);

	//memset(pCmd->u16Buffer, 0xFFFF, sizeof(pCmd->u16Buffer));

	pCmd->u16Buffer_Gy_X=gy_xyz.gyro_x;
	pCmd->u16Buffer_Gy_Y=gy_xyz.gyro_y;
	pCmd->u16Buffer_Gy_Z=gy_xyz.gyro_z;

	pCmd->u16Buffer_Ac_X=acc_xyz.acc_x;
	pCmd->u16Buffer_Ac_Y=acc_xyz.acc_y;
	pCmd->u16Buffer_Ac_Z=acc_xyz.acc_z;

	pCmd->s16Buffer_Ma_X=mag_xyz.mag_x;
	pCmd->s16Buffer_Ma_Y=mag_xyz.mag_y;
	pCmd->s16Buffer_Ma_Z=mag_xyz.mag_z;
	//printf("s16Buffer_Gy_X = %02x, s16Buffer_Ac_Y = %0xx, s16Buffer_Ma_Z = %02x\n",pCmd->s16Buffer_Gy_X,pCmd->s16Buffer_Ac_Y,pCmd->s16Buffer_Ma_Z);
				
	pCmd->u8Command = pCmd_r->u8Command_r;
	//2D.3D, Backlight, Calibration
	if (pCmd_r->cmd_status_r == 0x0)
	{
		pCmd->cmd_status = pCmd_r->cmd_status_r;
		pCmd->Key_status=CHANGE_MODE;
		pCmd->u8BL = g_CalDac_Reg;
					
		Get_Vcali_From_Data_Flash();
		pCmd->i8Cal_h1 = data_flash.h1;
		pCmd->i8Cal_v1 = data_flash.v1;
		pCmd->i8Cal_h2 = data_flash.h2;
		pCmd->i8Cal_v2 = data_flash.v2;
	}
	else if(pCmd_r->cmd_status_r == 0x1)
	{
		pCmd->cmd_status = pCmd_r->cmd_status_r;
		
		if(CHANGE_MODE != pCmd_r->u8Buffer_r[0])
		{
			Change_Mode();
		}		
			
		//Change_Mode();
		pCmd->Key_status=CHANGE_MODE;
		//printf(" 1 cmd_status=%x,Key_status= %x\n",pCmd->cmd_status,pCmd->Key_status);
	}
	else if(pCmd_r->cmd_status_r == 0x2)
	{
		pCmd->cmd_status = pCmd_r->cmd_status_r;
		//printf(" 2 cmd_status = %x\n",pCmd->cmd_status);
		g_CalDac_Reg =  pCmd_r->u8Buffer_r[0];
		BrightHandler();
	}
	else if(pCmd_r->cmd_status_r == 0x3)
	{
		pCmd->cmd_status = pCmd_r->cmd_status_r;
		data_flash.h1 = pCmd_r->u8Buffer_r[0];
		data_flash.v1 = pCmd_r->u8Buffer_r[1];
		data_flash.h2 = pCmd_r->u8Buffer_r[2];
		data_flash.v2 = pCmd_r->u8Buffer_r[3];
		//printf(" 3 cmd_status=%x,u8Buffer_r[0]=%x,u8Buffer_r[3]=%x\n",pCmd->cmd_status,pCmd_r->u8Buffer_r[0],v2 = pCmd_r->u8Buffer_r[3]);
		Ecx335af_Calibration();
	}

	
	//pCmd->u8Command = HID_CMD_NONE;
	
	return 0;
}

void Hid_Transfer_Data(void)
{
	uint8_t *ptrOut, *ptrIn;
	char s1[50],s2[20];
	uint8_t i=0,j=0;
	int8_t flag = 0;

	if(EP3_READY==1)
	{
		EP3_READY=0;
                            
		/* Interrupt OUT */
		ptrOut = (uint8_t *)(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP3));
    		ptrIn = (uint8_t *)(USBD_BUF_BASE + USBD_GET_EP_BUF_ADDR(EP2));
     
		USBD_MemCopy((uint8_t *)&hCmdR, ptrOut, EP3_MAX_PKT_SIZE);
			
		if(hCmdR.u8Command_r == HID_CMD_IMU)
		{
			HID_CmdImuData(&hCmdR,&hCmd);
			USBD_MemCopy(ptrIn, (void *)&hCmd, EP3_MAX_PKT_SIZE);
    			USBD_SET_PAYLOAD_LEN(EP3, EP3_MAX_PKT_SIZE);                        
			USBD_SET_PAYLOAD_LEN(EP2, EP2_MAX_PKT_SIZE);
			hCmd.u8Command = HID_CMD_NONE;
    		}

		if(hCmdR.u8Command_r == HID_CMD_V)
		{
			memcpy(s1,data_flash.mcu_version,sizeof(char)*10);
			memcpy(s2,data_flash.lt7211b_fwversion,sizeof(char)*10);

			while(s1[i]!='\0')
			{
				i++;
			}

			while(s2[j]!='\0')
			{
				s1[i]=s2[j];
				i++;
				j++;
			}
			s1[i]='\0';
			//printf("\n%s\n",s1);
			
			USBD_MemCopy(ptrIn, (void *)&s1, EP3_MAX_PKT_SIZE);
			USBD_SET_PAYLOAD_LEN(EP3, EP3_MAX_PKT_SIZE);                        
			USBD_SET_PAYLOAD_LEN(EP2, EP2_MAX_PKT_SIZE);
			hCmd.u8Command = HID_CMD_NONE;
		}
		
		else if(hCmdR.u8Command_r == HID_CMD_DL)
		{
			data_flash.dl_flags = hCmdR.cmd_status_r;
			
			printf("hCmdR.cmd_status_r = %d \n",hCmdR.cmd_status_r);
			printf("data_flash.dl_flags = %d\n",data_flash.dl_flags);
			
			Set_Mcu_Version();
			
			delay_ms(800);
			
			Get_Mcu_Version();
			
			if (1 == dl_flag)
			{
				set_boot_flags();	
			}
			
			
			USBD_SET_PAYLOAD_LEN(EP3, EP3_MAX_PKT_SIZE);                        
			USBD_SET_PAYLOAD_LEN(EP2, EP2_MAX_PKT_SIZE);
			hCmd.u8Command = HID_CMD_NONE;			
	
		}

   	}
}
