/*
 * module name: 		DIO
 * file name: 			dio.h
 * file description :   contain prototypes of module
 * Created on:          ١٧‏/٠٨‏/٢٠٢٣
 * Author: 				ASHRY
 */
#ifndef DIO_H_
#define DIO_H_
//name (*(volatile u8*)address)
//register definition
#define PORTA (*(volatile u8*)0x3B)
#define DDRA  (*(volatile u8*)0x3A)
#define PINA  (*(volatile u8*)0x39)

#define PORTB (*(volatile u8*)0x38)
#define DDRB  (*(volatile u8*)0x37)
#define PINB  (*(volatile u8*)0x36)

#define PORTC (*(volatile u8*)0x35)
#define DDRC  (*(volatile u8*)0x34)
#define PINC  (*(volatile u8*)0x33)

#define PORTD (*(volatile u8*)0x32)
#define DDRD  (*(volatile u8*)0x31)
#define PIND  (*(volatile u8*)0x30)

#define OUTPUT (u8)1
#define INPUT  (u8)0
#define HIGH   (u8)1
#define LOW	   (u8)0
#define PORT_A (u8)'A'
#define PORT_B (u8)'B'
#define PORT_C (u8)'c'
#define PORT_D (u8)'D'

void DIO_VIDSetPinDirection(u8 cpy_u8PortNumber,u8 cpy_u8PinNumber,u8 cpy_u8PinDirection);
void DIO_VIDSetPinValue(u8 cpy_u8PortNumber,u8 cpy_u8PinNumber,u8 cpy_u8PinValue);
void DIO_VIDgetPinDirection(u8 cpy_u8PortNumber,u8 cpy_u8PinNumber,u8* buf_u8value);
void DIO_VIDSetPortDirection(u8 cpy_u8PortNumber,u8 cpy_u8PortDirection);
void DIO_VIDSetPortValue(u8 cpy_u8PortNumber,u8 cpy_u8PortValue);
void DIO_VIDgetPortValue(u8 cpy_u8PortNumber,u8* buf_u8PortValue);


#endif /* DIO_H_ */
