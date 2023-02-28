/*
 * LCD_priv.h
 *
 *  Created on: Feb 5, 2023
 *      Author: dell
 */

#ifndef LCD_LCD_PRIV_H_
#define LCD_LCD_PRIV_H_

/***********************************************/
/****************PRIVITE MACROS*****************/
/***********************************************/
#define LCD_4BIT_MODE_    0
#define LCD_8BIT_MODE_    1


#define LCD_8BIT_MODE_2LINES_5X7        0x38   //(0b00111000)

#define LCD_4BIT_MODE_2LINES_5X7        0x28   //(0b00111000)

#define LCD_CLEAR_DISPLAY               0x01   //(0b00000001)

#define LCD_DISPLAYON_CURSON_BLINKOFF   0x0E

#define LCD_ENTRY_MODE_SET              0x06   // Increment position & Disable shift

#define LCD_SET_R0C0                    0x80   //Command to set address to row 0 col 0
#define LCD_SET_R1C0                    0xC0   //Command to set address to row 1 col 1


/***********************************************************/
/****************PRIVITE FUNCTION PROTOTYPE*****************/
/***********************************************************/
static void H_LCD_Void_writeNlatch(u8 copy_u8Byte);

#endif /* LCD_LCD_PRIV_H_ */
