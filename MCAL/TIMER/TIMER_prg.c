/*
 * TIMER_prg.h
 *
 *  Created on: Feb 8, 2023
 *      Author: dell
 */
#include <stdlib.h>
#include "avr/interrupt.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_priv.h"
#include "TIMER_config.h"
#include "TIMER_ini.h"

static void (*Arr_CallBack[2])(void) = {NULL , NULL};

void M_TIMER0_void_Init(void)
{
	//step 1 config timer mode
#if(TIMER0_MODE == TIMER0_NORMAL_MODE)
	CLR_BIT(TCCR0_REG ,WGM00_BIT);
	CLR_BIT(TCCR0_REG ,WGM01_BIT);
	//step 2 under each mode config OC0 pin mode
	#if(TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISCONNECTED && TIMER0_OC0_MODE <= TIMER0_OC0_MODE_SET)
		//step 1 Apply mask
		TCCR0_REG &= TIMER0_OC0_MASK;
		//step 2 insert value
		TCCR0_REG |= (TIMER0_OC0_MODE <<TIMER0_OC0_SHIF);
	#else
		#error("WRONG OC0 MODE!!")
	#endif
#elif(TIMER0_MODE == TIMER0_CTC_MODE)
	CLR_BIT(TCCR0_REG ,WGM00_BIT);
	SET_BIT(TCCR0_REG ,WGM01_BIT);
	//step 2 under each mode config OC0 pin mode
	#if(TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISCONNECTED && TIMER0_OC0_MODE <= TIMER0_OC0_MODE_SET)
		//step 1 Apply mask
		TCCR0_REG &= TIMER0_OC0_MASK;
		//step 2 insert value
		TCCR0_REG |= (TIMER0_OC0_MODE <<TIMER0_OC0_SHIF);
	#else
		#error("WRONG OC0 MODE!!")
	#endif
#elif(TIMER0_MODE == TIMER0_FAST_PWM_MODE)
	SET_BIT(TCCR0_REG ,WGM00_BIT);
	SET_BIT(TCCR0_REG ,WGM01_BIT);
	//step 2 under each mode config OC0 pin mode
	#if(TIMER0_OC0_MODE  == TIMER0_PWM_NON_INVERTED || TIMER0_OC0_MODE ==  TIMER0_PWM_INVERTED)
		//step 1 Apply mask
		TCCR0_REG &= TIMER0_OC0_MASK;
		//step 2 insert value
		TCCR0_REG |= TIMER0_OC0_MODE;
	#else
		#error("WRONG OC0 MODE!!")
	#endif
#elif(TIMER0_MODE == TIMER0_PHASECORRECT_MODE)
	SET_BIT(TCCR0_REG ,WGM00_BIT);
	CLR_BIT(TCCR0_REG ,WGM01_BIT);
	//step 2 under each mode config OC0 pin mode
	#if(TIMER0_OC0_MODE  == TIMER0_PWM_NON_INVERTED || TIMER0_OC0_MODE ==  TIMER0_PWM_INVERTED)
		//step 1 Apply mask
		TCCR0_REG &= TIMER0_OC0_MASK;
		//step 2 insert value
		TCCR0_REG |= TIMER0_OC0_MODE;
	#else
		#error("WRONG OC0 MODE!!")
	#endif
#else
	#error("WRONG TIMER MODE !!")
#endif


}
void M_TIMER0_void_start(void)
{
#if(TIMER0_PRESCALER >= TIMER0_PRESCALER_NO_CLK && TIMER0_PRESCALER <= TIMER0_PRESCALER_EXTCLK_RAIS_EDGE)
	//step 1 Apply mask
	TCCR0_REG &= TIMER0_PRESCALER_MASK;
	//step 2 insert value
	TCCR0_REG |= TIMER0_PRESCALER;
#else
	#error("WRONG PRESCALER!!")
#endif
}
void M_TIMER0_void_stop(void)
{
	//step 1 Apply mask
	TCCR0_REG &= TIMER0_PRESCALER_MASK;
	//step 2 insert value
	//TCCR0_REG |= TIMER0_PRESCALER_NO_CLK;
}

