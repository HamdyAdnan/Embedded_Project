/*
 * ADC_prg.c
 *
 *  Created on: Feb 16, 2023
 *      Author: dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_ini.h"


/*u16 volatile Glob_u16ADCReading = 0;
void (* ptr_callback)(void) = NULL;
void M_ADC_void_Init(prescaler_t copy_prescaler , vref_t copy_vref)
{
	// Set Prescaler
	ADCSRA_REG &= ADC_PRESCALER_MASK;
	ADCSRA_REG |= copy_prescaler;
	/*
	// disable Interrupt
	CLR_BIT(ADCSRA_REG, ADIE_BIT);
	*/
	// Enable Interrupt
	//SET_BIT(ADCSRA_REG, ADIE_BIT);

	// Config Right Adjust
	//CLR_BIT(ADMUX_REG, ADLAR_BIT);

	/*
	// disable auto trigger
	SET_BIT(ADCSRA_REG, ADATE_BIT);
	*/
/*
	// Enable auto trigger
	SET_BIT(ADCSRA_REG, ADATE_BIT);

	// Select Reference
	ADMUX_REG &= ADC_VREF_MASK;
	ADMUX_REG |= copy_vref << ADC_VREF_SHIFT;

	// Enable ADC
	SET_BIT(ADCSRA_REG , ADEN_BIT);

	// Start Conversion
	ADCSRA_REG |=1 << ADSC_BIT;
}
u16 M_ADC_u16_ADCRead(channel_t copy_channel)
{
	u16 Local_u16Reading = 0;
	// Select Channel
	ADMUX_REG &= ADC_MUX_MASK;
	ADMUX_REG |= ADC_CHANNEL;
	// Start Conversion
	ADCSRA_REG |=1 << ADSC_BIT;
	// polling wait until conversion is done
	while(GET_BIT(ADCSRA_REG, ADSC_BIT) == 1);
	// return data
	return ADC_REG;
}
void M_ADC_CallBack(void (*ptr_fun)(void))
{
	if(ptr_fun != NULL)
	{
		ptr_callback = ptr_fun;
	}
}

ISR(ADC_vect)
{
	Glob_u16ADCReading = ADC_REG;
	if(ptr_callback != NULL)
	{
		ptr_callback();
	}
}
*/
u16 gADC_value = 0;
void (* ptr_callback)(void) = NULL;

void M_ADC_void_Init(prescaler_t copy_prescaler ,vref_t  copy_vref )
{
  // step 1 : config prescaler
    // step : apply mask
	ADCSRA_REG &= ADC_PRESCALER_MASK;

	// step :insert value
	ADCSRA_REG |=  copy_prescaler;

  // step 3 : config right adjust
    CLR_BIT(ADMUX_REG,ADLAR_BIT);

#if (ADC_TYPE == ADC_POLLING)
    //step 2 : Disable Interrupt
    	CLR_BIT(ADCSRA_REG,ADIE_BIT);
    // step 4 : disable auto trigger
    CLR_BIT(ADCSRA_REG , ADATE_BIT);
#elif (ADC_TYPE == ADC_INT)
    // step 4 : Enable auto trigger
    SET_BIT(ADCSRA_REG,ADATE_BIT);
    //(start conversion )
    SET_BIT(ADCSRA_REG , ADSC_BIT);
    SET_BIT(ADCSRA_REG,3);// Interrupt Enable
#endif
  // step 5 : chose vref
	// step : apply mask
    ADMUX_REG &= ADC_VREF_MASK;
	// step :insert value
    ADMUX_REG |= copy_vref << ADC_VREF_SHIFT;
  // step 6 : Enable ADC
    SET_BIT(ADCSRA_REG , ADEN_BIT);
}
#if (ADC_TYPE == ADC_POLLING)
u16 M_ADC_u16_ADCRead(channel_t copy_channel )
{

	// step 1 : config channel
	     // step : apply mask
	     ADMUX_REG  &= ADC_CHANNEL_MASK;
		// step :insert value
	     ADMUX_REG  |= copy_channel;
	// step 2 : for single Conversion (start conversion )
      SET_BIT(ADCSRA_REG , ADSC_BIT);
	// step 3 : polling wait until conversion is done
      while((GET_BIT(ADCSRA_REG , ADIF_BIT))== 0);
    //  while(SET_BIT(ADCSRA_REG , ADSC_BIT)== 0);
     // SET_BIT(ADCSRA_REG , ADIF_BIT);
	// step 4 : return digital value
    return ADC_REG;
}
#elif  (ADC_TYPE == ADC_INT)

   void M_ADC_CallBack(void (*ptr_fun)(void))
   {
   	if(ptr_fun != NULL)
   	{
   		ptr_callback = ptr_fun;
   	}
   }

   ISR(ADC_vect)
   {
	   gADC_value = ADC_REG;
	   if(ptr_callback != NULL)
   	{
   		ptr_callback();
   	}
   }
#endif
