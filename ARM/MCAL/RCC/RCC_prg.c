/*
 * RCC_prg.c
 *
 *  Created on: Feb 28, 2023
 *      Author: dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_init.h"
#include "RCC_priv.h"
#include "RCC_config.h"


void M_RCC_void_SysClkInit(void)
{
#if SYSTEM_CLK == RCC_HSI
	SET_BIT(RCC_CR , 0);
	CLR_BIT(RCC_CFGR , 0);
	CLR_BIT(RCC_CFGR , 1);
#elif SYSTEM_CLK == RCC_HSE
	SET_BIT(RCC_CR , 16);
	SET_BIT(RCC_CFGR , 0);
	CLR_BIT(RCC_CFGR , 1);
#elif SYSTEM_CLK == RCC_PLL
	SET_BIT(RCC_CR , 25);
	CLR_BIT(RCC_CFGR , 0);
	SET_BIT(RCC_CFGR , 1);
#else
	#error "Wrong Choice of RCC Clock type"
#endif
}

void M_RCC_void_EnablePerClk(u8 copy_u8PerBus , u8 copy_u8PerNum)
{
	//Range Check
	if(copy_u8PerNum < 32)
	{
		switch(copy_u8PerBus)
		{
		case RCC_AHB:
			SET_BIT(RCC_AHBENR , copy_u8PerNum);
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR , copy_u8PerNum);
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR , copy_u8PerNum);
			break;
		}
	}
}
void M_RCC_void_DisablePerClk(u8 copy_u8PerBus , u8 copy_u8PerNum)
{
		//Range Check
	if(copy_u8PerNum < 32)
	{
		switch(copy_u8PerBus)
		{
		case RCC_AHB:
			CLR_BIT(RCC_AHBENR , copy_u8PerNum);
			break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR , copy_u8PerNum);
			break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR , copy_u8PerNum);
			break;
		}
	}
}
