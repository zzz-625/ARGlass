#ifndef LP_I2C_H__
#define LP_I2C_H__

#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"

/**宏定义----------------------------------------------------*/


#define GPIO_PIN_RESET	0 
#define GPIO_PIN_SET	1

#define LP_IIC_SCL(pin_status)			PA11 = pin_status;
#define LP_IIC_SDA(pin_status)			PA10 = pin_status;

#define LP_IIC_SCL_IS_HIGH()				(PA11 != GPIO_PIN_RESET)
#define LP_IIC_SDA_IS_HIGH()				(PA10 != GPIO_PIN_RESET)



extern int LP_WriteI2C_Byte(uint8_t SlaAddr, uint8_t RegAddr, uint8_t Data);
extern int LP_WriteI2C_ByteN(uint8_t SlaAddr, uint8_t RegAddr, uint8_t *P_Data, uint16_t N);
extern uint8_t LP_ReadI2C_Byte(uint8_t SlaAddr, uint8_t RegAddr);
extern int LP_ReadI2C_ByteN(uint8_t SlaAddr, uint8_t RegAddr, uint8_t *p_data, uint16_t N);


#endif
