#ifndef _I2C_ALSPS_H_
#define _I2C_ALSPS_H_

#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"


#define ALSPS_SENSOR_OPEN
//#define ALS_SENSOR_OPEN
#define PS_SENSOR_OPEN


#define SY3096PS_I2C_ADDRESS    0x1E //7 bit Address
#define SY3096PS_VENDOR_ID      0x27
/* REGISTER ADDRESS */
#define REG_ID                  0x00 // Product ID: 0x27
#define REG_CON0                0x01
#define REG_CON1                0x02
#define REG_PS_TL               0x03 // PS Threshold Low
#define REG_PS_TH               0x04 // PS Threshold High
#define REG_PS_DATA             0x05 // PS DATA
#define REG_INT_FLAG            0x08 // INT FLAG
#define SY3096AS_MAX_REG        9
/* Reg01 Parameter */
#define AP_EN_PS                0x40

/* Reg02 Parameter */
/*PXS Interrupt Type*/
#define PXS_PITYPE_WINDOW       0x00
#define PXS_PITYPE_EVENT        0x80

/*PXS Waiting time*/
#define PXS_WAIT_6_25ms         0x00
#define PXS_WAIT_12_5ms         0x10
#define PXS_WAIT_25ms           0x20
#define PXS_WAIT_50ms           0x30

/*PXS Current Setting*/
#define PXS_IR_DRV_10mA         0x00
#define PXS_IR_DRV_15mA         0x08

/*PXS Interrupt Persistence*/
/*    000, interrupt is disabled
    001, set PXS_FLAG if 1 reading trips the threshold value
    010, set PXS_FLAG if 2 consecutive readings trip the threshold value
    011, set PXS_FLAG if 4 consecutive readings trip the threshold value
    100, set PXS_FLAG if 8 consecutive readings trip the threshold value
    101, set PXS_FLAG if 16 consecutive readings trip the threshold value
    110, set PXS_FLAG if 32 consecutive readings the threshold value
    111, every proximity cycle generates an interrupt */
#define PXS_DISABLE_INTR        0x00
#define PXS_PRST_1              0x01
#define PXS_PRST_2              0x02
#define PXS_PRST_4              0x03
#define PXS_PRST_8              0x04
#define PXS_PRST_16             0x05
#define PXS_PRST_32             0x06
#define PXS_PRST_EVERY_CYCLE    0x07

/* Special Function */
#define CLEAR_PXS_FLAG          0x21
#define SOFTWARE_RESET          0x22

/* SENSOR SETTING */
#define DRIVE_CURR              PXS_IR_DRV_10mA
#define INTR_TYPE               PXS_PITYPE_EVENT //Edge trigger for Event type interrupt.
#define WAIT_TIME               PXS_WAIT_12_5ms
#define PRST                    PXS_PRST_16
#define NEAR_THRES              100
#define FAR_THRES               50


extern uint8_t ALP_ReadI2C_Byte(uint8_t RegAddr);
extern int ALP_WriteI2C_Byte(uint8_t RegAddr, uint8_t Data);
extern void i2c_alsps_init();
extern void sy3096ps_enable(int enable);
extern uint8_t sy3096ps_read_ps(void);
extern void sy3096ps_clear_interrupt(void);
extern void AlspsPro(void);
extern void PS_Interrupt_Init(void);

#endif
