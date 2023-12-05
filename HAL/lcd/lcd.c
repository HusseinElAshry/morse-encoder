
/*
 * lcd.c
 *
 *  Created on: ٢٠‏/٠٨‏/٢٠٢٣
 *      Author: ASHRY
 */
#include "avr/delay.h"
#include "../../LIB/math/bitmask.h"
#include "../../LIB/math/datatypes.h"
#include "../../MCAL/dio/dio.h"
#include "lcd.h"

/*to initialize LCD turn port DDR as output and follow instructions specified in data sheet  */
void HCLCD_vidInit(){
	DIO_VIDSetPinDirection(CONTROL_PORT,RS_PIN,HIGH);
	DIO_VIDSetPinDirection(CONTROL_PORT,RW_PIN,HIGH);
	DIO_VIDSetPinDirection(CONTROL_PORT,EN_PIN,HIGH);
	DIO_VIDSetPortDirection(DATA_PORT,0xff);

	_delay_ms(30);
	HCLCD_vidSendCommand(0b00111000);
	_delay_ms(1);
	HCLCD_vidSendCommand(0b00001110);
	_delay_ms(1);
	HCLCD_vidSendCommand(0b00000001);
	_delay_ms(2);
	HCLCD_vidSendCommand(0b00000110);
	_delay_ms(1);


}
/*to send command write at IR RW must be low and RW must be low*/
void HCLCD_vidSendCommand(u8 cpy_u8Command){
	DIO_VIDSetPinValue(CONTROL_PORT,RS_PIN,LOW);
	DIO_VIDSetPinValue(CONTROL_PORT,RW_PIN,LOW);
	DIO_VIDSetPortValue(DATA_PORT, cpy_u8Command);
	DIO_VIDSetPinValue(CONTROL_PORT,EN_PIN,HIGH);
	_delay_ms(1);
	DIO_VIDSetPinValue(CONTROL_PORT,EN_PIN,LOW);
	_delay_ms(1);

}
void HCLCD_vidSendData(u8 cpy_u8Data){
	DIO_VIDSetPinValue(CONTROL_PORT,RS_PIN,HIGH);
	DIO_VIDSetPortValue(DATA_PORT, cpy_u8Data);
	DIO_VIDSetPinValue(CONTROL_PORT,EN_PIN,HIGH);
	_delay_ms(1);
	DIO_VIDSetPinValue(CONTROL_PORT,EN_PIN,LOW);
	_delay_ms(1);

}
void HCLCD_vidSendString(const u8* add_pu8String){
	for(u8 i = 0;add_pu8String[i];i++){
		if(i==SCREEN_WIDTH){
			HCLCD_vidGoTo(0,1);
		}
		HCLCD_vidSendData(*(add_pu8String+i));
	}
}
void HCLCD_vidSendNumber(s32 cpy_s32Number){
	if(!cpy_s32Number){
		HCLCD_vidSendData('0');
	}else if(cpy_s32Number<0){
		HCLCD_vidSendData('-');
		cpy_s32Number *=-1;
	}
	u32 counter=1;
	s32 numValue = cpy_s32Number;
	while(cpy_s32Number){
		cpy_s32Number= cpy_s32Number/10;
		counter= counter*10;
	}
	while(counter>1){
		counter= counter/10;
		HCLCD_vidSendData((numValue/counter)+'0');
		numValue%=counter;
	}
}
/*with 3 digit after floated point*/
void HCLCD_vidSendFloat(f32 cpy_f32Float){
	HCLCD_vidSendNumber((s32)cpy_f32Float);
	cpy_f32Float-=(s32)cpy_f32Float;
	HCLCD_vidSendData('.');
	u32 counter = 0;
	while(  counter<PERCISION ){
		cpy_f32Float =(cpy_f32Float*10);
		HCLCD_vidSendData('0'+(u8)cpy_f32Float);
		cpy_f32Float -= (s32)cpy_f32Float;
		counter++;
	}
}
void HCLCD_vidGoTo(u8 cpy_u8X, u8 cpy_u8Y){
	setBit(cpy_u8X,7);
	if(cpy_u8Y!=0){
		setBit(cpy_u8X,6);
	}
	HCLCD_vidSendCommand(cpy_u8X);
}
void HCLCD_vidClear(){
	HCLCD_vidSendCommand(0x01);
	_delay_ms(2);
}
void HCLCD_vidSendSpecialChar(const u8* arr_u8Char, u8 cpy_u8BlockNumber){
	HCLCD_vidSendCommand(0x40+(cpy_u8BlockNumber*8));
	for(u8 i=0;i<8;i++)
	{
     	 HCLCD_vidSendData(arr_u8Char[i]);
	}
	HCLCD_vidSendCommand(0x80);
	HCLCD_vidSendCommand(0b00000010);



}
