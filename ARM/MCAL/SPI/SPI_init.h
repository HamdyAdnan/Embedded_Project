/*
 * SPI_init.h
 *
 *  Created on: Mar 14, 2023
 *      Author: dell
 */

#ifndef SPI_INIT_H_
#define SPI_INIT_H_

void M_SPI_void_MasterInit(void);
void M_SPI_void_MasterTransmit(u8 cData);
void M_SPI_void_SlaveInit(void);
void M_SPI_void_SlaveReceive(u8 *copy_u8Byte);
//u8 M_SPI_void_SlaveReceive(void);
void M_SPI_void_setCallBack(void (*ptrfn) (void));
void M_SPI_void_EnableInterrupt(void);

#endif /* SPI_INIT_H_ */
