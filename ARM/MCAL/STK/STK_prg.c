/*
 * STK_prg.c
 *
 *  Created on: Mar 6, 2023
 *      Author: dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_init.h"
#include "STK_priv.h"
#include "STK_config.h"
#include "STK_init.h"

static void (*SysTick_CallBack)(void) = NULL;
static u8 STK_u8ModeOfInterval;
void M_STK_void_Init(void)
{
#if   STK_CLK_SRC   ==  STK_AHB_DIV_8
	STK -> CTRL = 0x00000000 ;
#elif STK_CLK_SRC   ==  STK_AHB
	STK -> CTRL = 0x00000004 ;
#else
	#error "Wrong Choice"
#endif
}

void M_STK_void_BusyWait(u32 copy_u32Ticks)
{
	/*  Load Ticks to Load Register  */
	STK -> LOAD = copy_u32Ticks;
	/*  Start Timer  */
	SET_BIT(STK -> CTRL , 0);
	/*	wait till the flag raised	*/
	while((GET_BIT(STK -> CTRL , 16)) == 0)
	{
		asm("NOP");
	}
	/*	Stop Timer	*/
	CLR_BIT(STK -> CTRL , 0);
	STK -> LOAD = 0;
	STK -> VAL 	= 0;

}

void M_STK_void_SetIntervalSingle(u32 copy_u32Ticks , void (*pf)(void))
{
	/*  Load Ticks to Load Register  */
	STK -> LOAD = copy_u32Ticks;
	/*  Start Timer  */
	SET_BIT(STK -> CTRL , 0);
	/*	Save CallBack	*/
	SysTick_CallBack = pf;
	/*	Software Flag to indicate which callBack will execute*/
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
	/*	SysTick Interrupt Enable PIE*/
	SET_BIT(STK -> CTRL , 1);

}

void M_STK_void_SetIntervalPeriodic(u32 copy_u32Ticks , void (*pf)(void))
{
	/*  Load Ticks to Load Register  */
	STK -> LOAD = copy_u32Ticks;
	/*  Start Timer  */
	SET_BIT(STK -> CTRL , 0);
	/*	Save CallBack	*/
	SysTick_CallBack = pf;
	/*	Software Flag to indicate which callBack will execute*/
	STK_u8ModeOfInterval = STK_PERIODIC_INTERVAL;
	/*	SysTick Interrupt Enable PIE*/
	SET_BIT(STK -> CTRL , 1);

}

void M_STK_void_SetStopInterval(void)
{
	/*	Stop Timer	*/
	CLR_BIT(STK -> CTRL , 0);
	STK -> LOAD = 0;
	STK -> VAL 	= 0;
}

u32 M_STK_u32_GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = ((STK -> LOAD) - (STK -> VAL));
	return Local_u32ElapsedTime;
}

u32 M_STK_u32_GetRemainingTime(void)
{
	u32 Local_u32RemainingTime;
	Local_u32RemainingTime = (STK -> VAL);
	return Local_u32RemainingTime;
}

void SysTick_Handler(void)
{
	u8 Local_u8Temp;
	if(STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/*	1 - Disable Interrupt	*/
		CLR_BIT(STK -> CTRL , 1);

		/*	2 - Stop the timer		*/
		CLR_BIT(STK -> CTRL , 0);
		STK -> LOAD = 0;
		STK -> VAL 	= 0;
	}
	SysTick_CallBack();
	/*	Clear Interrupt Flag	*/
	Local_u8Temp = GET_BIT(STK -> CTRL , 16);
}
