/*
 * ADC_prg.c
 *
 *  Created on: Jan 8, 2015
 *      Author: DELL
 */
#include "avr/interrupt.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_pvt.h"
#include "ADC_config.h"
#include "ADC_int.h"

volatile u16 Glob_u16ADCReading = 0;
void (* ptr_callback)(void);
void M_ADC_void_init		(prescaler_t Copy_enuPrescaler , vref_t Copy_enuRefVoltage)
{
	// Set Prescaler
	ADCSRA_REG &= ADC_PRESCALER_MASK;
	ADCSRA_REG |= Copy_enuPrescaler;
	/*
	// disable Interrupt
	CLR_BIT(ADCSRA_REG, ADC_ADCSRA_ADIE_BIT);
	*/
	// Enable Interrupt
	SET_BIT(ADCSRA_REG, ADC_ADCSRA_ADIE_BIT);

	// Config Right Adjust
	CLR_BIT(ADMUX_REG, ADC_ADMUX_ADLAR_BIT);

	/*
	// disable auto trigger
	SET_BIT(ADCSRA_REG, ADC_ADCSRA_ADATE_BIT);
	*/

	// Enable auto trigger
	SET_BIT(ADCSRA_REG, ADC_ADCSRA_ADATE_BIT);

	// Select Reference
	ADMUX_REG &= ADC_VREFF_MASK;
	ADMUX_REG |= Copy_enuRefVoltage << ADC_VREFF_SHIFT;

	// Enable ADC
	SET_BIT(ADCSRA_REG , ADC_ADCSRA_ADEN_BIT);

	// Start Conversion
	ADCSRA_REG |=1 << ADC_ADCSRA_ADSC_BIT;
}
u16 M_ADC_void_read			(channel_t   Copy_enuChannel)
{
	u16 Local_u16Reading = 0;
	// Select Channel
	ADMUX_REG &= ADC_MUX_MASK;
	ADMUX_REG |= ADC_CHANNEL;
	// Start Conversion
	ADCSRA_REG |=1 << ADC_ADCSRA_ADSC_BIT;
	// polling wait until conversion is done
	while(GET_BIT(ADCSRA_REG, ADC_ADCSRA_ADSC_BIT) == 1);
	// return data
	return ADCL_REG;
}
void M_ADC_CallBack			(void (*ptr_fun)(void))
{
	if(ptr_fun != NULL)
	{
		ptr_callback = ptr_fun;
	}
}

ISR(ADC_vect)
{
	Glob_u16ADCReading = ADCL_REG;
	if(ptr_callback != NULL)
	{
		ptr_callback();
	}
}

/*
void M_ADC_void_init		(void)
{
	// Select Reference
	ADMUX_REG &= 0b00111111;
	ADMUX_REG |= 1<<ADC_ADMUX_REFS0_BIT;
	// Select Channel
	ADMUX_REG &= ADC_MUX_MASK;
	ADMUX_REG |= ADC_CHANNEL;
	// Set Prescaler
	ADCSRA_REG &= ADC_PRESCALER_MASK;
	ADCSRA_REG |= ADC_PRESCALER;
	// Enable ADC
	SET_BIT(ADCSRA_REG , ADC_ADCSRA_ADEN_BIT);
}
void M_ADC_void_read		(u16 * Copy_pu16Value)
{
	// Start Conversion
	ADCSRA_REG |=1 << ADC_ADCSRA_ADSC_BIT;
	// Stay until the End of Conversion
	while(GET_BIT(ADCSRA_REG, ADC_ADCSRA_ADSC_BIT) == 1);
	* Copy_pu16Value = ADCL_REG;
}
*/

