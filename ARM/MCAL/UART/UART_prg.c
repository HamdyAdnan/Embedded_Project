/*
 * UART_prg.c
 *
 *  Created on: Mar 13, 2023
 *      Author: dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART_init.h"
void M_UART_void_Init(void)
{
	/*	Baudrate 	9600					*/
	USART -> USART_BRR = 0x341 ;
	SET_BIT((USART -> USART_CR1) , 2);
	SET_BIT((USART -> USART_CR1) , 3);
	SET_BIT((USART -> USART_CR1) , 13);			//Set enable UART Bit
	USART -> USART_SR = 0;
#if(USART_DATA_SIZE == USART_SIZE8)
	CLR_BIT((USART -> USART_CR1) , 12);
#elif(USART_DATA_SIZE == USART_SIZE9)
	SET_BIT((USART -> USART_CR1) , 12);
#else
	#error "WRONG INPUT"
#endif

#if(USART_PARITY_CONTROL == USART_PARITY_DISABLE)
	CLR_BIT((USART -> USART_CR1) , 10);
#elif(USART_PARITY_CONTROL == USART_PARITY_ENABLE)
	SET_BIT((USART -> USART_CR1) , 10);
#else
	#error "WRONG INPUT"
#endif

#if(USART_PARITY_MODE == USART_PARITY_EVEN)
	CLR_BIT((USART -> USART_CR1) , 9);
#elif(USART_PARITY_MODE == USART_PARITY_ODD)
	SET_BIT((USART -> USART_CR1) , 9);
#else
	#error "WRONG INPUT"
#endif

}

void M_UART_void_sendByte(u8 Byte)
{
	USART -> USART_DR = Byte;
	while((GET_BIT(USART -> USART_SR , 6))== 0);
}
u8 M_UART_u8_recieveByte(u8 *Byte)
{
	u8 Local_u8Data = 0;
	while((GET_BIT(USART -> USART_SR , 5))== 0);
	Local_u8Data = USART -> USART_DR;
	return Local_u8Data;
}

void M_UART_void_sendString(const u8 *ptr)
{
	u8 i = 0;

	while(ptr[i] != '\0')
	{
		M_UART_void_sendByte(ptr[i]);
		i++;
	}
}

void M_UART_void_recieveString(u8 *ptr)
{
	u8 i = 0 ;

	M_UART_u8_recieveByte(&ptr[i]) ;

	while(ptr[i] != '#')
	{
		i++ ;
		M_UART_u8_recieveByte(&ptr[i]) ;
	}

	ptr[i] = '\0' ;
}
