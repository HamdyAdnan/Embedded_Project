/*
 * UART_priv.h
 *
 *  Created on: Mar 13, 2023
 *      Author: dell
 */

#ifndef UART_PRIV_H_
#define UART_PRIV_H_

typedef struct
{
	u32				USART_SR;
	u32				USART_DR;
	u32				USART_BRR;
	u32				USART_CR1;
	u32				USART_CR2;
	u32				USART_CR3;
	u32				USART_GTPR;
}USART_Type;

#define USART		((USART_Type*)0x40013800)

#define USART_SIZE8             0
#define USART_SIZE9             1

#define USART_PARITY_DISABLE    0
#define USART_PARITY_ENABLE     1

#define USART_PARITY_EVEN       0
#define USART_PARITY_ODD        1

#endif /* UART_PRIV_H_ */
