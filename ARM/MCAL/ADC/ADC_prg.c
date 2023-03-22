/*
 * ADC_prg.c
 *
 *  Created on: Mar 9, 2023
 *      Author: dell
 */
#include "_delay_ms.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_init.h"

volatile u16 analog_data =0;
volatile u16 counter=0;

void (* M_ADC1_void_callback)(void);

void M_ADC_void_Init(void)
{
	// ON ADC -> ADON -> 1
	SET_BIT(ADC1->ADC_CR2 , 0);
	_delay_ms(20);

	// Set External event select for regular group -> SWSTART -> 111
	SET_BIT(ADC1->ADC_CR2 , 19);
	SET_BIT(ADC1->ADC_CR2 , 17);
	SET_BIT(ADC1->ADC_CR2 , 18);

	// Set External trigger conversion mode for regular channels
	SET_BIT(ADC1->ADC_CR2 , 20);
	// Set  Data alignment -> Right Alignment -> ALIGN > 0
	CLR_BIT(ADC1->ADC_CR2 , 11);
	// Set Single conversion mode -> CONT -> 0
	CLR_BIT(ADC1->ADC_CR2 , 1);
	// Set Channel x Sample time selection -> Default -> 1.5 Cycle

	// Set Number of Conversion in Regular Mode -> Default -> 1


	// Start Calibration -> CAL -> 1
	SET_BIT(ADC1 -> ADC_CR2 , 2);
	while(GET_BIT(ADC1->ADC_CR2 , 2) != 0);
}

u16	M_ADC_u16_read	(Channel_ID Copy_enuChannel)
{
	u32 Local_u32Reading;
	// Set Channel
	if(Copy_enuChannel <= CHANNEL_9)
	{

		//ADC->SQR3 &= 0xfffffff0; // Clear 0 -> 4 bits
		//ADC->SQR3 |= Copy_enuChannel;
		CLR_BIT(ADC1->ADC_SQR3 , 0);
		CLR_BIT(ADC1->ADC_SQR3 , 1);
		CLR_BIT(ADC1->ADC_SQR3 , 2);
		CLR_BIT(ADC1->ADC_SQR3 , 3);
		CLR_BIT(ADC1->ADC_SQR3 , 4);

	}

	// Start conversion of regular channels -> SWSTART -> 1
	SET_BIT(ADC1->ADC_CR2 , 22);
	// Wait until the end of conversion -> SWSTART -> 0
	//while(GET_BIT(ADC->CR2 , 22) == 1);

	while(GET_BIT(ADC1->ADC_SR , 1) != 1);

/*
	// Start conversion of regular channels -> SWSTART -> 1
	SET_BIT(ADC->CR2 , 0);
	// Wait until the end of conversion -> SWSTART -> 0
	while(GET_BIT(ADC->SR , 1) != 1);
*/
	// Get data -> 0 -> 15
//	Local_u32Reading = (ADC->DR) & 0x0000ffff;
	// Return Data
	return ADC1->ADC_DR;
}

void ADC1_2_IRQHandler(void)
{


		//check if the End of conversion is completed
		if (ADC1->ADC_SR & (1<<1))
		{
			analog_data = ADC1->ADC_DR ;
		//	ADC1->ADC_SR &=~(1<<1);
		//	ADC1->ADC_CR2 |=(1<<22); /*Start conversion of regular channels*/

		}

		else
		{
			//counter--;
			//conversion not happened
		}


		counter++;
	//MADC1_callback();


}

//take care if there is an interrupt fired after firing ADC_handeler callback will jump to garbage location
// so itis recomendded to make call_back function before initialization in main()

void M_ADC1_void_set_callback(void (*ptr) (void))
{

 M_ADC1_void_callback = ptr;

}



u16 M_ADC1_u16_getdata(void)
{

	return analog_data;
}

