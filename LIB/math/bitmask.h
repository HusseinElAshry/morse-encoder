/*
 * bitmask.h
 *
 *  Created on: ١٧‏/٠٨‏/٢٠٢٣
 *      Author: ASHRY
 */

#ifndef BITMASK_H_
#define BITMASK_H_
#define setBit(var, bitNo) (var|=(1<<bitNo))
#define clearBit(var, bitNo) (var&=~(1<<bitNo))
#define toggle(var, bitNo) (var^=(1<<bitNo))
#define getBit(var, bitNo) ((var>>bitNo)&1)


#endif /* BITMASK_H_ */
