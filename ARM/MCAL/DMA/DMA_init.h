/*
 * DMA_init.h
 *
 *  Created on: Mar 8, 2023
 *      Author: dell
 */

#ifndef DMA_INIT_H_
#define DMA_INIT_H_

void M_DMA1_void_ChannelInit(void);
void M_DMA1_void_ChannelStart(u32 *copy_u32SrcAdd , u32 *copy_u32DesAdd , u16 copy_u16BlockLen);

#endif /* DMA_INIT_H_ */
