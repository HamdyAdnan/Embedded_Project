/*
 * KeyPad_prg.c
 *
 *  Created on: Feb 2, 2023
 *      Author: dell
 */
#include "STD_TYPES.h"
#include <util/delay.h>
#include "Dio_ini.h"
#include "KeyPad_priv.h"
#include "KeyPad_config.h"
#include "KeyPad_ini.h"

void H_KEYPAD_Void_init(void)
{
	//SET ALL ROWS DIRECTION AS OUTPUT
	M_Dio_Void_setPinDir(KEYPAD_R0_PORT, KEYPAD_R0_PIN, OUTPUT);
	M_Dio_Void_setPinDir(KEYPAD_R1_PORT, KEYPAD_R1_PIN, OUTPUT);
	M_Dio_Void_setPinDir(KEYPAD_R2_PORT, KEYPAD_R2_PIN, OUTPUT);
	M_Dio_Void_setPinDir(KEYPAD_R3_PORT, KEYPAD_R3_PIN, OUTPUT);
	//SET ALL COLOUMNS DIRECTION AS INPUT
	M_Dio_Void_setPinDir(KEYPAD_C0_PORT, KEYPAD_C0_PIN, INPUT);
	M_Dio_Void_setPinDir(KEYPAD_C1_PORT, KEYPAD_C1_PIN, INPUT);
	M_Dio_Void_setPinDir(KEYPAD_C2_PORT, KEYPAD_C2_PIN, INPUT);
	M_Dio_Void_setPinDir(KEYPAD_C3_PORT, KEYPAD_C3_PIN, INPUT);
	//DEACTIVATE ROWS
	M_Dio_Void_setPinValue(KEYPAD_R0_PORT, KEYPAD_R0_PIN, HIGH);
	M_Dio_Void_setPinValue(KEYPAD_R1_PORT, KEYPAD_R1_PIN, HIGH);
	M_Dio_Void_setPinValue(KEYPAD_R2_PORT, KEYPAD_R2_PIN, HIGH);
	M_Dio_Void_setPinValue(KEYPAD_R3_PORT, KEYPAD_R3_PIN, HIGH);
#if(KEYPAD_TYPE == KEYPAD_TYPE_SIM)
    M_Dio_Void_setPinValue(KEYPAD_C0_PORT,KEYPAD_C0_PIN, HIGH);
	M_Dio_Void_setPinValue(KEYPAD_C1_PORT,KEYPAD_C1_PIN, HIGH);
	M_Dio_Void_setPinValue(KEYPAD_C2_PORT,KEYPAD_C2_PIN, HIGH);
	M_Dio_Void_setPinValue(KEYPAD_C3_PORT,KEYPAD_C3_PIN, HIGH);
#endif
}
u8 H_KEYPAD_Void_getPressesKey(void)
{
	u8 Loc_key = NO_PRESSED_KEY;
	u8 Loc_row_index;
	u8 Loc_col_index;
	u8 Loc_KEYPAD_ARR [4][4] = KEYPAD_ARR_MAP;
	u8 read;

	for(Loc_row_index = KEYPAD_R0_PIN; Loc_row_index <= KEYPAD_R3_PIN; Loc_row_index++)
	{
		//Active Row (LOW)
		M_Dio_Void_setPinValue(KEYPAD_ROWS_PORT, Loc_row_index, LOW);
		for(Loc_col_index = KEYPAD_C0_PIN; Loc_col_index <= KEYPAD_C3_PIN; Loc_col_index++)
		{
			//get first reading
			M_Dio_Void_getPin(KEYPAD_COLS_PORT, Loc_col_index, &read);
			if(read == ACTRIVE_LOW_PRESSED)
			{
				//debouncing delay
				_delay_ms(100);
				//get second reading
				M_Dio_Void_getPin(KEYPAD_COLS_PORT, Loc_col_index, &read);
				if(read == ACTRIVE_LOW_PRESSED)
				{
					//single press
					while(read == ACTRIVE_LOW_PRESSED)
					{
						M_Dio_Void_getPin(KEYPAD_COLS_PORT, Loc_col_index, &read);
					}//while
					Loc_key = Loc_KEYPAD_ARR[Loc_row_index - KEYPAD_R0_PIN][Loc_col_index - KEYPAD_C0_PIN];
					return Loc_key;
				}//if 2

			}//if 1
		}//for loop

		//deactivate
		M_Dio_Void_setPinValue(KEYPAD_ROWS_PORT, Loc_row_index, HIGH);

	}
	return Loc_key;
}
