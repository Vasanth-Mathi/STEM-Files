# ESP32 Bluetooth Home Appliance Controller

## Description
Uses Bluetooth Classic commands to control four low-voltage LED outputs that represent home appliances.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module with Bluetooth Classic | 1 |
| LED | 4 |
| 220 Ω Resistor | 4 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| GPIO 23 | Appliance 1 LED through 220 Ω resistor |
| GPIO 22 | Appliance 2 LED through 220 Ω resistor |
| GPIO 21 | Appliance 3 LED through 220 Ω resistor |
| GPIO 19 | Appliance 4 LED through 220 Ω resistor |
| GND | All LED cathodes |

> This is a low-voltage educational prototype. Do not connect household mains appliances directly to ESP32 GPIO pins.

## Code
See [`bluetooth_home_appliance_controller.ino`](./bluetooth_home_appliance_controller.ino).

## Working Principle
1. The ESP32 creates the Bluetooth device `ESP32-Home`.
2. Commands 1 to 4 toggle individual outputs.
3. Command A turns all outputs on and S turns all outputs off.
4. LEDs safely demonstrate appliance control without using mains electricity.

## Use Cases
- Smart-home demonstrations
- Bluetooth command practice
- Output-control lessons
- Home-automation prototypes
