/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

//#include <stdint.h>
//
//#if !defined(__SOFT_FP__) && defined(__ARM_FP)
//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
//#endif
#include "_delay_ms.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_init.h"
#include "GPIO_init.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
TaskHandle_t	xPushButtonTaskHandle;
TaskHandle_t	xLedTaskHandle;

void	vPushButtonTask(void *pvParameter);
void	vLedTask(void *pvParameter);

u8 ButtonState = 1;
u8 read;

#define ForgetGiveSemaphore     pdFALSE

xSemaphoreHandle ButtonSemaphore = 0;


int main(void)
{
	M_RCC_void_SysClkInit();
	M_RCC_void_EnablePerClk(RCC_APB2, 2);
	M_GPIO_void_SetPinDir(PORTA_ID, PIN1_ID, OUT_50MHZ_PP);
	M_GPIO_void_SetPinDir(PORTA_ID, PIN0_ID, IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinValue(PORTA_ID, PIN1_ID, HIGH);

	   xTaskCreate(     vPushButtonTask , "PushButton", 128, NULL , 1 , &xPushButtonTaskHandle);
	   xTaskCreate(     vLedTask , "Led", 128, NULL , 2 , &xLedTaskHandle);
	   /*Create Semaphore for the Button */
	   vSemaphoreCreateBinary(ButtonSemaphore);
	   vTaskStartScheduler();
    /* Loop forever */
	for(;;);
}

void	vPushButtonTask(void *pvParameter)
{
	 portTickType Freq = 50;
	 portTickType Start = xTaskGetTickCount();
	for(;;)
	{
		M_GPIO_void_GetPinValue(PORTA_ID, PIN0_ID, &read);
		/* if the Push Button is Pressed */
		if(read == 1)
		{

			/* If the Resource No One is Using so Take the Semaphore  **/
			if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100))
			{
				/*Change the State */
				ButtonState = 0;

				/*Give the Semaphore */
				if (ForgetGiveSemaphore == pdFALSE)
				xSemaphoreGive(ButtonSemaphore);

			}
			else
			{
				vTaskDelay(10);
			}
		}
		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);
	}
}
void	vLedTask(void *pvParameter)
{
	portTickType Freq = 50;
	portTickType Start = xTaskGetTickCount();
	for(;;)
	{

		if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100))
		{

			if (ButtonState == 0)
			{
				M_GPIO_void_TogPin(PORTA_ID, PIN1_ID);
				ButtonState = 1;
			}
			/*Give the Semaphore */
			xSemaphoreGive(ButtonSemaphore);

		}
		else
		{
			vTaskDelay(10);
		}

		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);

	}
}
