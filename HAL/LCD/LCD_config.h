/*
 * LCD_config.h
 *
 *  Created on: Feb 5, 2023
 *      Author: dell
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

/*
 * choose LCD_MODE :
 * LCD_4BIT_MODE_
 * LCD_8BIT_MODE_
 */
#define LCD_MODE  LCD_4BIT_MODE_

/*
 * Choose Control pins
 * RS   ,    EN
 */

#define LCD_RS_PORT    PORTA_ID
#define LCD_RS_PIN     PIN1_ID

#define LCD_EN_PORT    PORTA_ID
#define LCD_EN_PIN     PIN2_ID

/*
 * Choose Data pins
 */

#define LCD_D7_PORT    PORTA_ID
#define LCD_D7_PIN     PIN6_ID

#define LCD_D6_PORT    PORTA_ID
#define LCD_D6_PIN     PIN5_ID

#define LCD_D5_PORT    PORTA_ID
#define LCD_D5_PIN     PIN4_ID

#define LCD_D4_PORT	   PORTA_ID
#define LCD_D4_PIN     PIN3_ID

#if(LCD_MODE == LCD_8BIT_MODE_)
#define LCD_D3_PORT    PORTA_ID
#define LCD_D3_PIN     PIN2_ID

#define LCD_D2_PORT    PORTA_ID
#define LCD_D2_PIN     PIN1_ID

#define LCD_D1_PORT    PORTA_ID
#define LCD_D1_PIN     PIN0_ID

#define LCD_D0_PORT    PORTA_ID
#define LCD_D0_PIN     PIN0_ID
#endif

/*choose
 * LCD_8BIT_MODE_2LINES_5X7
 * LCD_4BIT_MODE_2LINES_5X7
 */

#define FUNCTION_SET   LCD_4BIT_MODE_2LINES_5X7

#endif /* LCD_LCD_CONFIG_H_ */
