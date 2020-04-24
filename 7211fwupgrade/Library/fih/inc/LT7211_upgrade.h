#ifndef LT7211_UPGRADE_H__
#define LT7211_UPGRADE_H__

#include "fih_arg.h"



extern int CheckChipId(void);
extern void Config(void);
extern void ReadKey(void);
extern void BlockErase(void);
extern void Write_Frimware(void);
extern int Verify_Firmware(void);
extern void Write_Key(void);
extern void LT7211_Firmware_Upgrade(void);


#endif
