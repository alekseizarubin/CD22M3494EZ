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


#include <CD22M3494EZ.h>

// Define pins for addressing and data
int addressPins[7] = {2, 3, 4, 5, 6, 7, 8}; // Assign pins for the address (AX0,AX1,AX2,AX3,AY0,AY1,AY2)
int dataPin = 9;                            // Pin for data transmission
int strobePin = 10;                         // Pin for strobing (synchronization)
int reset = 16;                             // Pin for reset
int X = 0;                                  // Example X coordinate for addressing
int Y = 7;                                  // Example Y coordinate for addressing

//The CS contact must be connected to the Positive Supply.

// Create an object myDevice of the class CD22M3494EZ
CD22M3494EZ myDevice(addressPins, dataPin, strobePin);

void setup() {
    // Setup the reset, CS1, and CS2 pins as outputs
    pinMode(reset, OUTPUT);

    // Reset process
    digitalWrite(reset, HIGH); // Set the reset pin to high
    delay(1);               // Short delay
    digitalWrite(reset, LOW);  // Set the reset pin to low

    // Turn on the device at the address obtained from X and Y
    myDevice.switchOn(calculateAddress(X, Y));
    delay(10);              // Delay after turning on the device

}

void loop() {
    // Code for loop() goes here, if necessary
}