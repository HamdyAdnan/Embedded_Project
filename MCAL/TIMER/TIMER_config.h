/*
 * TIMER_config.h
 *
 *  Created on: Feb 8, 2023
 *      Author: dell
 */

#ifndef TIMER_TIMER_CONFIG_H_
#define TIMER_TIMER_CONFIG_H_

/*Please Choose from :
 * TIMER0_NORMAL_MODE
 * TIMER0_CTC_MODE
 * TIMER0_FAST_PWM_MODE
 * TIMER0_PHASECORRECT_MODE
 */
#define TIMER0_MODE         TIMER0_FAST_PWM_MODE
/*
 * Please Choose prescaler
 * TIMER0_PRESCALER_NO_CLC
 * TIMER0_PRESCALER_NO_PRESCALER
 * TIMER0_PRESCALER_8
 * TIMER0_PRESCALER_64
 * TIMER0_PRESCALER_256
 * TIMER0_PRESCALER_1024
 * TIMER0_PRESCALER_EXTCLK_FALL_EDGE
 * TIMER0_PRESCALER_EXTCLK_RAIS_EDGE
 */
#define TIMER0_PRESCALER    TIMER0_PRESCALER_1024

/*
 * Please Choose OC0 pin mode :
 * for no PWM :
 * TIMER0_OC0_MODE_DISCONNECTED
 * TIMER0_OC0_MODE_TOGGLE
 * TIMER0_OC0_MODE_CLEAR
 * TIMER0_OC0_MODE_SET
 *
 * for PWM :
 *TIMER0_PWM_NON_INVERTED
 *TIMER0_PWM_INVERTED
 */

#define TIMER0_OC0_MODE     TIMER0_PWM_NON_INVERTED

#define FCPU                16

#endif /* TIMER_TIMER_CONFIG_H_ */
