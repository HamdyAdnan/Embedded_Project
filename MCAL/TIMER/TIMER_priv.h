/*
 * TIMER_priv.h
 *
 *  Created on: Feb 8, 2023
 *      Author: dell
 */

#ifndef TIMER_TIMER_PRIV_H_
#define TIMER_TIMER_PRIV_H_

//Timer Register

#define TCNT0_REG             ((*(volatile u8 *)0x52))    //counter register
#define OCR0_REG              ((*(volatile u8 *)0x5C))    //compare match register
#define TCCR0_REG             ((*(volatile u8 *)0x53))    //control register

#define TIMSK_REG             ((*(volatile u8 *)0x59))    //PIE
#define TIFR_REG              ((*(volatile u8 *)0x58))    //flags
//Register Bit
//TCCR0_REG
#define WGM01_BIT                3
#define WGM00_BIT                6

//TIMSK_REG
#define TOIE0_BIT                0            //Overflow Interrupt Enable
#define OCIE0_BIT                1            //Compare match Interrupt Enable

#define TIMER0_PRESCALER_MASK    0b11111000   //0xF8
#define TIMER0_OC0_MASK          0b11001111   //0xCF
#define TIMER0_OC0_SHIF          4

//Timer modes
#define TIMER0_NORMAL_MODE                  0
#define TIMER0_CTC_MODE                     1
#define TIMER0_FAST_PWM_MODE                2
#define TIMER0_PHASECORRECT_MODE            3

//prescaler options
#define TIMER0_PRESCALER_NO_CLK             0
#define TIMER0_PRESCALER_NO_PRESCALER       1   //001
#define TIMER0_PRESCALER_8                  2   //010
#define TIMER0_PRESCALER_64                 3   //011
#define TIMER0_PRESCALER_256                4   //100
#define TIMER0_PRESCALER_1024               5   //101
#define TIMER0_PRESCALER_EXTCLK_FALL_EDGE   6   //110
#define TIMER0_PRESCALER_EXTCLK_RAIS_EDGE   7   //111


//OC0 pin mode option for non PWM
#define TIMER0_OC0_MODE_DISCONNECTED        0
#define TIMER0_OC0_MODE_TOGGLE              1
#define TIMER0_OC0_MODE_CLEAR               2
#define TIMER0_OC0_MODE_SET                 3

// OC0 pins Mode option for PWM
#define TIMER0_PWM_NON_INVERTED             0x20        //0b00100000
#define TIMER0_PWM_INVERTED                 0x30        //0b00110000

#endif /* TIMER_TIMER_PRIV_H_ */
