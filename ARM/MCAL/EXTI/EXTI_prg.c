/*
 * EXTI_prg.c
 *
 *  Created on: Mar 6, 2023
 *      Author: dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_init.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI_init.h"

static void (*EXTI_CallBack[3]) (void) = {0,0,0};

void M_EXTI_void_Init()
{

}

void M_EXTI_void_EnableLine(u8 copy_u8ExtiLine)
{
	SET_BIT(EXTI -> IMR , copy_u8ExtiLine);
}

void M_EXTI_void_DisableLine(u8 copy_u8ExtiLine)
{
	CLR_BIT(EXTI -> IMR , copy_u8ExtiLine);
}

void M_EXTI_void_SetExtiEdge(u8 copy_u8ExtiLine , u8 copy_u8ExtiEdge)
{
	switch(copy_u8ExtiEdge)
	{
	case EXTI_RISING :
		SET_BIT(EXTI -> RSTR , copy_u8ExtiLine);
		CLR_BIT(EXTI -> FSTR , copy_u8ExtiLine);
		break;
	case EXTI_FALLING :
		SET_BIT(EXTI -> FSTR , copy_u8ExtiLine);
		CLR_BIT(EXTI -> RSTR , copy_u8ExtiLine);
		break;
	case EXTI_IOC :
		SET_BIT(EXTI -> RSTR , copy_u8ExtiLine);
		SET_BIT(EXTI -> FSTR , copy_u8ExtiLine);
		break;
	default:
		CLR_BIT(EXTI -> RSTR , copy_u8ExtiLine);
		CLR_BIT(EXTI -> FSTR , copy_u8ExtiLine);
	}
}

void	M_EXTI_voidSetCallBack(void (*Pf) (void) , u8 copy_u8ExtiLine)
{
	if(Pf != 0)
	{
		   switch(copy_u8ExtiLine)
		   {
		   case EXTI0_ID:
				EXTI_CallBack[0] = Pf; //Ahmed
		   		break;
		   	case EXTI1_ID:
				EXTI_CallBack[1] = Pf;
		   		break;
		   	case EXTI2_ID:
				EXTI_CallBack[2] = Pf;
		   		break;
		   }
	}
}

//External Peripherals
void	EXTI0_IRQHandler(void)
{
	if(GET_BIT(EXTI -> PR , 0) != 0)
	{
		SET_BIT(EXTI -> PR , 0);
		EXTI_CallBack[0]();
	}

}
void	EXTI1_IRQHandler(void)
{
	if(GET_BIT(EXTI -> PR , 0) != 0)
	{
		SET_BIT(EXTI -> PR , 0);
		EXTI_CallBack[1]();
	}

}
void	EXTI2_IRQHandler(void)
{
	if(GET_BIT(EXTI -> PR , 0) != 0)
	{
		SET_BIT(EXTI -> PR , 0);
		EXTI_CallBack[2]();
	}

}
