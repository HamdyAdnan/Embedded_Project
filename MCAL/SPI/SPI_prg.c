/*
 * SPI_prg.c
 *
 *  Created on: Feb 20, 2023
 *      Author: dell
 */
#include "avr/interrupt.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_priv.h"
#include "SPI_config.h"
#include "SPI_ini.h"
#include "Dio_priv.h"
#include "Dio_ini.h"

static void (*SPI_CallBack) (void) = NULL;
void M_SPI_void_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
DDR_SPI = (1<<DD_MOSI) | (1<<DD_SCK) | (1<<DD_SS);
/* Enable SPI, Master, set clock rate fck/16 */
SPCR_REG = (1<<SPE_BIT)|(1<<MSTR_BIT)|(1<<SPR0_BIT);
}

void M_SPI_void_MasterTransmit(u8 cData)
{
/* Start transmission */
SPDR_REG = cData;
/* Wait for transmission complete */
while(!(SPSR_REG & (1<<SPIF_BIT)))
;
}

void M_SPI_void_SlaveInit(void)
{
/* Set MISO output, all others input */
DDR_SPI = (1<<DD_MISO);
/* Enable SPI */
SPCR_REG = (1<<SPE_BIT);
}

u8 M_SPI_void_SlaveReceive(void)
{
/* Wait for reception complete */
while(!(SPSR_REG & (1<<SPIF_BIT)))
;
/* Return data register */
return SPDR_REG;
}

void M_SPI_void_EnableInterrupt(void)
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
}
