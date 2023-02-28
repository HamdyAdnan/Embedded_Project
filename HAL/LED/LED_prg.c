#include "STD_TYPES.h"
#include "Dio_ini.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "LED_ini.h"


void H_Led_Void_ledInit(u8 LedID)
{
	switch(LedID)
	{
	case RED_LED :
		M_Dio_Void_setPinDir(LED_RED_PORT, LED_RED_PIN, OUTPUT );
		break;
	case GRN_LED :
		M_Dio_Void_setPinDir(LED_GRN_PORT, LED_GRN_PIN, OUTPUT );
		break;
	case BLU_LED :
		M_Dio_Void_setPinDir(LED_GRN_PORT, LED_GRN_PIN, OUTPUT );
		break;
	}
}
void H_Led_Void_ledSetON(u8 LedID)
{
	switch(LedID)
	{
	case RED_LED :
#if(LED_RED_DIR	== LED_FORWARD)
		M_Dio_Void_setPinValue(LED_RED_PORT, LED_RED_PIN, HIGH );
#elif(LED_RED_DIR == LED_REVERSE)
		M_Dio_Void_setPinValue(LED_RED_PORT, LED_RED_PIN, LOW );
#endif
		break;
	case GRN_LED :
#if(LED_GRN_DIR	== LED_FORWARD)
		M_Dio_Void_setPinValue(LED_GRN_PORT, LED_GRN_PIN, HIGH );
#elif(LED_GRN_DIR == LED_REVERSE)
		M_Dio_Void_setPinValue(LED_GRN_PORT, LED_GRN_PIN, LOW );
#endif
		break;
	case BLU_LED :
#if(LED_BLU_DIR	== LED_FORWARD)
		M_Dio_Void_setPinValue(LED_BLU_PORT, LED_BLU_PIN, HIGH );
#elif(LED_BLU_DIR == LED_REVERSE)
		M_Dio_Void_setPinValue(LED_BLU_PORT, LED_BLU_PIN, LOW );
#endif
		break;
	}
}
void H_Led_Void_ledSetOFF(u8 LedID)
{
	switch(LedID)
	{
	case RED_LED :
#if(LED_RED_DIR	== LED_FORWARD)
		M_Dio_Void_setPinValue(LED_RED_PORT, LED_RED_PIN, LOW );
#elif(LED_RED_DIR == LED_REVERSE)
		M_Dio_Void_setPinValue(LED_RED_PORT, LED_RED_PIN, HIGH );
#endif
		break;

	case GRN_LED :
#if(LED_GRN_DIR	== LED_FORWARD)
		M_Dio_Void_setPinValue(LED_GRN_PORT, LED_GRN_PIN, LOW );
#elif(LED_GRN_DIR == LED_REVERSE)
		M_Dio_Void_setPinValue(LED_GRN_PORT, LED_GRN_PIN, HIGH );
#endif
		break;
#if(LED_BLU_DIR	== LED_FORWARD)
	case BLU_LED :
		M_Dio_Void_setPinValue(LED_BLU_PORT, LED_BLU_PIN, LOW );
#elif(LED_BLU_DIR == LED_REVERSE)
		M_Dio_Void_setPinValue(LED_BLU_PORT, LED_BLU_PIN, HIGH );
#endif
		break;
	}
}
void H_Led_Void_ledToggle(u8 LedID)
{
	switch(LedID)
	{
	case RED_LED :
		M_Dio_Void_togPin(LED_RED_PORT, LED_RED_PIN);
		break;
	case GRN_LED :
		M_Dio_Void_togPin(LED_GRN_PORT, LED_GRN_PIN);
		break;
	case BLU_LED :
		M_Dio_Void_togPin(LED_GRN_PORT, LED_GRN_PIN);
		break;
	}
}
