#ifndef KEY_H__
#define KEY_H__

#include "Nano100Series.h"
#include "fih_arg.h"

extern void Mode_Change_Interrupt_Init(void);
extern void GPDEF_IRQHandler(void);
extern void Backlight_Interrupt_Init(void);
extern void GPABC_IRQHandler(void);

#endif
