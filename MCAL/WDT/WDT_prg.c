/*
 * WDT_prg.c
 *
 *  Created on: Feb 15, 2023
 *      Author: dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_priv.h"
#include "WDT_config.h"
#include "WDT_ini.h"

void M_WDT_void_enable(void)                     //Turn On Watchdog
{
	SET_BIT(WDTCR_REG , WDE_BIT);
}
void M_WDT_void_disable(void)                    //Turn On Watchdog
{
	/* Write logical one to WDTOE and WDE */
	WDTCR_REG |= (1<<WDTOE_BIT) | (1<<WDE_BIT);
	/* Turn off WDT */
	WDTCR_REG = 0x00;

	/*SET_BIT(WDTCR_REG , WDE_BIT);
	SET_BIT(WDTCR_REG , WDTOE_BIT);
	CLR_BIT(WDTCR_REG , WDE_BIT);*/
}
void M_WDT_void_sleep(u8 copy_timeOut)           //timeout
{
	if(copy_timeOut >= WDT_TIMEOUT_16_3_MS && copy_timeOut <= WDT_TIMEOUT_2_1_S)
	{
	//Step 1 Apply mask
	WDTCR_REG &= WDT_PRESCALER_MASK;
	//Step 2 Insert Value
	WDTCR_REG |= copy_timeOut;
	}
}
void M_WDT_void_refresh(void)
{
	asm("WDR");
}
