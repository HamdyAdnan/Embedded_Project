/*
 * DC_ini.h
 *
 *  Created on: Feb 23, 2023
 *      Author: dell
 */

#ifndef DC_MOTOR_DC_INI_H_
#define DC_MOTOR_DC_INI_H_

#define DC_STOP              1
#define DC_HALF_SPEED        2
#define DC_FULL_SPEED        3

void H_DC_void_Init(void);
void H_DC_void_Control(u8 copy_u8Speed);
#endif /* DC_MOTOR_DC_INI_H_ */
