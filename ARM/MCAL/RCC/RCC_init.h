/*
 * RCC_init.h
 *
 *  Created on: Feb 28, 2023
 *      Author: dell
 */

#ifndef RCC_RCC_INIT_H_
#define RCC_RCC_INIT_H_

#define RCC_AHB                   0
#define RCC_APB1                  1
#define RCC_APB2                  2

void M_RCC_void_SysClkInit(void);
void M_RCC_void_EnablePerClk(u8 copy_u8PerBus , u8 copy_u8PerNum);
void M_RCC_void_DisablePerClk(u8 copy_u8PerBus , u8 copy_u8PerNum);


#endif /* RCC_RCC_INIT_H_ */
