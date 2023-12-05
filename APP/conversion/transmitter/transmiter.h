/*
 * transmiter.h
 *
 *  Created on: ٣٠‏/١١‏/٢٠٢٣
 *      Author: ASHRY
 */

#ifndef APP_CONVERSION_TRANSMITER_H_
#define APP_CONVERSION_TRANSMITER_H_
typedef enum{
	CONVERTED,
	NON_CONVERTED,
}CONVERSION_STATE;
void vid_initProgram();
void vid_transmitCharcters();
void vid_transmitNumbers();
void vid_displayHome();
void vid_handle_NonConverted(u8*ptrToLetter);
void vid_convertToSignal(u8*pattern);
CONVERSION_STATE convertToMorse(u8*pattern,u8 character);

#endif /* APP_CONVERSION_TRANSMITER_H_ */
