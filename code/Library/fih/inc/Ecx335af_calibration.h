#ifndef __ECX335AF_CALIBRATION_H__
#define __ECX335AF_CALIBRATION_H__

#include <stdio.h>
#include "Nano100Series.h"
#include "fih_arg.h"

#define DATA_FLASH_CALI_BASE        0xFC00
#define DATA_FLASH_CALI_END         0xFDFF

extern void Set_Vcali_To_Data_Flash(void);

extern void Get_Vcali_From_Data_Flash(void);

extern void Horizontal_orbit_adjustment(int8_t h1, int8_t h2);
extern void Vertical_orbit_adjustment(int8_t v1, int8_t v2);
extern void Set_Value_To_Ecx335af(void);
extern void Ecx335af_Calibration(void);

extern void Ecx335af_Calibration_test(void);


#endif
