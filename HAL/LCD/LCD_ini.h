/*
 * LCD_ini.h
 *
 *  Created on: Feb 5, 2023
 *      Author: dell
 */

#ifndef LCD_LCD_INI_H_
#define LCD_LCD_INI_H_

void H_LCD_Void_Init(void);
void H_LCD_Void_sendData(u8 copy_u8Data);
void H_LCD_Void_sendCommand(u8 copy_u8Command);
void H_LCD_Void_sendString(const u8 * pstr);
void H_LCD_Void_clear(void);
void H_LCD_Void_sendIntNum(s32 copy_s32Num );
void H_LCD_Void_gotXY(u8 copy_u8Row , u8 copy_u8Col);
void H_LCD_Void_creatCustomChar(const u8 * arrPattern , u8 copy_u8CharCode);
void H_LCD_Void_displayCustomChar(u8 copy_u8CharCode);


#endif /* LCD_LCD_INI_H_ */
