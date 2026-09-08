# Motion Detector Using PIR Sensor

## Description
A simple motion detector that uses a PIR sensor to detect movement. When motion is detected, an LED and buzzer turn ON.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| PIR Motion Sensor | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | PIR VCC and Buzzer Module VCC |
| GND | PIR GND, Buzzer Module GND and LED cathode (-) |
| D2 | PIR OUT |
| D8 | 220 Ω resistor ---> LED anode (+) |
| D9 | Buzzer Module SIG |

## Code
See [`pir_motion_detector.ino`](./pir_motion_detector.ino).

## Working Principle
1. The PIR sensor monitors changes in infrared radiation caused by moving people or animals.
2. When motion is detected, the PIR output becomes active.
3. Arduino turns ON the LED and buzzer.
4. When no motion is detected, the LED and buzzer remain OFF.

## Use Cases
- Room motion alarms
- Occupancy sensing
- Security-system prototypes
- PIR sensor lessons
