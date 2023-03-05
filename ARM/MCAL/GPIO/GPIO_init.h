/*
 * GPIO_init.h
 *
 *  Created on: Mar 1, 2023
 *      Author: dell
 */

#ifndef GPIO_GPIO_INIT_H_
#define GPIO_GPIO_INIT_H_

#define LOW                 0
#define HIGH                1

#define PORTA_ID                 0
#define PORTB_ID                 1
#define PORTC_ID                 2

#define PIN0_ID                  0
#define PIN1_ID                  1
#define PIN2_ID                  2
#define PIN3_ID                  3
#define PIN4_ID                  4
#define PIN5_ID                  5
#define PIN6_ID                  6
#define PIN7_ID                  7
#define PIN8_ID                  8
#define PIN9_ID                  9
#define PIN10_ID                 10
#define PIN11_ID                 11
#define PIN12_ID                 12
#define PIN13_ID                 13
#define PIN14_ID                 14
#define PIN15_ID                 15

void M_GPIO_void_SetPinDir(u8 PortID , u8 PinID , u8 Dir);
void M_GPIO_void_SetPinValue(u8 PortID , u8 PinID , u8 Value);
void M_GPIO_void_GetPinValue(u8 PortID , u8 PinID , u8 *Value);

#define IN_ANALOG                0b0000
#define IN_FLOATING              0b0100
#define IN_PULL_UP_DOWN          0b1000

#define OUT_10MHZ_PP             0b0001
#define OUT_10MHZ_OD             0b0101
#define OUT_10MHZ_AF_PP          0b1001
#define OUT_10MHZ_AF_PP          0b1101

#define OUT_20MHZ_PP             0b0010
#define OUT_20MHZ_OD             0b0110
#define OUT_20MHZ_AF_PP          0b1010
#define OUT_20MHZ_AF_PP          0b1110

#define OUT_50MHZ_PP             0b0011
#define OUT_50MHZ_OD             0b0111
#define OUT_50MHZ_AF_PP          0b1011
#define OUT_50MHZ_AF_PP          0b1111

#endif /* GPIO_GPIO_INIT_H_ */
