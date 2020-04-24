#include <stdio.h>
#include "stdint.h"
#include "Nano100Series.h"
#include "fih_arg.h"


uint8_t g_CalDac_Reg = 7;//eason

fih_lcd g_LcdSettingAdj[7]={
{0x82,0x05,0x5A,0x85,0x40,0x40,0x50},//20cd/m2
{0x82,0x05,0x60,0x85,0x40,0x40,0x50},//30cd/m2
{0x82,0x05,0x67,0x85,0x40,0x40,0x50},//50cd/m2
{0x82,0x05,0x6C,0x85,0x40,0x40,0x50},//70cd/m2
{0x82,0x05,0x6F,0x85,0x40,0x40,0x50},//90cd/m2
{0x82,0x05,0x73,0x85,0x40,0x40,0x50},//110cd/m2
{0x82,0x05,0x76,0x85,0x40,0x40,0x50}//130cd/m2
};



void BrightHandler(void)
{
	fih_lcd s_str;
    
	switch(g_CalDac_Reg)
	{
		case Lum_20cd:  s_str=g_LcdSettingAdj[0]; break;
		case Lum_30cd:  s_str=g_LcdSettingAdj[1]; break;
		case Lum_50cd:  s_str=g_LcdSettingAdj[2]; break;
		case Lum_70cd:  s_str=g_LcdSettingAdj[3]; break;
		case Lum_90cd:  s_str=g_LcdSettingAdj[4]; break;
		case Lum_110cd:  s_str=g_LcdSettingAdj[5];break;
		case Lum_130cd:  s_str=g_LcdSettingAdj[6];break;
		default: s_str=g_LcdSettingAdj[4];	break;
	}
	Spi_WriteReg_1(0x05,s_str.reg_05);
	Spi_WriteReg_1(0x08,s_str.reg_08);
	Spi_WriteReg_1(0x1D,s_str.reg_1D);
	Spi_WriteReg_1(0x18,s_str.reg_18);
	Spi_WriteReg_1(0x19,s_str.reg_19);
	Spi_WriteReg_1(0x1A,s_str.reg_1A);
	Spi_WriteReg_1(0x1B,s_str.reg_1B);
	
	Spi_WriteReg_2(0x05,s_str.reg_05);
	Spi_WriteReg_2(0x08,s_str.reg_08);
	Spi_WriteReg_2(0x1D,s_str.reg_1D);
	Spi_WriteReg_2(0x18,s_str.reg_18);
	Spi_WriteReg_2(0x19,s_str.reg_19);
	Spi_WriteReg_2(0x1A,s_str.reg_1A);
	Spi_WriteReg_2(0x1B,s_str.reg_1B);
}



void Bright_Strong(void)
{

	g_CalDac_Reg++;
	if(g_CalDac_Reg>=8)
	{
		g_CalDac_Reg=7;
		return;
	}
	g_CalDac_Reg %= 9;
	
#ifdef BACKLIGHT_DEBUG
	printf("BL level is %d \n",g_CalDac_Reg);
#endif
	
	BrightHandler();
}

void Bright_Weak(void)
{

	g_CalDac_Reg--;
	if(g_CalDac_Reg==0)
	{
		g_CalDac_Reg=1;
		return;
	}
	g_CalDac_Reg %= 9;

#ifdef BACKLIGHT_DEBUG
	printf("BL level is %d \n",g_CalDac_Reg);
#endif

	BrightHandler();
}


