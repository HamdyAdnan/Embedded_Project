/*
 * SPI_priv.h
 *
 *  Created on: Mar 14, 2023
 *      Author: dell
 */

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

typedef struct
{
	u32				SPI_CR1;
	u32				SPI_CR2;
	u32				SPI_SR;
	u32				SPI_DR;
	u32				SPI_CRCPR;
	u32				SPI_RXCRCR;
	u32				SPI_TXCRCR;
	u32				SPI_I2SCFGR;
	u32				SPI_I2SPR;

}SPI_Type;

#define SPI			((SPI_Type*)0x40013000 )

#endif /* SPI_PRIV_H_ */
