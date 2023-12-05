/*
 * eeprom.h
 *
 *  Created on: ٠٨‏/٠٩‏/٢٠٢٣
 *      Author: ASHRY
 */

#ifndef SRC_MCAL_EEPROM_EEPROM_H_
#define SRC_MCAL_EEPROM_EEPROM_H_
/*EEPROM address register low 8 bits */
#define EEARL 	(*(volatile u8*)0x3E)
/*EEPROM address register most 2 bits */
#define EEARH 	(*(volatile u8*)0x3F)
/*EEPROM data register*/
#define EEDR    (*(volatile u8*)0x3D)
/*EEPROM control register */
#define EECR 	(*(volatile u8*)0x3C)
/* EEPROM read enable*/
#define EECR_EERE 		0
/* EEPROM write enable*/
#define EECR_EEWE 		1
/* EEPROM master write enable*/
#define EECR_EEMWE 		2
/* EEPROM ready interrupt enable*/
#define EECR_EERIE 		3

void MC_EEPROM_vidWrite(u16 address , u8 data);
void MC_EEPROM_vidWriteString(u16 address ,u8*data );
u8   MC_EEPROM_u8Read(u16 address);
void  MC_EEPROM_vidRead(u16 address,u8 size,u8 *dataPtr);
void MC_EEPROM_RESET();


#endif /* SRC_MCAL_EEPROM_EEPROM_H_ */
