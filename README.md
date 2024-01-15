
# CD22M3494EZ Library

This Arduino library is designed for controlling a CD22M3494EZ device, offering an easy way to manage its address and data pins for effective control.

### About the CD22M3494EZ Chip

The CD22M3494EZ chip is a BiMOS-E Crosspoint Switch. It features 128 analog switches configured in a 16 x 8 array. The CD22M3494EZ switches can handle both analog and digital signals, covering a frequency range from DC up to 1 MHz. They can operate over the entire supply voltage range, making them versatile for various signal processing applications.

## Features

- Manage and control address pins.
- Set data on a specific pin.
- Efficient strobing mechanism.
- Enable or disable devices at specified addresses.

## Installation

Download this library and place it in your Arduino IDE's libraries folder. Restart the IDE, then include the library in your sketch with `#include <CD22M3494EZ.h>`.

## Usage

To use this library in your project, include it at the top of your Arduino sketch:

```cpp
#include <CD22M3494EZ.h>
```

Create an instance of the `CD22M3494EZ` class and initialize it with the address pins, data pin, and strobe pin:

```cpp
CD22M3494EZ device = CD22M3494EZ(address_pins, data_pin, strobe_pin);
```

Control the device using the provided methods:

```cpp
device.switchOn(0x01);    // Turn on the device at address 0x01
device.switchOff(0x01);   // Turn off the device at address 0x01

// calculateAddress(X, Y) returns the switch number that connects port X with port Y

device.switchOn(calculateAddress(X, Y));    // Turn on the device at the address with X = X and Y = Y
device.switchOff(calculateAddress(X, Y));   // Turn off the device at the address with X = X and Y = Y

```

## Examples

Check the `examples` folder for detailed usage examples:
- `InitializeAndSwitchOn`: Basic initialization and turning on a device.
- `DualDeviceControlWithReset`: Advanced example showing control of two devices with reset functionality.

## Limitations and Compatibility

### Tested Microcontroller
The CD22M3494EZ library has been tested with the Arduino Pro Micro 5V. This ensures reliable performance with this specific microcontroller.

### Voltage Compatibility
The library is designed to function correctly with microcontrollers operating at 5V and above. If you are using a microcontroller with a different operating voltage, we recommend using level converters to ensure proper functionality.

### Caution with 3V Microcontrollers
Direct operation with 3V microcontrollers has not been thoroughly tested and may not be suitable. We advise caution and suggest conducting your own tests if you plan to use this library with 3V systems.


## Contributing
Contributions to the library are welcome. Please adhere to standard coding practices and document any changes.


## License

This library is open-sourced and licensed under the [MIT License](LICENSE). Feel free to use it in your projects and contribute.

## Acknowledgements
Thanks to all contributors and users of the CD22M3494EZ library.

