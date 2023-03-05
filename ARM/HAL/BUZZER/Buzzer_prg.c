/*
 * Buzzer_prg.c
 *
 *  Created on: Feb 4, 2023
 *      Author: dell
 */
#include "_delay_ms.h"
#include "STD_TYPES.h"

#include "GPIO_init.h"
#include "Buzzer_priv.h"
#include "Buzzer_config.h"
#include "Buzzer_ini.h"

void H_Buzzer_Void_init(void)
{
	M_GPIO_void_SetPinDir( BUZZER_PORT , BUZZER_PIN, OUT_20MHZ_PP);
}

void H_Buzzer_Void_setOnOnce(void)
{
	M_GPIO_void_SetPinValue(BUZZER_PORT, BUZZER_PIN, HIGH);
	_delay_ms(1000);
	M_GPIO_void_SetPinValue(BUZZER_PORT, BUZZER_PIN, LOW);
}

void H_Buzzer_Void_setOnTwice(void)
{
	M_GPIO_void_SetPinValue(BUZZER_PORT, BUZZER_PIN, HIGH);
	_delay_ms(1000);
	M_GPIO_void_SetPinValue(BUZZER_PORT, BUZZER_PIN, LOW);
	_delay_ms(1000);

	M_GPIO_void_SetPinValue(BUZZER_PORT, BUZZER_PIN, HIGH);
	_delay_ms(1000);
	M_GPIO_void_SetPinValue(BUZZER_PORT, BUZZER_PIN, LOW);
}

