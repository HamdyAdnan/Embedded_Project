/*
 * LM35_prg.c
 *
 *  Created on: Feb 16, 2023
 *      Author: dell
 */


#include "STD_TYPES.h"
#include "Dio_ini.h"
#include "ADC_ini.h"
#include "LM35_priv.h"
#include "LM35_config.h"
#include "LM35_ini.h"

void H_TEMPSENSOR_void_Init()
{
   //set direction of temp Sensor channel  pin as input
	M_Dio_Void_setPinDir(PORTA_ID, TEMP_SENSOR_CHANNEL, INPUT);
	// ADC init
	M_ADC_void_Init(prescaler_128 , vref_AVCC);
}

u8   H_TEMPSENSOR_u8_readTemp()
{
	// step 1 : call adc to convert (read digital value)
	u16 adc_read = M_ADC_u16_ADCRead(TEMP_SENSOR_CHANNEL);
	// step 2: convert digital value to analog
    u32 read_mv =   ( (u32)adc_read * TEMP_VREF)/ TEMP_RES;
    //step 3 : convert from mv to degree C
    u8 temp =  read_mv / 10;
    //step 4 : return temp
    return temp;
}

