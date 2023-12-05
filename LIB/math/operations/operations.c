/*
 * operation.c
 *
 *  Created on: ٢٢‏/٠٨‏/٢٠٢٣
 *      Author: ASHRY
 */
#include "../datatypes.h"
#include "operations.h"
void reverseNumber(s32 value,u32 digitsWithZeros , s32*buffer){
	s32 cpy_value= value;
	u32 digitCounter= 1 ;
	while(value){
		value/=10;
		digitCounter*=10;
	}
	u32 digitDifference =digitsWithZeros/digitCounter;
	for(u32 i= 1;digitCounter>1;i*=10){
		digitCounter/=10;
		*(buffer)+= ((cpy_value/digitCounter)*i);
		cpy_value%= digitCounter;
	}
	*(buffer)*=digitDifference;
}

