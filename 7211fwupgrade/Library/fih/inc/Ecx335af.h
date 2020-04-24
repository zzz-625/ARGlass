#ifndef ECX335AF_H__
#define ECX335AF__H__
#include "Nano100Series.h"
#include "fih_arg.h"

#define SPI_OLED_PORT  	SPI2
#define SPI_WRITE_TX    SPI_WRITE_TX0
#define SPI_READ_RX     SPI_READ_RX0
#define OLED_RESET		PA9
#define OLED_CS1		PA8
#define OLED_CS2		PB4
#if 0
#define CHANGE_MODE		PC2
#else
#define CHANGE_MODE		PA6		//PC2
#endif

extern void Spi_WriteReg_1(uint8_t reg, uint8_t u8Value);
extern void Spi_WriteReg_2(uint8_t reg, uint8_t u8Value);
extern uint8_t Spi_ReadReg_1(uint8_t reg);
extern uint8_t Spi_ReadReg_2(uint8_t reg);
extern void step_1(void);
extern void step_2(void);
extern void step_3(void);
extern void step_4(void);
extern void step_5(void);
extern void step_6(void);
extern void step_6_1(void);
extern void ECX_PwrSv_1(void);
extern void ECX_PwrSv_2(void);
extern void Ecx335af_Init(void);
extern void Ecx335af_Power_On(void);
extern void Ecx335af_Power_Off(void);
extern void Ecx335af_Power_Saving(void);
extern void Ecx335af_Exit_Power_Saving(void);
extern void Ecx335af_spi2_init(void);
extern void Read_Ecx335af_reg(void);
extern void Change_Mode(void);

extern void delay_ms(int ms);


#endif
