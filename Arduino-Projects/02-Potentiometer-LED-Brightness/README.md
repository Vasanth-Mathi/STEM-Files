# Potentiometer Controlled LED Brightness

## Description
A simple analog-input project where a potentiometer controls the brightness of an LED. Turning the knob changes the voltage read by Arduino, and the program converts that reading into an LED brightness level.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| 10 kΩ Potentiometer | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | One outer potentiometer terminal |
| GND | Other outer potentiometer terminal and LED cathode (-) |
| A0 | Potentiometer centre / wiper terminal |
| D9 | 220 Ω resistor ---> LED anode (+) |

> D9 is used because it supports PWM output on the Arduino Uno.

## Code
See [`potentiometer_led_brightness.ino`](./potentiometer_led_brightness.ino).

## Working Principle
1. The potentiometer creates a changing voltage between 0V and 5V.
2. Arduino reads this voltage through A0 as a value from approximately 0 to 1023.
3. The program converts the reading to a PWM value from 0 to 255.
4. Arduino sends the PWM signal through D9.
5. The LED becomes dimmer or brighter as the knob is turned.

## Use Cases
- Learning analog input
- Learning PWM output
- Brightness-control experiments
- Understanding value mapping
