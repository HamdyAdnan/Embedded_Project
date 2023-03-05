/*
 * SSD_prg.c
 *
 *  Created on: Feb 1, 2023
 *      Author: dell
 */
#include "STD_TYPES.h"
#include "GPIO_init.h"
#include "SSD_priv.h"
#include "SSD_config.h"
#include "SSD_ini.h"

void H_SSD_Void_init(void)
{
	M_GPIO_void_SetPinDir(SSD_LED_A_PORT, SSD_LED_A_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(SSD_LED_B_PORT, SSD_LED_B_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(SSD_LED_C_PORT, SSD_LED_C_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(SSD_LED_D_PORT, SSD_LED_D_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(SSD_LED_E_PORT, SSD_LED_E_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(SSD_LED_F_PORT, SSD_LED_F_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(SSD_LED_G_PORT, SSD_LED_G_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(SSD_LED_H_PORT, SSD_LED_H_PIN, OUT_20MHZ_PP);

	M_GPIO_void_SetPinDir(SSD_DIG1_EN_PORT, SSD_DIG1_EN_PIN, OUT_20MHZ_PP);
	M_GPIO_void_SetPinDir(SSD_DIG2_EN_PORT, SSD_DIG2_EN_PIN, OUT_20MHZ_PP);
}
void H_SSD_Void_DisplayNumber(u8 number)
{
	if(number > 99)
	{
		return;
	}
	u8 units = number % 10;
	u8 tens = number / 10;
	u32 i;


	for(i=0; i<SSD_DISPLAY_TIME;i++)
	{
	switch(units)
	{
	case 0:
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 1 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 2 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 3 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 4 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 5 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 6 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 7 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 8 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 9 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	}

	//Enable DIG 1 (units)
	M_GPIO_void_SetPinValue(SSD_DIG1_EN_PORT, SSD_DIG1_EN_PIN, HIGH);
	//Disable DIG 2 (tens)
	M_GPIO_void_SetPinValue(SSD_DIG2_EN_PORT, SSD_DIG2_EN_PIN, LOW);
	_delay_ms(1);
	M_GPIO_void_SetPinValue(SSD_DIG1_EN_PORT, SSD_DIG1_EN_PIN, LOW);

	switch(tens)
	{
	case 0:
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 1 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 2 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 3 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 4 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 5 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 6 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 7 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 8 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	case 9 :
		M_GPIO_void_SetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW);
		M_GPIO_void_SetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH);
		M_GPIO_void_SetPinValue(SSD_LED_H_PORT, SSD_LED_H_PIN, LOW);
		break;
	}

	//Enable DIG 1 (tens)
	M_GPIO_void_SetPinValue(SSD_DIG2_EN_PORT, SSD_DIG2_EN_PIN, HIGH);
	_delay_ms(1);
	M_GPIO_void_SetPinValue(SSD_DIG2_EN_PORT, SSD_DIG2_EN_PIN, LOW);

	}
}
