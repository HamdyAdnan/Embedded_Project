/*
 * KeyPad_prg.c
 *
 *  Created on: Feb 2, 2023
 *      Author: dell
 */
#include "STD_TYPES.h"
#include "GPIO_init.h"
#include "KeyPad_priv.h"
#include "KeyPad_config.h"
#include "KeyPad_ini.h"
#include "_delay_ms.h"

void Delay_ms(void)
{
	for(u32 i=0; i < 2000 ; i++)
	{
		asm("NOP");
	}
}
void H_KEYPAD_Void_init(void)
{
	//SET ALL ROWS DIRECTION AS OUTPUT
	M_GPIO_void_SetPinDir(KEYPAD_R0_PORT, KEYPAD_R0_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(KEYPAD_R1_PORT, KEYPAD_R1_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(KEYPAD_R2_PORT, KEYPAD_R2_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(KEYPAD_R3_PORT, KEYPAD_R3_PIN, OUT_20MHZ_PP);
	//SET ALL COLOUMNS DIRECTION AS INPUT
	M_GPIO_void_SetPinDir(KEYPAD_C0_PORT, KEYPAD_C0_PIN, IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinDir(KEYPAD_C1_PORT, KEYPAD_C1_PIN, IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinDir(KEYPAD_C2_PORT, KEYPAD_C2_PIN, IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinDir(KEYPAD_C3_PORT, KEYPAD_C3_PIN, IN_PULL_UP_DOWN);
	//DEACTIVATE ROWS
	M_GPIO_Void_SetPinValue(KEYPAD_R0_PORT, KEYPAD_R0_PIN, HIGH);
	M_GPIO_Void_SetPinValue(KEYPAD_R1_PORT, KEYPAD_R1_PIN, HIGH);
	M_GPIO_Void_SetPinValue(KEYPAD_R2_PORT, KEYPAD_R2_PIN, HIGH);
	M_GPIO_Void_SetPinValue(KEYPAD_R3_PORT, KEYPAD_R3_PIN, HIGH);
#if(KEYPAD_TYPE == KEYPAD_TYPE_SIM)
	M_GPIO_Void_SetPinValue(KEYPAD_C0_PORT,KEYPAD_C0_PIN, HIGH);
	M_GPIO_Void_SetPinValue(KEYPAD_C1_PORT,KEYPAD_C1_PIN, HIGH);
	M_GPIO_Void_SetPinValue(KEYPAD_C2_PORT,KEYPAD_C2_PIN, HIGH);
	M_GPIO_Void_SetPinValue(KEYPAD_C3_PORT,KEYPAD_C3_PIN, HIGH);
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
		M_GPIO_Void_SetPinValue(KEYPAD_ROWS_PORT, Loc_row_index, LOW);
		for(Loc_col_index = KEYPAD_C0_PIN; Loc_col_index <= KEYPAD_C3_PIN; Loc_col_index++)
		{
			//get first reading
			M_GPIO_void_GetPinValue(KEYPAD_COLS_PORT, Loc_col_index, &read);
			if(read == ACTRIVE_LOW_PRESSED)
			{
				//debouncing delay
				_delay_ms(20);
				//get second reading
				M_GPIO_void_GetPinValue(KEYPAD_COLS_PORT, Loc_col_index, &read);
				if(read == ACTRIVE_LOW_PRESSED)
				{
					//single press
					while(read == ACTRIVE_LOW_PRESSED)
					{
						M_GPIO_void_GetPinValue(KEYPAD_COLS_PORT, Loc_col_index, &read);
					}//while
					Loc_key = Loc_KEYPAD_ARR[Loc_row_index - KEYPAD_R0_PIN][Loc_col_index - KEYPAD_C0_PIN];
					return Loc_key;
				}//if 2

			}//if 1
		}//for loop

		//deactivate
		M_GPIO_Void_SetPinValue(KEYPAD_ROWS_PORT, Loc_row_index, HIGH);

	}
	return Loc_key;
}
