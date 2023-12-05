/*
 * adc.h
 *
 *  Created on: ٢٤‏/٠٨‏/٢٠٢٣
 *      Author: ASHRY
 */

#ifndef SRC_MCAL_ADC_ADC_H_
#define SRC_MCAL_ADC_ADC_H_
/*
 * analogue digital multiplexer register which include AD channel and gain at first five bits
 * 5th bit responsible for adjusting result right or left ADCL must read before ADCH
 * 7th and 8th  responsible for selecting reference voltage
*/
#define ADMUX   (*(volatile u8*) 0x27)
#define ADMUX_MUX0   0
#define ADMUX_MUX1   1
#define ADMUX_MUX2   2
#define ADMUX_MUX3   3
#define ADMUX_MUX4   4
#define ADMUX_ADLAR  5
#define ADMUX_REFS0  6
#define ADMUX_REFS1  7
/*
 * analogue digital control sense register which can control pre-scaler factor in first  3 bits
 * 3th bit is responsible for enable interrupt
 * 4th bit is responsible for interrupt flag
 * 5th bit responsible for auto trigger
 * 6th bit is for starting conversion
 * 7th bit for enable conversion
 */
#define ADCSRA  (*(volatile u8*) 0x26)
#define ADCSRA_ADPS0 0
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS2 2
#define ADCSRA_ADIE  3
#define ADCSRA_ADIF  4
#define ADCSRA_ADATE 5
#define ADCSRA_ADSC  6
#define ADCSRA_ADEN  7
/*
 * ADCH ADCL registers that hold result
 * SFIOR select function input output register which contain last 3 bits to select trigger source  */
#define ADCH    (*(volatile u8*) 0x25)
#define ADCL    (*(volatile u8*) 0x24)
#define SFIOR   (*(volatile u8*) 0x50)

/* pins at port A*/
#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3
#define ADC_CHANNEL_4 4
#define ADC_CHANNEL_5 5
#define ADC_CHANNEL_6 6
#define ADC_CHANNEL_7 7

/* trigger source pins*/
#define SFIOR_ADTS0  5
#define SFIOR_ADTS1  6
#define SFIOR_ADTS2  7

#define AREF     0
#define AVCC     1
#define INTERNAL 3
#define PRE_SCALER_0 2
#define PRE_SCALER_1 2
#define PRE_SCALER_2 4
#define PRE_SCALER_3 8
#define PRE_SCALER_4 16
#define PRE_SCALER_5 32
#define PRE_SCALER_6 64
#define PRE_SCALER_7 128

void MADC_vidInit(u8 volt_reference,u8 pre_scaler);
u16 MADC_u16Read(u8 channel );
f32 MADC_f32getVolt(u8 channel );
u8 MADC_u8getTemprature(u8 channel);

#endif /* SRC_MCAL_ADC_ADC_H_ */
