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

int CS1 = 15;                               // Pin for Chip Select 1
int CS2 = 14;                               // Pin for Chip Select 2



// Create an object myDevice of the class CD22M3494EZ
CD22M3494EZ myDevice(addressPins, dataPin, strobePin);

void setup() {
    // Setup the reset, CS1, and CS2 pins as outputs
    pinMode(reset, OUTPUT);
    pinMode(CS1, OUTPUT);
    pinMode(CS2, OUTPUT);

    // Activate CS1 and deactivate CS2
    digitalWrite(CS1, HIGH); // Set CS1 to high, enabling the first device
    delay(1);                // Short delay for stabilization
    digitalWrite(CS2, LOW);  // Set CS2 to low, disabling the second device
    delay(1);                // Short delay for stabilization

    // Reset process
    digitalWrite(reset, HIGH); // Set the reset pin to high
    delay(1);               // Short delay
    digitalWrite(reset, LOW);  // Set the reset pin to low

    // Turn on the device at the address obtained from X and Y
    myDevice.switchOn(calculateAddress(X, Y));
    delay(10);              // Delay after turning on the device


    // Switching to the second device
    digitalWrite(CS1, LOW);    // Deactivate CS1, disabling the first device
    delay(1);                  // Short delay for stabilization
    digitalWrite(CS2, HIGH);   // Activate CS2, enabling the second device
    delay(1);                  // Short delay for stabilization            
    
    // Reset process for the second device
    digitalWrite(reset, HIGH); // Set the reset pin to high
    delay(1);               // Short delay
    digitalWrite(reset, LOW);  // Set the reset pin to low

    // Turn on the device at the address obtained from X and Y for the second device
    myDevice.switchOn(calculateAddress(X, Y));
    delay(10);              // Delay after turning on the device




}

void loop() {
    // Code for loop() goes here, if necessary
}