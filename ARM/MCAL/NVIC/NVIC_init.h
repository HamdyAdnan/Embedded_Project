/*
 * NVIC_init.h
 *
 *  Created on: Mar 5, 2023
 *      Author: dell
 */

#ifndef NVIC_INIT_H_
#define NVIC_INIT_H_

void M_NVIC_void_Init();
void M_NVIC_void_EnableInt(u8 IntNum);
void M_NVIC_void_DisableInt(u8 IntNum);

void M_NVIC_void_SetPendingFlag(u8 IntNum);
void M_NVIC_void_ClrPendingFlag(u8 IntNum);

void M_NVIC_u8_GetActiveFlag(u8 IntNum);
void	NVIC_voidEXTI0SetCallBack(void (*Pf) (void));
void	NVIC_voidEXTI1SetCallBack(void (*Pf) (void));


#endif /* NVIC_INIT_H_ */
