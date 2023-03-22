/*
 * UART_init.h
 *
 *  Created on: Mar 13, 2023
 *      Author: dell
 */

#ifndef UART_INIT_H_
#define UART_INIT_H_

void M_UART_void_Init(void);
void M_UART_void_sendByte(u8 Byte);
u8 M_UART_u8_recieveByte(u8 *Byte);
void M_UART_void_sendString(const u8 *ptr);
void M_UART_void_recieveString(u8 *ptr);

void M_UART_void_EnableInt(void);
void M_UART_void_DisableInt(void);
void M_UART_void_setCallBack(void);

#endif /* UART_INIT_H_ */
