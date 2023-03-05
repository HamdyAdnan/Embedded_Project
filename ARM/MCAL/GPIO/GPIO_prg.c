/*
 * GPIO_prg.c
 *
 *  Created on: Mar 1, 2023
 *      Author: dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_init.h"
#include "GPIO_priv.h"
#include "GPIO_config.h"

void M_GPIO_void_SetPinDir(u8 PortID , u8 PinID , u8 Dir)
{
	//Range Check
if(PortID < 3 && PinID < 16 && Dir < 16)
{
	if(PinID < 8) /*PIN0 : PIN7 --> CRL*/
	{
		switch(PortID)
		{
		case PORTA_ID:
			GPIOA_CRL &= ~(0b1111<<(PinID * 4)); //Clear the 4 Bits
			GPIOA_CRL |=  ((Dir)<<(PinID * 4)); //Assign The 4 Bits
			break;
		case PORTB_ID:
			GPIOB_CRL &= ~(0b1111<<(PinID * 4)); //Clear the 4 Bits
			GPIOB_CRL |=  ((Dir)<<(PinID * 4)); //Assign The 4 Bits
			break;
		case PORTC_ID:
			GPIOC_CRL &= ~(0b1111<<(PinID * 4)); //Clear the 4 Bits
			GPIOC_CRL |=  ((Dir)<<(PinID * 4)); //Assign The 4 Bits
			break;
		}
	}
	else if(PinID < 16) /*PIN0 : PIN7 --> CRL*/
	{
		PinID -=8;
		switch(PortID)
		{
		case PORTA_ID:
			GPIOA_CRH &= ~(0b1111<<(PinID * 4)); //Clear the 4 Bits
			GPIOA_CRH |=  ((Dir)<<(PinID * 4)); //Assign The 4 Bits
			break;
		case PORTB_ID:
			GPIOB_CRH &= ~(0b1111<<(PinID * 4)); //Clear the 4 Bits
			GPIOB_CRH |=  ((Dir)<<(PinID * 4)); //Assign The 4 Bits
			break;
		case PORTC_ID:
			GPIOC_CRH &= ~(0b1111<<(PinID * 4)); //Clear the 4 Bits
			GPIOC_CRH |=  ((Dir)<<(PinID * 4)); //Assign The 4 Bits
			break;
		}
	}
	}
}
void M_GPIO_void_SetPinValue(u8 PortID , u8 PinID , u8 Value)
{
	//Range Check
if(PortID < 3 && PinID < 16)
{
	if(Value == LOW)
	{
		switch(PortID)
		{
		case PORTA_ID:
			CLR_BIT(GPIOA_ODR , PinID);
			break;
		case PORTB_ID:
			CLR_BIT(GPIOB_ODR , PinID);
			break;
		case PORTC_ID:
			CLR_BIT(GPIOC_ODR , PinID);
			break;
		}
	}
	else if(Value == HIGH)
	{
		switch(PortID)
		{
		case PORTA_ID:
			SET_BIT(GPIOA_ODR , PinID);
			break;
		case PORTB_ID:
			SET_BIT(GPIOB_ODR , PinID);
			break;
		case PORTC_ID:
			SET_BIT(GPIOC_ODR , PinID);
			break;
		}
	}
}
}
void M_GPIO_void_GetPinValue(u8 PortID , u8 PinID , u8 *Value)
{
	//Range Check
if(PortID < 3 && PinID < 16)
{
		switch(PortID)
		{
		case PORTA_ID:
			*Value = GET_BIT(GPIOA_IDR , PinID);
			break;
		case PORTB_ID:
			*Value = GET_BIT(GPIOB_IDR , PinID);
			break;
		case PORTC_ID:
			*Value = GET_BIT(GPIOC_IDR , PinID);
			break;
		}
	}
}
