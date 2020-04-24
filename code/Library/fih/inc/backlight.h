#ifndef BACKLIGHT_H__
#define BACKLIGHT_H__
#include "Nano100Series.h"
#include "stdint.h"
#include "fih_arg.h"

#define Lum_20cd				1
#define Lum_30cd				2
#define Lum_50cd				3
#define Lum_70cd				4	
#define Lum_90cd				5
#define Lum_110cd				6
#define Lum_130cd				7

extern uint8_t g_CalDac_Reg;

typedef struct {
	uint8_t reg_05;
	uint8_t reg_08;
	uint8_t reg_1D;
	uint8_t reg_18;
	uint8_t reg_19;
	uint8_t reg_1A;
	uint8_t reg_1B;	
} fih_lcd;

extern void BrightHandler(void);
extern void Bright_Strong(void);
extern void Bright_Weak(void);

#endif
