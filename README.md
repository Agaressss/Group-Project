# Arduino Bluetooth Servo Controller for WheelCam App

## Overview

This Arduino project is specifically tailored to function alongside the WheelCam app, an Android application that enhances camera controls through advanced features like custom grid control and dynamic orientation adjustments. The project enables remote control of servo motors via Bluetooth, facilitating precise adjustments in camera orientation for the WheelCam app.

## Hardware Requirements

- **Arduino Nano**: 1 unit
- **SER0038 270° Servo**: 2 units
- **SER0039 360° Servo**: 1 unit
- **HC-05 Bluetooth Module**: 1 unit
- **2-Slot Battery Case**: 1 unit
- **18650 3.7V Battery**: 2 units

## Wiring Instructions

1. **Servo Motors**:
   - Connect `SER0038 270° servos` to pins specified in your Arduino sketch.
   - Connect `SER0039 360° servo` to an appropriate pin as per your setup.
   - Ensure all servos are connected to a power source adequate for their operation.
2. **HC-05 Bluetooth Module**:
   - Connect `TX` of HC-05 to `RX` on Arduino Nano.
   - Connect `RX` of HC-05 to `TX` on Arduino Nano.
   - Power the HC-05 module directly from the Arduino Nano's 3.3V output to ensure voltage compatibility.

## Software Setup

1. **Arduino Sketch**:
   - Load the provided sketch onto the Arduino Nano using the Arduino IDE.
   - Ensure the HC-05 module is configured and paired with the Android device.
2. **WheelCam App Integration**:
   - Ensure the WheelCam app is installed on an Android device and paired via Bluetooth to the Arduino setup.

## Usage

- **Commands**:
  - `"reset"`: Resets servos to default positions.
  - `"rotate"`: Toggles the position of the 360° servo.
  - `"x<number>y<number>"`: Adjusts the 270° servos based on the transmitted coordinates.

- **Operation with WheelCam App**:
  - Use the app to send commands to the Arduino setup for dynamic adjustment of camera orientations.

## Additional Notes

- Always ensure that the servo motors do not exceed their operating voltage and current limits to avoid damage.
- It's recommended to use a separate power source for the servos if their combined current draw exceeds the Arduino's output capacity.

## License

This project is released under the [MIT License](https://choosealicense.com/licenses/mit/).
