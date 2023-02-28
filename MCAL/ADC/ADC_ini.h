/*
 * ADC_ini.h
 *
 *  Created on: Feb 16, 2023
 *      Author: dell
 */

#ifndef ADC_ADC_INI_H_
#define ADC_ADC_INI_H_

typedef enum{
		prescaler_2 = 1,             //1
		prescaler_4,                 //2
		prescaler_8,                 //3
		prescaler_16,                //4
		prescaler_32,                //5
		prescaler_64,                //6
		prescaler_128                //7
}prescaler_t;

typedef enum{
	vref_AREF,
	vref_AVCC,
	vref_Internal =3                 //2.56Volt
}vref_t;

typedef enum{
	channel_0,                       //temperature sensor
	channel_1,                       //Smoke sensor
	channel_2,
	channel_3,
	channel_4,
	channel_5,
	channel_6,
	channel_7
}channel_t;

void M_ADC_void_Init(prescaler_t copy_prescaler , vref_t copy_vref);
u16 M_ADC_u16_ADCRead(channel_t copy_channel);
void M_ADC_CallBack(void (*ptr_fun)(void));

#endif /* ADC_ADC_INI_H_ */
