#ifndef LT_I2C_H__
#define LT_I2C_H__

#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"

/**宏定义----------------------------------------------------*/
#define LT7211		0x56

#define GPIO_PIN_RESET	0
#define GPIO_PIN_SET	1

#define LT_IIC_SCL(pin_status)			PA5 = pin_status;
#define LT_IIC_SDA(pin_status)			PA4 = pin_status;

#define LT_IIC_SCL_IS_HIGH()				(PA5 != GPIO_PIN_RESET)
#define LT_IIC_SDA_IS_HIGH()				(PA4 != GPIO_PIN_RESET)

#define LT7211_RESET			PB10

typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus;

extern int LT_WriteI2C_Byte(uint8_t RegAddr, uint8_t Data);
extern int LT_WriteI2C_ByteN(uint8_t RegAddr, uint8_t *P_Data, uint16_t N);
extern uint8_t LT_ReadI2C_Byte(uint8_t RegAddr);
extern int LT_ReadI2C_ByteN(uint8_t RegAddr, uint8_t *p_data, uint16_t N);
extern void LtChipID(void);
extern void LT_Read_Mode(void);

#endif
