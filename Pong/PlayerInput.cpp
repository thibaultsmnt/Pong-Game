#include <stdio.h>
#include <fcntl.h>     // open
#include <inttypes.h>  // uint8_t, etc
#include <linux/i2c-dev.h> // I2C bus definitions
#include <unistd.h>
#include "PlayerInput.hpp"


void defineWrite(int canal, uint8_t *byte1, uint8_t *byte2){
    int bit_14_12 = canal + 4;

    *byte1 = (BIT_15 << 7) | (bit_14_12 << 4) | (BITS_11_9<< 1) | BITS_8;
    *byte2 = (BITS_7_5 << 5) | (BIT_4 << 4) | (BIT_3<<3) | (BIT_2<<2) | BIT_1_0;

}

float getPlayerInput(int canal, int *I2CFile){
    int16_t val;
    uint8_t writeBuf[3];
    uint8_t readBuf[2];       // 2 byte buffer to store the data read from the I2C device

    writeBuf[0] = 1;                                    // This sets the pointer register so that the following two bytes write to the config register
    defineWrite(canal, (writeBuf+1), (writeBuf+2));     //This sets the bytes in function of the parameter define and the canal

    readBuf[0]= 0;
    readBuf[1]= 0;


    // Write writeBuf to the ADS1115, the 3 specifies the number of bytes we are writing,
    // this begins a single conversion
    write(*I2CFile, writeBuf, 3);

    // Wait for the conversion to complete, this requires bit 15 to change from 0->1
    while ((readBuf[0] & 0x80) == 0)  // readBuf[0] contains 8 MSBs of config register, AND with 10000000 to select bit 15
    {
        read(*I2CFile, readBuf, 2);    // Read the config register into readBuf
    }

    writeBuf[0] = 0;                  // Set pointer register to 0 to read from the conversion register
    write(*I2CFile, writeBuf, 1);

    read(*I2CFile, readBuf, 2);        // Read the contents of the conversion register into readBuf

    val = readBuf[0] << 8 | readBuf[1];   // Combine the two bytes of readBuf into a single 16 bit result


    return (float)val*100/27900;

}
