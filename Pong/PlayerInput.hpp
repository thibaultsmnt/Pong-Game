/*
 * playerInput.hpp
 *
 *  Created on: 14 Apr 2016
 *      Author: pi
 */

#ifndef PLAYERINPUT_HPP_
#define PLAYERINPUT_HPP_

#include <inttypes.h>
#define ADS_ADDRESS 0x48 //adress on the I2C bus

#define BIT_15 1
#define BITS_14_12 0x4
#define BITS_11_9 000   /*
                        000 : FS = ±6.144V(1)           100 : FS = ±0.512V
                        001 : FS = ±4.096V(1)           101 : FS = ±0.256V
                        010 : FS = ±2.048V (default)    110 : FS = ±0.256V
                        011 : FS = ±1.024V              111 : FS = ±0.256V   */
#define BITS_8 1        /*0 : Continuous conversion mode
                        1 : Power-down single-shot mode (default)*/
#define BITS_7_5 000    /*000 : 128SPS 100 : 1600SPS (default)
                        001 : 250SPS 101 : 2400SPS
                        010 : 490SPS 110 : 3300SPS
                        011 : 920SPS 111 : 3300SPS*/

#define BIT_4 0
#define BIT_3 0
#define BIT_2 0
#define BIT_1_0 0x3

void defineWrite(int canal, uint8_t *byte1, uint8_t *byte2);

float getPlayerInput(int canal, int *I2CFile);



#endif /* PLAYERINPUT_HPP_ */
