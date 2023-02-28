/*
 * TIMER1_ini.h
 *
 *  Created on: Feb 14, 2023
 *      Author: dell
 */

#ifndef TIMER1_TIMER1_INI_H_
#define TIMER1_TIMER1_INI_H_

#define TIMER1_ICU_FALL_TRIGG            0
#define TIMER1_ICU_RAISING_TRIGG            1

void M_TIMER1_void_Init(void);           //Mode = Normal , Prescaler
void M_TIMER1_ICU_void_Init(void);       //SetUp initial trigger for ICU
void M_TIMER1_ICU_void_IntEnable(void);
void M_TIMER1_ICU_void_IntDisable(void);
void M_TIMER1_ICU_void_setTrigg(u8 copy_u8Trigg );

u16 M_TIMER1_ICU_u16_takeReading(void);
void M_TIMER1_ICU_void_setCallBack(void (*ptrfn)(void));

#endif /* TIMER1_TIMER1_INI_H_ */
