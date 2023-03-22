/*
 * STK_init.h
 *
 *  Created on: Mar 6, 2023
 *      Author: dell
 */

#ifndef STK_INIT_H_
#define STK_INIT_H_

void M_STK_void_Init(void);
void M_STK_void_BusyWait(u32 copy_u32Ticks);
void M_STK_void_SetIntervalSingle(u32 copy_u32Ticks , void (*pf)(void));
void M_STK_void_SetStopInterval(void);
u32 M_STK_u32_GetElapsedTime(void);
u32 M_STK_u32_GetRemainingTime(void);

#endif /* STK_INIT_H_ */
