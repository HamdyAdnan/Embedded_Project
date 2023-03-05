/*
 * _delay_ms.c
 *
 *  Created on: Mar 2, 2023
 *      Author: dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "_delay_ms.h"

void	_delay_ms(u32 ms)
{
	for(u32 i = 0; i < (ms * 500) ; i++)
	{
		asm("NOP");
	}
}
