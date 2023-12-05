/*
 * module name: 		DIO
 * file name: 			dio.c
 * file description :   contain implementation of module
 * Created on:          ١٧‏/٠٨‏/٢٠٢٣
 * Author: 				ASHRY
 */
#include "../../LIB/math/bitmask.h"
#include "../../LIB/math/datatypes.h"
#include "./dio.h"
void DIO_VIDSetPinDirection(u8 cpy_u8PortNumber,u8 cpy_u8PinNumber,u8 cpy_u8PinDirection){
	switch(cpy_u8PinDirection){
	case OUTPUT:
		switch (cpy_u8PortNumber){
		case PORT_A:
			setBit(DDRA,cpy_u8PinNumber);
			break;
		case PORT_B:
			setBit(DDRB,cpy_u8PinNumber);
			break;
		case PORT_C:
			setBit(DDRC,cpy_u8PinNumber);
			break;
		case PORT_D:
			setBit(DDRD,cpy_u8PinNumber);
			break;
		default:
			break;
		}
		break;
		case INPUT:
			switch (cpy_u8PortNumber){
			case PORT_A:
				clearBit(DDRA,cpy_u8PinNumber);
				break;
			case PORT_B:
				clearBit(DDRB,cpy_u8PinNumber);
				break;
			case PORT_C:
				clearBit(DDRC,cpy_u8PinNumber);
				break;
			case PORT_D:
				clearBit(DDRD,cpy_u8PinNumber);
				break;
			default:
				break;
			}
			break;
			default:
				break;
	}
}
void DIO_VIDSetPinValue(u8 cpy_u8PortNumber,u8 cpy_u8PinNumber,u8 cpy_u8PinValue){
	switch(cpy_u8PinValue){
	case HIGH :
		switch (cpy_u8PortNumber){
		case PORT_A:
			setBit(PORTA,cpy_u8PinNumber);
			break;
		case PORT_B:
			setBit(PORTB,cpy_u8PinNumber);
			break;
		case PORT_C:
			setBit(PORTC,cpy_u8PinNumber);
			break;
		case PORT_D:
			setBit(PORTD,cpy_u8PinNumber);
			break;
		default:
			break;
		}
		break;
		case LOW :
			switch (cpy_u8PortNumber){
			case PORT_A:
				clearBit(PORTA,cpy_u8PinNumber);
				break;
			case PORT_B:
				clearBit(PORTB,cpy_u8PinNumber);
				break;
			case PORT_C:
				clearBit(PORTC,cpy_u8PinNumber);
				break;
			case PORT_D:
				clearBit(PORTD,cpy_u8PinNumber);
				break;
			default:
				break;
			}
			break;
			default :
				break;

	}
}
void DIO_VIDgetPinDirection(u8 cpy_u8PortNumber,u8 cpy_u8PinNumber,u8* buf_u8value){
	switch (cpy_u8PortNumber){
	case PORT_A:
		*buf_u8value = getBit(PINA,cpy_u8PinNumber);
		break;
	case PORT_B:
		*buf_u8value = getBit(PINB,cpy_u8PinNumber);
		break;
	case PORT_C:
		*buf_u8value = getBit(PINC,cpy_u8PinNumber);
		break;
	case PORT_D:
		*buf_u8value = getBit(PINA,cpy_u8PinNumber);
		break;
	default:
		break;
	}
}
void DIO_VIDSetPortDirection(u8 cpy_u8PortNumber,u8 cpy_u8PortDirection){
	switch (cpy_u8PortNumber){
	case PORT_A:
		DDRA = cpy_u8PortDirection;
		break;
	case PORT_B:
		DDRB = cpy_u8PortDirection;
		break;
	case PORT_C:
		DDRC = cpy_u8PortDirection;
		break;
	case PORT_D:
		DDRD = cpy_u8PortDirection;
		break;
	default:
		break;
	}
}
void DIO_VIDSetPortValue(u8 cpy_u8PortNumber,u8 cpy_u8PortValue){
	switch (cpy_u8PortNumber){
	case PORT_A:
		PORTA = cpy_u8PortValue;
		break;
	case PORT_B:
		PORTB = cpy_u8PortValue;
		break;
	case PORT_C:
		PORTC = cpy_u8PortValue;
		break;
	case PORT_D:
		PORTD = cpy_u8PortValue;
		break;
	default:
		break;
	}
}
void DIO_VIDgetPortValue(u8 cpy_u8PortNumber,u8* buf_u8PortValue){
	switch (cpy_u8PortNumber){
	case PORT_A:
		*buf_u8PortValue = PINA;
		break;
	case PORT_B:
		*buf_u8PortValue = PINB;
		break;
	case PORT_C:
		*buf_u8PortValue = PINC;
		break;
	case PORT_D:
		*buf_u8PortValue = PIND;
		break;
	default:
		break;
	}
}
