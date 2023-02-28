/*
 * KeyPad_ini.h
 *
 *  Created on: Feb 2, 2023
 *      Author: dell
 */

#ifndef KEYPAD_KEYPAD_INI_H_
#define KEYPAD_KEYPAD_INI_H_

#define NO_PRESSED_KEY       0xFF

#define ACTRIVE_LOW_PRESSED  0

void H_KEYPAD_Void_init(void);
u8 H_KEYPAD_Void_getPressesKey(void);

#endif /* KEYPAD_KEYPAD_INI_H_ */
