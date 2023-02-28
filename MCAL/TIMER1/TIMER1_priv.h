/*
 * TIMER1_priv.h
 *
 *  Created on: Feb 14, 2023
 *      Author: dell
 */

#ifndef TIMER1_TIMER1_PRIV_H_
#define TIMER1_TIMER1_PRIV_H_

#define TCCR1A_REG           (*((volatile u8*)0x4F))
#define TCCR1B_REG           (*((volatile u8*)0x4E))

#define ICR_REG              (*((volatile u16*)0x46))

#define TIMSK_REG            ((*(volatile u8 *)0x59))    //PIE

//TCCR1A_REG
#define WGM10_BIT            0
#define WGM11_BIT            1

//TCCR1B_REG
//Prescaler BITS
#define CS10_BIT             0
#define CS11_BIT             1
#define CS12_BIT             2

//Mode BITS
#define WGM12_BIT            3
#define WGM13_BIT            4

//ICU BITS
#define ICES1_BIT            6
#define ICEC1_BIT            7

//TIMSK_REG
#define TICIE1_BIT           5

#endif /* TIMER1_TIMER1_PRIV_H_ */
