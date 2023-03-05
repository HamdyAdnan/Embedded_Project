/*
 * PB_prg.c
 *
 *  Created on: Feb 2, 2023
 *      Author: dell
 */
#include "STD_TYPES.h"
#include "GPIO_init.h"
#include "PB_priv.h"
#include "PB_config.h"
#include "PB_ini.h"
#include "_delay_ms.h"


void H_PB_Void_init(const PB_t * pcopy_PB)
{
	M_GPIO_void_SetPinDir(pcopy_PB->PB_port , pcopy_PB->PB_pin, IN_PULL_UP_DOWN);
}
void H_PB_Void_read(const PB_t * pcopy_PB , u8 *pvalue)
{
	u8 read;

	if(pcopy_PB->PB_ActiveMode == ACTIVE_LOW)
	{
		*pvalue = NOT_PRESSED_ACTIVE_LOW;
		M_GPIO_void_GetPinValue(pcopy_PB->PB_port, pcopy_PB->PB_pin, &read);
		if(read == PRESSED_ACTIVE_LOW)
		{
			_delay_ms(20);
			//get second reading to check that is not noise
			M_GPIO_void_GetPinValue(pcopy_PB->PB_port, pcopy_PB->PB_pin, &read);
			if(read == PRESSED_ACTIVE_LOW)
			{
				while(read == PRESSED_ACTIVE_LOW)
				{
					M_GPIO_void_GetPinValue(pcopy_PB->PB_port, pcopy_PB->PB_pin, &read);

				}
				*pvalue = PRESSED_ACTIVE_LOW;
				return;
			}

		}
	}
	else if(pcopy_PB->PB_ActiveMode == ACTIVE_HIGH)
	{

		*pvalue = NOT_PRESSED_ACTIVE_HIGH;
		M_GPIO_void_GetPinValue(pcopy_PB->PB_port, pcopy_PB->PB_pin, &read);
		if(read == PRESSED_ACTIVE_HIGH)
		{
			_delay_ms(20);
			//get second reading to check that is not noise
			M_GPIO_void_GetPinValue(pcopy_PB->PB_port, pcopy_PB->PB_pin, &read);
				if(read == PRESSED_ACTIVE_HIGH)
				{
					while(read == PRESSED_ACTIVE_HIGH)
				{
						M_GPIO_void_GetPinValue(pcopy_PB->PB_port, pcopy_PB->PB_pin, &read);

				}
					*pvalue = PRESSED_ACTIVE_HIGH;
					return;
				}

			}

	}

}
