/*
 * transmiter.c
 *
 *  Created on: ٣٠‏/١١‏/٢٠٢٣
 *      Author: ASHRY
 */
#include "../../../LIB/math/datatypes.h"
#include "../../../HAL/lcd/lcd.h"
#include "../../../HAL/keypad/keypad.h"
#include "../../../MCAL/dio/dio.h"
#include "stdlib.h"
#include "avr/delay.h"
#include "./transmiter.h"
u8* pattern = NULL;
void vid_displayHome(){
	HCLCD_vidGoTo(5,0);
	HCLCD_vidSendString("select");
	HCLCD_vidGoTo(0,1);
	HCLCD_vidSendString("*number#charcter");
	u8 letter = '+';
	while(letter != '*' && letter!='#'){
		letter = HKEYPAD_u8getPressedValue();
	}
	HCLCD_vidClear();
	switch (letter){
		case '#':
			vid_transmitCharcters();
			break;
		case '*':
			vid_transmitNumbers();
			break;
	}
}
void vid_initProgram(){
		HCLCD_vidInit();
		HKEYPAD_vidinit();
		DIO_VIDSetPinDirection(PORT_D,0,OUTPUT);
		pattern = malloc(5*sizeof(u8));
}
void vid_convertToSignal(u8*pattern){
	for(u8 i = 0; pattern[i]; i++){
		if(pattern[i]=='.'){
			DIO_VIDSetPinValue(PORT_D,0,HIGH);
			_delay_ms(400);
		}else if(pattern[i] == '-'){
			DIO_VIDSetPinValue(PORT_D,0,HIGH);
			_delay_ms(800);
		}
		DIO_VIDSetPinValue(PORT_D,0,LOW);
		_delay_ms(200);
	}
}
void vid_transmitCharcters(){
	u8 letter = '+';
	while(1){
		while(letter =='+'){
			letter = HKEYPAD_u8getCharecterValue();
		}
		HCLCD_vidClear();
		HCLCD_vidGoTo(0,0);
		HCLCD_vidSendData(letter-0x20);
		u8 conversionState = convertToMorse(pattern,letter);
		if(conversionState == CONVERTED){
			HCLCD_vidGoTo(0,1);
			HCLCD_vidSendString(pattern);
			vid_convertToSignal(pattern);
			letter = '+';
		}else{
			vid_handle_NonConverted(&letter);
		}

	}
}
void vid_transmitNumbers(){
	u8 letter = '+';
	while(1){
		while(letter =='+'){
			letter = HKEYPAD_u8getPressedValue();
		}
		HCLCD_vidClear();
		HCLCD_vidGoTo(0,0);
		HCLCD_vidSendData(letter);
		u8 conversionState = convertToMorse(pattern,letter);
		if(conversionState == CONVERTED){
			HCLCD_vidGoTo(0,1);
			HCLCD_vidSendString(pattern);
			vid_convertToSignal(pattern);
			letter = '+';
		}else{
			vid_handle_NonConverted(&letter);
		}

	}
}
void vid_handle_NonConverted(u8*ptrToLetter){
	HCLCD_vidClear();
	if(*ptrToLetter == '*'){
		vid_displayHome();
	}
	*ptrToLetter = '+';
}
CONVERSION_STATE convertToMorse(u8*pattern,u8 character){
	u8* encoded = NULL;
	encoded = malloc(5*sizeof(u8));
	switch (character){
		case 'a':
			encoded = ".-";
			break;
		case 'b':
			encoded = "-...";
			break;
		case 'c':
			encoded = "-.-.";
			break;
		case 'd':
			encoded = "-..";
			break;
		case 'e':
			encoded = ".";
			break;
		case 'f':
			encoded = "..-.";
			break;
		case 'g':
			encoded = "--.";
			break;
		case 'h':
			encoded = "....";
			break;
		case 'i':
			encoded = "..";
			break;
		case 'j':
			encoded = ".---";
			break;
		case 'k':
			encoded = "-.-";
			break;
		case 'l':
			encoded = ".-..";
			break;
		case 'm':
			encoded = "--";
			break;
		case 'n':
			encoded = "-.";
			break;
		case 'o':
			encoded = "---";
			break;
		case 'p':
			encoded = ".--.";
			break;
		case 'q':
			encoded = "--.-";
			break;
		case 'r':
			encoded = ".-.";
			break;
		case 's':
			encoded = "...";
			break;
		case 't':
			encoded = "-";
			break;
		case 'u':
			encoded = "..-";
			break;
		case 'v':
			encoded = "...-";
			break;
		case 'w':
			encoded = ".--";
			break;
		case 'x':
			encoded = "-..-";
			break;
		case 'y':
			encoded = "-.--";
			break;
		case 'z':
			encoded = "--..";
			break;
		case '0':
			encoded = "-----";
			break;
		case '1':
			encoded = ".----";
			break;
		case '2':
			encoded = "..---";
			break;
		case '3':
			encoded = "...--";
			break;
		case '4':
			encoded = "....-";
			break;
		case '5':
			encoded = ".....";
			break;
		case '6':
			encoded = "-....";
			break;
		case '7':
			encoded = "--...";
			break;
		case '8':
			encoded = "---..";
			break;
		case '9':
			encoded = "----.";
			break;
		default:
			return NON_CONVERTED;
			break;

	}
	u8 i =0;
	for(;encoded[i];i++){
		*(pattern+i) = *(encoded+i);
	}
	*(pattern+i) = '\0';
	encoded = NULL;
	return CONVERTED;
}
