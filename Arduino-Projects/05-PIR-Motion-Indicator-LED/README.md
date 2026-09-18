# PIR Motion Indicator Using LED

## Description
A simple motion-detection project using a PIR sensor and one LED. When the PIR sensor detects movement, Arduino turns the LED ON.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| PIR Motion Sensor | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | PIR Sensor VCC |
| GND | PIR Sensor GND and LED cathode (-) |
| D2 | PIR Sensor OUT |
| D8 | 220 Ω resistor ---> LED anode (+) |

> PIR sensors may need a short warm-up period after power is switched on.

## Code
See [`pir_motion_led.ino`](./pir_motion_led.ino).

## Working Principle
1. The PIR sensor responds to changes in infrared radiation caused by moving people or warm objects.
2. The sensor output becomes HIGH when motion is detected.
3. Arduino reads the signal through D2.
4. Arduino turns the LED ON while motion is detected.
5. The LED turns OFF when the PIR output returns LOW.

## Use Cases
- Motion-sensor lessons
- Occupancy indicators
- Security-system demonstrations
- Beginner automation projects
