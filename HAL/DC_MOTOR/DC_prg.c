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
#include "Dio_ini.h"

void H_DC_void_Init(void)
{
	M_Dio_Void_setPinDir(PORTD_ID , PIN0_ID , OUTPUT);
	M_Dio_Void_setPinDir(PORTD_ID , PIN1_ID , OUTPUT);
	M_TIMER0_void_Init();
	M_TIMER0_void_start();
	M_Dio_Void_setPinDir(PORTB_ID, PIN3_ID, OUTPUT);
}
void H_DC_void_Control(u8 copy_u8Speed)
{
	switch(copy_u8Speed)
	{
	case DC_STOP:
		M_TIMER0_void_setFastPWM(0);
		M_Dio_Void_setPinValue(PORTD_ID , PIN0_ID , LOW);
		M_Dio_Void_setPinValue(PORTD_ID , PIN1_ID , LOW);
		break;
	case DC_HALF_SPEED:
		M_TIMER0_void_setFastPWM(50);
		M_Dio_Void_setPinValue(PORTD_ID , PIN0_ID , LOW);
		M_Dio_Void_setPinValue(PORTD_ID , PIN1_ID , HIGH);
		break;
	case DC_FULL_SPEED:
		M_TIMER0_void_setFastPWM(100);
		M_Dio_Void_setPinValue(PORTD_ID , PIN0_ID , LOW);
		M_Dio_Void_setPinValue(PORTD_ID , PIN1_ID , HIGH);
		break;
	}
}
