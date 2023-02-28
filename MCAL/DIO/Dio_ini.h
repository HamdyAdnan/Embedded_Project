#ifndef DIO_DIO_INI_H_
#define DIO_DIO_INI_H_

#define PORTA_ID 1
#define PORTB_ID 2
#define PORTC_ID 3
#define PORTD_ID 4

#define INPUT    0
#define OUTPUT   1

#define PIN0_ID  0
#define PIN1_ID  1
#define PIN2_ID  2
#define PIN3_ID  3
#define PIN4_ID  4
#define PIN5_ID  5
#define PIN6_ID  6
#define PIN7_ID  7

#define LOW      0
#define HIGH     1

void M_Dio_Void_setPinDir(u8 port, u8 pin, u8 dir );
void M_Dio_Void_setPinValue(u8 port, u8 pin, u8 value );
void M_Dio_Void_getPin(u8 port, u8 pin, u8 *pvalue );
void M_Dio_Void_togPin(u8 port, u8 pin);
void M_Dio_Void_setPortValue(u8 port, u8 value);
void M_Dio_Void_getPortValue(u8 port, u8 *pvalue);
#endif  /*DIO_DIO_INI_H_*/
