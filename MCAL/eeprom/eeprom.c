/*
 * eeprom.c
 *
 *  Created on: ٠٨‏/٠٩‏/٢٠٢٣
 *      Author: ASHRY
 */
#include "../../LIB/math/datatypes.h"
#include "../../LIB/math/bitmask.h"
#include "avr/delay.h"
#include "./eeprom.h"

void MC_EEPROM_vidWrite(u16 address , u8 data){
	while(EECR & (1<<EECR_EEWE));
	EEARL = (address & 0x00FF);
	EEARH = (address & 0x0300)>>8;
	EEDR  =	data;
	EECR =(1<<EECR_EEMWE);
	EECR =(1<<EECR_EEWE);

}
void MC_EEPROM_vidWriteString(u16 address ,u8*data ){
	u8 i= 0;
	while(data[i]){
		MC_EEPROM_vidWrite( (address+i) , data[i]);
		i++;
	}
}
void  MC_EEPROM_vidRead(u16 address,u8 size,u8 *dataPtr){
	u8 counter = 0;
	while( counter<size  && dataPtr[counter-1] != 0xff){
		dataPtr[counter] = MC_EEPROM_u8Read(  (address+counter) );
		counter++;
	}
	dataPtr[--counter] = '\0';
}
u8   MC_EEPROM_u8Read(u16 address){
	while(EECR & (1<<EECR_EEWE));
	u8 data;
	EEARL = (address & 0x00FF);
	EEARH = (address & 0x0300)>>8;
	EECR  |= 1<< EECR_EERE;
	data = EEDR;
	return data;
}
void MC_EEPROM_RESET(){
	u16 i =0;
	while(i<1024){
		MC_EEPROM_vidWrite(i,0xff);
		i++;
	}
}
