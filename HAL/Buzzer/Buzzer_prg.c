/*
 * Buzzer_prg.c
 *
 *  Created on: Feb 4, 2023
 *      Author: dell
 */
#include "util/delay.h"
#include "STD_TYPES.h"

#include "Dio_ini.h"
#include "Buzzer_priv.h"
#include "Buzzer_config.h"
#include "Buzzer_ini.h"

void H_Buzzer_Void_init(void)
{
	M_Dio_Void_setPinDir( BUZZER_PORT , BUZZER_PIN, OUTPUT);
}

void H_Buzzer_Void_setOnOnce(void)
{
	M_Dio_Void_setPinValue(BUZZER_PORT, BUZZER_PIN, HIGH);
	_delay_ms(1000);
	M_Dio_Void_setPinValue(BUZZER_PORT, BUZZER_PIN, LOW);
}

void H_Buzzer_Void_setOnTwice(void)
{
	M_Dio_Void_setPinValue(BUZZER_PORT, BUZZER_PIN, HIGH);
	_delay_ms(1000);
	M_Dio_Void_setPinValue(BUZZER_PORT, BUZZER_PIN, LOW);
	_delay_ms(1000);

	M_Dio_Void_setPinValue(BUZZER_PORT, BUZZER_PIN, HIGH);
	_delay_ms(1000);
	M_Dio_Void_setPinValue(BUZZER_PORT, BUZZER_PIN, LOW);
}

