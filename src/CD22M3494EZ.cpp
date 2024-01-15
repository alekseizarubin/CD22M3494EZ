/*

The MIT License (MIT)

Copyright (c) 2024 alekseizarubin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <Arduino.h>
#include "CD22M3494EZ.h"

// Constructor implementation
CD22M3494EZ::CD22M3494EZ(int *address_pins, int data_pin, int strobe_pin) {
    memcpy(addressPins, address_pins, 7 * sizeof(int));
    dataPin = data_pin;
    strobePin = strobe_pin;

    // Initialize pins
    for (int i = 0; i < 7; i++) {
        pinMode(addressPins[i], OUTPUT);
    }
    pinMode(dataPin, OUTPUT);
    pinMode(strobePin, OUTPUT);
}

// Implementation of setAddress
void CD22M3494EZ::setAddress(int address) {
    for (int i = 0; i < 7; i++) {
        digitalWrite(addressPins[i], (address >> i) & 0x01);
    }
}

// Implementation of setData
void CD22M3494EZ::setData(bool data) {
    digitalWrite(dataPin, data);
}

// Implementation of strobe
void CD22M3494EZ::strobe() {
digitalWrite(strobePin, HIGH);
delay(1); // Short delay for stabilization
digitalWrite(strobePin, LOW);
}

// Implementation of switchOn
void CD22M3494EZ::switchOn(int address) {
setAddress(address);
setData(HIGH);
strobe();
}

// Implementation of switchOff
void CD22M3494EZ::switchOff(int address) {
setAddress(address);
setData(LOW);
strobe();

}

// Implementation of calculateAddress
int calculateAddress(int portX, int portY) {
// Lookup table to convert X ports to address bits
    int xAddressLookup[16] = {0b0000, 0b0001, 0b0010, 0b0011, 0b0100, 0b0101, 0b1000, 0b1001,
                              0b1010, 0b1011, 0b1100, 0b1101, 0b0110, 0b0111, 0b1110, 0b1111};

    int addressX = xAddressLookup[portX & 0xF]; // Retrieve X address from the table
    int addressY = (portY & 0x7) << 4; // Retrieve Y address bits and shift left by 4 positions

// Combine Y and X addresses (Y becomes the higher bits)
    return addressY | addressX;
}