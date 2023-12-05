/*
 * util.c
 *
 *  Created on: ٠٩‏/٠٩‏/٢٠٢٣
 *      Author: ASHRY
 */
#include "../../LIB/math/datatypes.h"
#include "util.h"
u8 util_u8StringCompare(u8 string1[] , u8 string2[]){
	u8 counter = 0;
	while(string1[counter] == string2[counter]){
		if(string1[counter]=='\0' || string2[counter]=='\0'){
			break;
		}
		counter++;
	}
	if(string1[counter]=='\0' && string2[counter]=='\0'){
		return 1;
	}else{
		return 0;
	}
}
