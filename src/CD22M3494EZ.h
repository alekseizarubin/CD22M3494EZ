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
#ifndef CD22M3494EZ_H
#define CD22M3494EZ_H

#include <Arduino.h>

class CD22M3494EZ {
    int addressPins[7]; // Pins for the address
    int dataPin;        // Pin for data
    int strobePin;      // Pin for strobe

public:
    // Constructor: initializes the pins
    CD22M3494EZ(int *address_pins, int data_pin, int strobe_pin);

    // Sets the address
    void setAddress(int address);

    // Sets the data
    void setData(bool data);

    // Activates the strobe
    void strobe();

    // Turns on the device at the given address
    void switchOn(int address);

    // Turns off the device at the given address
    void switchOff(int address);

};

    // Converts X and Y port values to an address
    int calculateAddress(int portX, int portY);
#endif