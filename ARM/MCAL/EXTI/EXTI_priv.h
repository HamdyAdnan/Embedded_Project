/*
 * EXTI_priv.h
 *
 *  Created on: Mar 6, 2023
 *      Author: dell
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

typedef struct
{
	volatile	u32			IMR;
	volatile	u32			EMR;
	volatile	u32			RSTR;
	volatile	u32			FSTR;
	volatile	u32			SWIER;
	volatile	u32			PR;
}EXTI_Type;

#define 	EXTI			((EXTI_Type*)0x40010400)

//EXTI Interrupt Lines
#define EXTI0_ID                0
#define EXTI1_ID                1
#define EXTI2_ID                2
#endif /* EXTI_PRIV_H_ */
