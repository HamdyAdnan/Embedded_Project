/*
 * ADC_priv.h
 *
 *  Created on: Mar 9, 2023
 *      Author: dell
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

typedef struct
{
	u32			ADC_SR;
	u32 		ADC_CR1;
	u32 		ADC_CR2;
	u32 		ADC_SMPR1;
	u32 		ADC_SMPR2;
	u32 		ADC_JOFR1;
	u32 		ADC_JOFR2;
	u32 		ADC_JOFR3;
	u32 		ADC_JOFR4;
	u32 		ADC_HTR;
	u32			ADC_LTR;
	u32			ADC_SQR1;
	u32			ADC_SQR2;
	u32			ADC_SQR3;
	u32			ADC_JSQR;
	u32			ADC_JDR1;
	u32			ADC_JDR2;
	u32			ADC_JDR3;
	u32			ADC_JDR4;
	u32			ADC_DR;

}ADC_Types;

#define 	ADC1			((ADC_Types*)0x40010400)

#endif /* ADC_PRIV_H_ */
