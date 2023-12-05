/*
 * keypad.h
 *
 *  Created on: ٢٢‏/٠٨‏/٢٠٢٣
 *      Author: ASHRY
 */

#ifndef SRC_HAL_KEYPAD_KEYPAD_H_
#define SRC_HAL_KEYPAD_KEYPAD_H_

#define PORT_NUM PORT_B

u8 HKEYPAD_u8getPressedValue();
u8 HKEYPAD_u8getCharecterValue();
void HKEYPAD_vidinit();
#endif /* SRC_HAL_KEYPAD_KEYPAD_H_ */
