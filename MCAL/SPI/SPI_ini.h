/*
 * SPI_ini.h
 *
 *  Created on: Feb 20, 2023
 *      Author: dell
 */

#ifndef SPI_SPI_INI_H_
#define SPI_SPI_INI_H_

void M_SPI_void_MasterInit(void);
void M_SPI_void_MasterTransmit(u8 cData);
void M_SPI_void_SlaveInit(void);
u8 M_SPI_void_SlaveReceive(void);
void M_SPI_void_setCallBack(void (*ptrfn) (void));
void M_SPI_void_EnableInterrupt(void);


#endif /* SPI_SPI_INI_H_ */
