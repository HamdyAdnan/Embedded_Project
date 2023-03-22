/*
 * EXTI_init.h
 *
 *  Created on: Mar 6, 2023
 *      Author: dell
 */

#ifndef EXTI_INIT_H_
#define EXTI_INIT_H_

void M_EXTI_void_Init(void);
void M_EXTI_void_EnableLine(u8 copy_u8ExtiLine);
void M_EXTI_void_DisableLine(u8 copy_u8ExtiLine);
void M_EXTI_void_SetExtiEdge(u8 copy_u8ExtiLine , u8 copy_u8ExtiEdge);
void M_EXTI_voidSetCallBack(void (*Pf) (void) , u8 copy_u8ExtiLine);

#define EXTI_NONE              0
#define EXTI_RISING            1
#define EXTI_FALLING           2
#define EXTI_IOC               3

#endif /* EXTI_INIT_H_ */
