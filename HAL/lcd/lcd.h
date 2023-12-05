/*
 * lcd.h
 *
 *  Created on: ٢٠‏/٠٨‏/٢٠٢٣
 *      Author: ASHRY
 */

#ifndef LCD_H_
#define LCD_H_
#define SCREEN_WIDTH  		16
#define PERCISION 4
#define RS_PIN 0
#define RW_PIN 1
#define EN_PIN 2
#define CONTROL_PORT PORT_A
#define DATA_PORT  PORT_C

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define READ  1
#define WRITE 0
void HCLCD_vidInit();
void HCLCD_vidSendCommand(u8 cpy_u8Command);
void HCLCD_vidSendData(u8 cpy_u8Data);
void HCLCD_vidSendString(const u8* add_pu8String);
void HCLCD_vidSendNumber(s32 cpy_u32Number);
void HCLCD_vidSendFloat(f32 cpy_f32Float);
void HCLCD_vidGoTo(u8 cpy_u8X, u8 cpy_u8Y);
void HCLCD_vidClear();
void HCLCD_vidSendSpecialChar(const u8* arr_u8Char, u8 cpy_u8BlockNumber);

#endif /* LCD_H_ */
