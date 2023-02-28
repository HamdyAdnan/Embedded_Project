/*
 * LCD_prg.c
 *
 *  Created on: Feb 5, 2023
 *      Author: dell
 *      */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_ini.h"

#include "LCD_priv.h"
#include "LCD_config.h"
#include "LCD_ini.h"

void H_LCD_Void_Init(void)
{
	//Set Direction RS,EN
	M_Dio_Void_setPinDir(LCD_RS_PORT, LCD_RS_PIN , OUTPUT);
	M_Dio_Void_setPinDir(LCD_EN_PORT, LCD_EN_PIN , OUTPUT);
	//Set Direction D4...D7
	M_Dio_Void_setPinDir(LCD_D4_PORT, LCD_D4_PIN , OUTPUT);
	M_Dio_Void_setPinDir(LCD_D5_PORT, LCD_D5_PIN , OUTPUT);
	M_Dio_Void_setPinDir(LCD_D6_PORT, LCD_D6_PIN , OUTPUT);
	M_Dio_Void_setPinDir(LCD_D7_PORT, LCD_D7_PIN , OUTPUT);
#if(LCD_MODE == LCD_8BIT_MODE_)
	//set Dir from D3...D0
	M_Dio_Void_setPinDir(LCD_D3_PORT, LCD_D3_PIN , OUTPUT);
	M_Dio_Void_setPinDir(LCD_D2_PORT, LCD_D2_PIN , OUTPUT);
	M_Dio_Void_setPinDir(LCD_D1_PORT, LCD_D1_PIN , OUTPUT);
	M_Dio_Void_setPinDir(LCD_D0_PORT, LCD_D0_PIN , OUTPUT);
#endif
	//Send init Sequence
#if(LCD_MODE == LCD_8BIT_MODE_)
	_delay_ms(35);
	H_LCD_Void_sendCommand(LCD_8BIT_MODE_2LINES_5X7);
#elif(LCD_MODE == LCD_4BIT_MODE_)
	_delay_ms(35);
	//RS = Command = 0
	M_Dio_Void_setPinValue(LCD_RS_PORT, LCD_RS_PIN, LOW);
	//EN = 0 disable
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
	//prepare data
	M_Dio_Void_setPinValue(LCD_D7_PORT, LCD_D7_PIN, 0);
	M_Dio_Void_setPinValue(LCD_D6_PORT, LCD_D6_PIN, 0);
	M_Dio_Void_setPinValue(LCD_D5_PORT, LCD_D5_PIN, 1);
	M_Dio_Void_setPinValue(LCD_D4_PORT, LCD_D4_PIN, 0);
	//EN = 1
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	//delay 1 msec (to allow latching)
	_delay_ms(1);
	//EN = 0
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
	//delay to allow processing
	_delay_ms(5);
	H_LCD_Void_sendCommand(LCD_4BIT_MODE_2LINES_5X7);
#else
	#error("Wrong LCD Mode")
#endif
	//Display ON/OFF
	H_LCD_Void_sendCommand(LCD_DISPLAYON_CURSON_BLINKOFF);
	//Display Clear
	H_LCD_Void_sendCommand(LCD_CLEAR_DISPLAY);
	//Entry Mode set
	H_LCD_Void_sendCommand(LCD_ENTRY_MODE_SET);

}
void H_LCD_Void_sendData(u8 copy_u8Data)
{
	//step1 : RS = 1 to be in Data Mode
	M_Dio_Void_setPinValue(LCD_RS_PORT, LCD_RS_PIN, HIGH);
	//step2 : Write Data
	H_LCD_Void_writeNlatch(copy_u8Data);
}
void H_LCD_Void_sendCommand(u8 copy_u8Command)
{
	//step1 : RS = 0 to be in Command Mode
	M_Dio_Void_setPinValue(LCD_RS_PORT, LCD_RS_PIN, LOW);
	//step2 : Write Command
	H_LCD_Void_writeNlatch(copy_u8Command);
}
void H_LCD_Void_sendString(const u8 * pstr)
{
	while(*pstr)
	{
		H_LCD_Void_sendData(*pstr);
		pstr++;
	}
}
void H_LCD_Void_clear(void)
{
	H_LCD_Void_sendCommand(LCD_CLEAR_DISPLAY);
}
void H_LCD_Void_sendIntNum(s32 copy_s32Num )
{
	s8 i=0;
	s8 Loc_Arr[10]={0};
	if(copy_s32Num == 0)
	{
		H_LCD_Void_sendData('0');
	}
	else if(copy_s32Num < 0)
	{
		H_LCD_Void_sendData('-');
		copy_s32Num *= -1;
	}
	while (copy_s32Num != 0)
	{
		Loc_Arr[i] = copy_s32Num %10;
		copy_s32Num = copy_s32Num / 10;
		i++;
	}
	i--;
	while(i >= 0)
	{
		H_LCD_Void_sendData(Loc_Arr[i] + '0');

		i--;
	}
}
void H_LCD_Void_gotXY(u8 copy_u8Row , u8 copy_u8Col)
{
	if(copy_u8Row == 0 || copy_u8Row == 1)
	{
		if(copy_u8Col >= 0 && copy_u8Col <= 15)
		{
			switch(copy_u8Row)
			{
			case 0 :
				H_LCD_Void_sendCommand(LCD_SET_R0C0 + copy_u8Col);
				break;
			case 1 :
				H_LCD_Void_sendCommand(LCD_SET_R1C0 + copy_u8Col);
				break;
			}
		}
	}
}
void H_LCD_Void_creatCustomChar(const u8 * arrPattern , u8 copy_u8CharCode)
{
	u8 Character1[8] = { 0x00, 0x00, 0x08, 0x04, 0x02, 0x1F, 0x00, 0x00 };
	u8 Character2[8] = { 0x00, 0x00, 0x0E, 0x11, 0x11, 0x08, 0x0E, 0x00 };
	u8 Character3[8] = { 0x00, 0x04, 0x04, 0x0C, 0x0F, 0x1F, 0x00, 0x00 };
	u8 Character4[8] = { 0x00, 0x00, 0x06, 0x08, 0x0E, 0x01, 0x1E, 0x00 };
}
void H_LCD_Void_displayCustomChar(u8 copy_u8CharCode)
{

}
static void H_LCD_Void_writeNlatch(u8 copy_u8Byte)
{
#if(LCD_MODE == LCD_8BIT_MODE_)
	//EN = 0 disable
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
	//Step 1 : prepare data DB7...DB0
	M_Dio_Void_setPinValue(LCD_D0_PORT, LCD_D0_PIN, GET_BIT(copy_u8Byte, 0));
	M_Dio_Void_setPinValue(LCD_D1_PORT, LCD_D1_PIN, GET_BIT(copy_u8Byte, 1));
	M_Dio_Void_setPinValue(LCD_D2_PORT, LCD_D2_PIN, GET_BIT(copy_u8Byte, 2));
	M_Dio_Void_setPinValue(LCD_D3_PORT, LCD_D3_PIN, GET_BIT(copy_u8Byte, 3));
	M_Dio_Void_setPinValue(LCD_D4_PORT, LCD_D4_PIN, GET_BIT(copy_u8Byte, 4));
	M_Dio_Void_setPinValue(LCD_D5_PORT, LCD_D5_PIN, GET_BIT(copy_u8Byte, 5));
	M_Dio_Void_setPinValue(LCD_D6_PORT, LCD_D6_PIN, GET_BIT(copy_u8Byte, 6));
	M_Dio_Void_setPinValue(LCD_D7_PORT, LCD_D7_PIN, GET_BIT(copy_u8Byte, 7));
	//Step 2 : Active Enable (E = 1)
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	//Step 3 : Delay for 1 second to allow latching
	_delay_ms(1);
	//Step 4 : Deactivate Enable (E = 0)
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
	//Step 5 : Delay to allow LCD to process
	_delay_ms(5);

#elif(LCD_MODE == LCD_4BIT_MODE_)
	//EN = 0 disable
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
	//Divide Byte to 2 (4 bits)
	//Step 1 : prepare data (DB7...DB4)
	M_Dio_Void_setPinValue(LCD_D4_PORT, LCD_D4_PIN, GET_BIT(copy_u8Byte, 4));
	M_Dio_Void_setPinValue(LCD_D5_PORT, LCD_D5_PIN, GET_BIT(copy_u8Byte, 5));
	M_Dio_Void_setPinValue(LCD_D6_PORT, LCD_D6_PIN, GET_BIT(copy_u8Byte, 6));
	M_Dio_Void_setPinValue(LCD_D7_PORT, LCD_D7_PIN, GET_BIT(copy_u8Byte, 7));

	//Step 2 : Active Enable (E = 1)
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	//Step 3 : Delay for 1 second to allow latching
	_delay_ms(1);
	//Step 4 : Deactivate Enable (E = 0)
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
	//Step 5 : Delay to allow LCD to process
	_delay_ms(5);
	//Step 6 : Send Low Order
	M_Dio_Void_setPinValue(LCD_D4_PORT, LCD_D4_PIN, GET_BIT(copy_u8Byte, 0));
	M_Dio_Void_setPinValue(LCD_D5_PORT, LCD_D5_PIN, GET_BIT(copy_u8Byte, 1));
	M_Dio_Void_setPinValue(LCD_D6_PORT, LCD_D6_PIN, GET_BIT(copy_u8Byte, 2));
	M_Dio_Void_setPinValue(LCD_D7_PORT, LCD_D7_PIN, GET_BIT(copy_u8Byte, 3));

	//Step 2 : Active Enable (E = 1)
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	//Step 3 : Delay for 1 second to allow latching
	_delay_ms(1);
	//Step 4 : Deactivate Enable (E = 0)
	M_Dio_Void_setPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
	//Step 5 : Delay to allow LCD to process
	_delay_ms(5);

#else
	#error("Wrong LCD Mode")
#endif
}
