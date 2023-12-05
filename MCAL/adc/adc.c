/*
 * adc.c
 *
 *  Created on: ٢٤‏/٠٨‏/٢٠٢٣
 *      Author: ASHRY
 */
#include "../../LIB/math/bitmask.h"
#include "../../LIB/math/datatypes.h"
#include "./adc.h"

void MADC_vidInit(u8 volt_reference,u8 pre_scaler){
	//1-volt reference
	switch(volt_reference){
	case AREF :
		clearBit(ADMUX,ADMUX_REFS0);
		clearBit(ADMUX,ADMUX_REFS1);
		break;
	case AVCC :
		setBit(ADMUX,ADMUX_REFS0);
		clearBit(ADMUX,ADMUX_REFS1);
		break;
	case INTERNAL :
		setBit(ADMUX,ADMUX_REFS0);
		setBit(ADMUX,ADMUX_REFS1);
		break;
	default :
		break;
	}
	//2.data direction
	clearBit(ADMUX,ADMUX_ADLAR);
	//3.set pre-scaller
	switch(pre_scaler){
		case PRE_SCALER_1 :
			clearBit(ADCSRA,ADCSRA_ADPS0);
			clearBit(ADCSRA,ADCSRA_ADPS1);
			clearBit(ADCSRA,ADCSRA_ADPS2);
			break;
		case PRE_SCALER_2:
			clearBit(ADCSRA,ADCSRA_ADPS0);
			setBit(ADCSRA,ADCSRA_ADPS1);
			clearBit(ADCSRA,ADCSRA_ADPS2);
			break;
		case PRE_SCALER_3:
			setBit(ADCSRA,ADCSRA_ADPS0);
			setBit(ADCSRA,ADCSRA_ADPS1);
			clearBit(ADCSRA,ADCSRA_ADPS2);
			break;
		case PRE_SCALER_4:
			clearBit(ADCSRA,ADCSRA_ADPS0);
			clearBit(ADCSRA,ADCSRA_ADPS1);
			setBit(ADCSRA,ADCSRA_ADPS2);
			break;
		case PRE_SCALER_5:
			setBit(ADCSRA,ADCSRA_ADPS0);
			clearBit(ADCSRA,ADCSRA_ADPS1);
			setBit(ADCSRA,ADCSRA_ADPS2);
			break;
		case PRE_SCALER_6:
			clearBit(ADCSRA,ADCSRA_ADPS0);
			setBit(ADCSRA,ADCSRA_ADPS1);
			setBit(ADCSRA,ADCSRA_ADPS2);
			break;
		case PRE_SCALER_7:
			setBit(ADCSRA,ADCSRA_ADPS0);
			setBit(ADCSRA,ADCSRA_ADPS1);
			setBit(ADCSRA,ADCSRA_ADPS2);
			break;
		default:
			break;
	}
	//enable
	setBit(ADCSRA,ADCSRA_ADEN);
}
u16 MADC_u16Read(u8 channel){

	//select Channel
	ADMUX&=0xD0;
	ADMUX = ADMUX|channel;
	//start conversion
	setBit(ADCSRA,ADCSRA_ADSC);
	//wait
	while(!getBit(ADCSRA,ADCSRA_ADIF)){}
	//clear flag
	setBit(ADCSRA,ADCSRA_ADIF);
	return getBit(ADMUX,ADMUX_ADLAR)? ADCL>>6|ADCH<<2 :ADCL|ADCH<<8;
}
f32 MADC_f32getVolt(u8 channel){
	f32 volt = (MADC_u16Read(channel)*5.0000)/(1024);
	return volt;
}
u8 MADC_u8getTemprature(u8 channel){
	return MADC_f32getVolt(channel)*100;
}