static u32 NumberOfOverflows =0;
static u32 NumberOfRemainingTicks =0;
void M_TIMER0_void_setTime(u32 copy_u32timeMS)
{
	u32 Loc_prescalerArr[] = {1 , 8 , 64 , 256 , 1024};
	f32 Loc_TickTime = (f32)Loc_prescalerArr[TIMER0_PRESCALER - 1] / FCPU;
	u32 NoOfDesiredTicks = (copy_u32timeMS *1000)/Loc_TickTime;
#if(TIMER0_MODE == TIMER0_NORMAL_MODE)
	NumberOfOverflows = NoOfDesiredTicks / 256;
	u32 NumberOfRemainingTicks = NoOfDesiredTicks % 256;
	if(NumberOfRemainingTicks != 0)
	{
		TCNT0_REG = 256 - NumberOfRemainingTicks;
		NumberOfOverflows++;
	}
#elif(TIMER0_MODE == TIMER0_CTC_MODE)
#endif
}
void M_TIMER0_void_EnableInt(u8 copy_u8IntID)
{
	//method 1
	/*switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID :
		SET_BIT(TIMSK_REG , TOIE0_BIT);
		break;
	case TIMER0_CMP_INT_ID :
		SET_BIT(TIMSK_REG , OCIE0_BIT);
		break;
	}*/
	//Method 2
	SET_BIT(TIMSK_REG , copy_u8IntID);
}
void M_TIMER0_void_DisableInt(u8 copy_u8IntID)
{
	//method 1
	/*switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID :
		CLR_BIT(TIMSK_REG , TOIE0_BIT);
		break;
	case TIMER0_CMP_INT_ID :
		CLR_BIT(TIMSK_REG , OCIE0_BIT);
		break;
	}*/
	//Method 2
	CLR_BIT(TIMSK_REG , copy_u8IntID);
}
void M_TIMER0_void_setCallBack(void (*ptrfn)(void) , u8 copy_u8IntID)
{
	//Method 1
	/*switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID :
		Arr_CallBack[0] = ptrfn;
		break;
	case TIMER0_CMP_INT_ID :
		Arr_CallBack[1] = ptrfn;
		break;
	}*/
	//Method 2
	Arr_CallBack[copy_u8IntID] = ptrfn;

}

void M_TIMER0_void_setFastPWM(u8 copy_u8Duty)
{
#if(TIMER0_MODE == TIMER0_FAST_PWM_MODE)
	#if(TIMER0_OC0_MODE   ==  TIMER0_PWM_NON_INVERTED)
		OCR0_REG= abs (((copy_u8Duty * 256) / 100)-1);
	#elif(TIMER0_OC0_MODE     TIMER0_PWM_INVERTED)
		OCR0_REG= 255 - ((copy_u8Duty * 256) / 100);
	#else
		#error("WRONG OC0 MODE!!")
	#endif
#endif
}
void M_TIMER0_void_setphaseCorrectPWM(u8 copy_u8Duty)
{
#if(TIMER0_MODE == TIMER0_PHASECORRECT_MODE)
	#if(TIMER0_OC0_MODE   ==  TIMER0_PWM_NON_INVERTED)
		OCR0_REG= abs ((copy_u8Duty * 255) / 100);
	#elif(TIMER0_OC0_MODE     TIMER0_PWM_INVERTED)
		OCR0_REG= 255 - ((copy_u8Duty * 255) / 100);
	#else
		#error("WRONG OC0 MODE!!")
	#endif
#endif
}

ISR(TIMER0_OVF_vect)
{
	static u32 Loc_OVFCounter = 0;
	Loc_OVFCounter++;
	if(Loc_OVFCounter == NumberOfOverflows)
	{
		//Step 1 reload TCNT with preload value
		TCNT0_REG = 256 - NumberOfRemainingTicks;
		//Step 2 Couter = 0
		Loc_OVFCounter = 0;
		//Step 3 take action
		if(Arr_CallBack[TIMER0_OVF_INT_ID] != NULL)
		Arr_CallBack[TIMER0_OVF_INT_ID]();
	}
}
ISR(TIMER0_CMP_vect)
{
	if(Arr_CallBack[TIMER0_CMP_INT_ID] != NULL)
	Arr_CallBack[TIMER0_CMP_INT_ID]();
}

