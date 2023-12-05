/*
 * keypad.c
 *
 *  Created on: ٢٢‏/٠٨‏/٢٠٢٣
 *      Author:ASHRY
 */
#include "../../LIB/math/bitmask.h"
#include "../../LIB/math/datatypes.h"
#include "../../MCAL/dio/dio.h"
#include "keypad.h"
#include "avr/delay.h"
void HKEYPAD_vidinit()
{
	DIO_VIDSetPortDirection(PORT_NUM,0x0F);
	DIO_VIDSetPortValue(PORT_NUM,0x7F);
}
u8 HKEYPAD_u8getPressedValue(){
	u8 key ='+';
	u8 keys[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
	u8 i , j;
	for( i=0; i<4; i++){
		DIO_VIDSetPinValue(PORT_NUM,i,LOW);
		for(j=4; j<7; j++){
			u8 buffer=0;
			DIO_VIDgetPinDirection(PORT_NUM,j,&buffer);
			if(buffer!=1){
				key = keys[i][j-4];
			}
			_delay_ms(20);
		}

		DIO_VIDSetPinValue(PORT_NUM,i,HIGH);
	}
	return key;
}
u8 HKEYPAD_u8getCharecterValue(){
	u8 key =  '+';
	u8 bufferData = '+';
	u8 keys[4][3]={{'a','d','g'},{'j','m','p'},{'s','v','y'},{'*','0','#'}};
	u8 i , j, k =0;
	while( key!='0' && k<3 ){
		for( i=0; i<4; i++){
			DIO_VIDSetPinValue(PORT_NUM,i,LOW);
			for(j=4; j<7; j++){
				u8 buffer=0;
				DIO_VIDgetPinDirection(PORT_NUM,j,&buffer);
				if(buffer!=1){
					key = keys[i][j-4];
					if(bufferData == '+'){
						bufferData = keys[i][j-4];
					}

					if( key==bufferData ){
						k++;
					}else if( (key != bufferData) && key !='0'){
						k=1;
						bufferData = key;
					}

					if(bufferData=='y' && k==3){
						return '\b';
					}
					if (key=='*' || key == '#'){
						return key;
					}
				}
				_delay_ms(20);
			}
			DIO_VIDSetPinValue(PORT_NUM,i,HIGH);
		}
	}

	return ((bufferData+k-1)>='a' && (bufferData+k-1)<='z')?(bufferData+k-1):'+';

}
