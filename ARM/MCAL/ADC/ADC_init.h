/*
 * ADC_init.h
 *
 *  Created on: Mar 9, 2023
 *      Author: dell
 */

#ifndef ADC_INIT_H_
#define ADC_INIT_H_

typedef enum
{
	CHANNEL_0,
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3,
	CHANNEL_4,
	CHANNEL_5,
	CHANNEL_6,
	CHANNEL_7,
	CHANNEL_8,
	CHANNEL_9
}Channel_ID;


void M_ADC_void_Init(void);
u16	M_ADC_u16_read	(Channel_ID Copy_enuChannel);

#endif /* ADC_INIT_H_ */
