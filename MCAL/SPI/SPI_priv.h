/*
 * SPI_priv.h
 *
 *  Created on: Feb 20, 2023
 *      Author: dell
 */

#ifndef SPI_SPI_PRIV_H_
#define SPI_SPI_PRIV_H_

#define SPCR_REG        (*((volatile u8*)0x2D))
#define SPSR_REG        (*((volatile u8*)0x2E))
#define SPDR_REG        (*((volatile u8*)0x2F))
#define SREG_REG        (*((volatile u8*)0x5F))

/*SPSR_REG Bits
 *
 */
#define SPIF_BIT        7
/*SPCR_REG Bits
 *
 */
#define  SPE_BIT        6
#define  MSTR_BIT       4
#define  SPR0_BIT       0
#define  SPIE_BIT       7

#define  DDR_SPI        DDRB_REG
#define  DD_SS          PIN4_ID
#define  DD_MOSI        PIN5_ID
#define  DD_MISO        PIN6_ID
#define  DD_SCK         PIN7_ID

#endif /* SPI_SPI_PRIV_H_ */
