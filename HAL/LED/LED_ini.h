#ifndef LED_LED_INI_H_
#define LED_LED_INI_H_
#include "STD_TYPES.h"
#define RED_LED   0
#define GRN_LED   1
#define BLU_LED   2

void H_Led_Void_ledInit(u8 LedID);
void H_Led_Void_ledSetON(u8 LedID);
void H_Led_Void_ledSetOFF(u8 LedID);
void H_Led_Void_ledToggle(u8 LedID);

#endif /*LED_LED_INI_H_*/
