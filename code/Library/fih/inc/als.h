#ifndef _ALS_H_
#define _ALS_H_

#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"

#define SY3079AS_I2C_ADDRESS    0x44 //7 bit Address
#define SY3079AS_VENDOR_ID      0x21
/* REGISTER ADDRESS */
#define REG_ALs_ID                  0x00 // Product ID: 0x21
#define REG_ALs_CON1                0x01
#define REG_ALs_CON2                0x02
#define REG_ALS_DATA_L          0x03 // ALS Data LSM
#define REG_ALS_DATA_H          0x04 // ALS Data MSB
#define REG_INT_TL_L            0x05 // 
#define REG_INT_TL_H            0x06 // 
#define REG_INT_TH_L            0x07 // 
#define REG_INT_TH_H            0x08 // 
#define SY3079AS_MAX_REG        9

/*Config1@ 0x01*/
#define ALS_EN                  0x80

#define ALS_PRST_1              0x00
#define ALS_PRST_4              0x01
#define ALS_PRST_8              0x02
#define ALS_PRST_16             0x03

/*Config2@ 0x02*/
#define ALS_RANGE_200MS_0       0x00
#define ALS_RANGE_200MS_1       0x01
#define ALS_RANGE_200MS_2       0x02
#define ALS_RANGE_400MS_0       0x04
#define ALS_RANGE_400MS_1       0x05
#define ALS_RANGE_400MS_2       0x06

#define CLEAR_RANGE_200MS       0x03
#define CLEAR_RANGE_400MS       0x07

/* SENSOR SETTING */
#define ALS_RANGE               ALS_RANGE_200MS_0
#define ALS_PRST                ALS_PRST_1
#define ALS_TL                  0
#define ALS_TH                  65535
//#define ALS_USE_INTERRUPT

/* ALS Calibration */
#define CAL_LUX_TARGET          400
static uint32_t cali_adc = 815;

extern void ALs_Pro(void);
extern void sy3079as_enable(int enable);
extern int Check_ALS_ID(void);
extern uint16_t sy3096ps_read_als(void);
extern uint32_t sy3079as_process_data(void);
extern void sy3079as_clear_interrupt(void);
extern void sy3079_u32_swap(uint32_t *x, uint32_t *y);
extern void sy3079_bubble_sort_u32(uint32_t* array, int arysize);
extern uint32_t sy3079as_als_calibration(void);


#endif