/*
 * WDT_priv.h
 *
 *  Created on: Feb 15, 2023
 *      Author: dell
 */

#ifndef WDT_WDT_PRIV_H_
#define WDT_WDT_PRIV_H_

//Register
#define                     WDTCR_REG (*((volatile u8*)0x41))

//Bits
#define WDE_BIT               3          //Watchdog Enable
#define WDTOE_BIT             4          //Watchdog Turn-off Enable

//WDT Prescaler Mask
#define WDT_PRESCALER_MASK            0xF8  // 0b11111000

#endif /* WDT_WDT_PRIV_H_ */
