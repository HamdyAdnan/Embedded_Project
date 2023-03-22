/*
 * STK_priv.h
 *
 *  Created on: Mar 6, 2023
 *      Author: dell
 */

#ifndef STK_PRIV_H_
#define STK_PRIV_H_

typedef struct
{
	volatile	u32			CTRL;
	volatile	u32			LOAD;
	volatile	u32			VAL;
	volatile	u32			CALIB;
}STK_Type;

#define		STK_AHB_DIV_8            0
#define		STK_AHB                  1

#define 	STK_SINGLE_INTERVAL		 2
#define 	STK_PERIODIC_INTERVAL		 4

#define 	STK			((STK_Type*)0xE000E010)

#endif /* STK_PRIV_H_ */
