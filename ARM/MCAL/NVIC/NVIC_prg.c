/*
 * NVIC_prg.c
 *
 *  Created on: Mar 5, 2023
 *      Author: dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_init.h"
#include "NVIC_priv.h"
#include "NVIC_config.h"
#include "NVIC_init.h"

static void (*EXTI0_CallBack) (void) = 0;
static void (*EXTI1_CallBack) (void) = 0;

void M_NVIC_void_Init()
{
#ifndef SCB_AIRCR
#define SCB_AIRCR       *((volatile u32*)(0xE000ED00+0x0C))
#endif
	SCB_AIRCR = NVIC_GROUP_SUB_NUM;
}
void M_NVIC_void_EnableInt(u8 IntNum)
{
	if(IntNum < 32)
	{
		NVIC_ISER0 = (1 << IntNum);
	}
	else if(IntNum < 64)
	{
		IntNum -= 32;
		NVIC_ISER1 = (1 << IntNum);
	}
}
void M_NVIC_void_DisableInt(u8 IntNum)
{
	if(IntNum < 32)
	{
		NVIC_ICER0 = (1 << IntNum);
	}
	else if(IntNum < 64)
	{
		IntNum -= 32;
		NVIC_ICER1 = (1 << IntNum);
	}
}
void M_NVIC_void_SetPendingFlag(u8 IntNum)
{
	if(IntNum < 32)
	{
		NVIC_ISPR0 = (1 << IntNum);
	}
	else if(IntNum < 64)
	{
		IntNum -= 32;
		NVIC_ISPR1 = (1 << IntNum);
	}
}
void M_NVIC_void_ClrPendingFlag(u8 IntNum)
{
	if(IntNum < 32)
	{
		NVIC_ICPR0 = (1 << IntNum);
	}
	else if(IntNum < 64)
	{
		IntNum -= 32;
		NVIC_ICPR1 = (1 << IntNum);
	}
}
void M_NVIC_u8_GetActiveFlag(u8 IntNum)
{
	u8 Local_Active = 0x22;
			if(IntNum < 32)
			{
				GIT_BIT(NVIC_IABR0 , (1 << IntNum));
			}
			else if(IntNum < 64)
			{
				IntNum -= 32;
				GIT_BIT(NVIC_IABR1 , (1 << IntNum));
			}
	return Local_Active;
}

void M_NVIC_void_SetPriority(u8 IntNum , u8 Priority)
{
	NVIC_IPR[IntNum] = (Priority << 4);
}

void	NVIC_voidEXTI0SetCallBack(void (*Pf) (void))
{
	if(Pf != 0)
	{
		EXTI0_CallBack = Pf; //Ahmed
	}
}

//External Peripherals

void	NVIC_voidEXTI1SetCallBack(void (*Pf) (void))
{
	if(Pf != 0)
	{
		EXTI1_CallBack = Pf; //Ahmed
	}
}

