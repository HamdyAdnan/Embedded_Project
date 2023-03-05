/*
 * DC_prg.c
 *
 *  Created on: Feb 23, 2023
 *      Author: dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DC_priv.h"
#include "DC_config.h"
#include "DC_ini.h"
#include "GPIO_init.h"

void H_DC_void_Init(void)
{
	M_GPIO_void_SetPinDir(PORTB_ID , PIN3_ID , OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(PORTB_ID , PIN4_ID , OUT_20MHZ_PP);
	M_TIMER0_void_Init();
	M_TIMER0_void_start();
	M_GPIO_void_SetPinDir(PORTB_ID, PIN5_ID, OUT_20MHZ_PP);
}
void H_DC_void_Control(u8 copy_u8Speed)
{
	switch(copy_u8Speed)
	{
	case DC_STOP:
		M_TIMER0_void_setFastPWM(0);
		M_GPIO_void_SetPinValue(PORTB_ID , PIN3_ID , LOW);
		M_GPIO_void_SetPinValue(PORTB_ID , PIN4_ID , LOW);
		break;
	case DC_HALF_SPEED:
		M_TIMER0_void_setFastPWM(50);
		M_GPIO_void_SetPinValue(PORTB_ID , PIN3_ID , LOW);
		M_GPIO_void_SetPinValue(PORTB_ID , PIN4_ID , HIGH);
		break;
	case DC_FULL_SPEED:
		M_TIMER0_void_setFastPWM(100);
		M_GPIO_void_SetPinValue(PORTB_ID , PIN3_ID , LOW);
		M_GPIO_void_SetPinValue(PORTB_ID , PIN4_ID , HIGH);
		break;
	}
}
