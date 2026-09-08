# ESP32 Blynk IoT Smart Home Control System

## Description
Controls four low-voltage outputs from Blynk dashboard switches to demonstrate remote smart-home control.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| LED | 4 |
| 220 Ω Resistor | 4 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| GPIO 23 | Output 1 LED through 220 Ω resistor |
| GPIO 22 | Output 2 LED through 220 Ω resistor |
| GPIO 21 | Output 3 LED through 220 Ω resistor |
| GPIO 19 | Output 4 LED through 220 Ω resistor |
| GND | All LED cathodes |

> The LEDs are safe appliance models. Do not connect household mains loads directly to ESP32 GPIO pins.

## Code
See [`blynk_smart_home_control.ino`](./blynk_smart_home_control.ino).

## Working Principle
1. Blynk virtual pins V0 to V3 are configured as switch datastreams.
2. Each Blynk switch changes one ESP32 GPIO output.
3. The four LEDs represent four different home appliances.
4. The project demonstrates cloud-based remote control without connecting real mains loads.

## Use Cases
- Smart-home education
- Blynk switch widgets
- Remote GPIO control
- IoT dashboard practice
