# Displays and Modules

> **Source note:** Component names, basic purpose, connection guidance, and example uses are based on the uploaded **Microcontroller Boards Reference** document. Short student explanations are added to make the material easier to learn. Exact pin labels, voltage limits, polarity, and module variants must be checked on the actual component before wiring.

Modules add communication, display, and switching functions to a controller.

| No. | Component | How It Works | Basic Connection | Example Use |
|---:|---|---|---|---|
| 3 | 16x2 LCD Display with I2C | Shows letters, numbers, and sensor values. The I2C interface reduces the number of signal wires needed. | Connect SDA and SCL to the controller's corresponding I2C pins, plus suitable power and GND. | Displaying sensor data |
| 4 | HC05 Bluetooth Module | Provides short-range wireless serial communication between a controller and another Bluetooth device. | Reference connection: HC05 TX to controller RX and HC05 RX to controller TX, plus power and GND. Check the exact module's logic-level requirements before wiring. | Wireless communication with a smartphone |
| 5 | Relay Module, 1 Channel | Uses a low-power control signal to switch a separate load circuit. | Connect the relay control input to a digital output, and connect suitable power/GND. The load uses the relay output terminals. | Switching a separate electrical load |

## Safety Note
For student work, use **safe low-voltage loads only**. Although the source lists AC appliance control as an application, mains wiring should not be treated as a student breadboard activity.
