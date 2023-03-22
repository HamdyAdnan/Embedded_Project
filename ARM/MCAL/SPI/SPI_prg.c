/*
 * SPI_prg.c
 *
 *  Created on: Mar 14, 2023
 *      Author: dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_init.h"
#include "SPI_priv.h"
#include "SPI_config.h"
#include "SPI_init.h"

static void (*SPI_CallBack) (void) = NULL;
void M_SPI_void_MasterInit(void)
{
	SPI -> SPI_CR1 = 0x0347;
// Set MOSI and SCK output, all others input
// Enable SPI, Master, set clock rate fck/2

}

void M_SPI_void_MasterTransmit(u8 cData)
{
	M_GPIO_void_SetPinValue(PORTA_ID, PIN0_ID, LOW);
	/* Start transmission */
	SPI -> SPI_DR = cData;
	/* Wait for transmission complete */
	while(GET_BIT((SPI -> SPI_SR) , 1) == 0);
	M_GPIO_void_SetPinValue(PORTA_ID, PIN0_ID, HIGH);
}

void M_SPI_void_SlaveInit(void)
{
	SPI -> SPI_CR1 =0x0343;
}

void M_SPI_void_SlaveReceive(u8 *copy_u8Byte)
{
	// Wait for reception complete
	while(GET_BIT((SPI -> SPI_SR) , 0) == 0);
	// Return data register
	*copy_u8Byte = SPI -> SPI_DR;
}
/*u8 M_SPI_void_SlaveReceive(void)
{
	// Wait for reception complete
	while(GET_BIT((SPI -> SPI_SR) , 0) == 0);
	// Return data register
	return SPI -> SPI_DR;
}*/

/*void M_SPI_void_EnableInterrupt(void)
{
	SREG_REG |= 1 << 7;
	SPCR_REG |= (1 << SPE_BIT) | (1 << SPIE_BIT);
}

void M_SPI_void_setCallBack(void (*ptrfn)(void))
{
    if(ptrfn != NULL)
    {
    	SPI_CallBack = ptrfn;
    }
}


ISR(SPI_STC_vect)
{
    if(SPI_CallBack != NULL)
    {
    	SPI_CallBack();
    }
}*/
