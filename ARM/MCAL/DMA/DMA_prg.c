/*
 * DMA_prg.c
 *
 *  Created on: Mar 8, 2023
 *      Author: dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DMA_priv.h"
#include "DMA_config.h"
#include "DMA_init.h"

void M_DMA1_void_ChannelInit(void)
{
	/*
	 * 1 - Memory to Memory
	 * 2 - Priority very high
	 * 3 - Source and Destination size = 32 bit
	 * 4 - MINC & PINC Active
	 * 5 - No Circular
	 * 6 - Direction Memory to Memory
	 * 7 - Transfer complete Interrupt
	 * 8 - Disable the channel
	 */
	DMA1 -> Channel[0].CCR = 0x00007AC2;
}
void M_DMA1_void_ChannelStart(u32 *copy_u32SrcAdd , u32 *copy_u32DesAdd , u16 copy_u16BlockLen)
{
	 /*  Disable the channel	*/
	CLR_BIT((DMA1 -> Channel[0].CCR) , 0);
	DMA1 -> Channel[0].CPAR = copy_u32SrcAdd;
	DMA1 -> Channel[0].CMAR = copy_u32DesAdd;
	DMA1 -> Channel[0].CNDTR = copy_u16BlockLen;

	/*  Enable the channel	*/
	SET_BIT((DMA1 -> Channel[0].CCR) , 0);
}
