# Vibration Detector Using SW-420 Sensor

## Description
A vibration detector using an SW-420 vibration sensor module. When vibration is detected, Arduino turns ON an LED and buzzer.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| SW-420 Vibration Sensor Module | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | SW-420 Module VCC and Buzzer Module VCC |
| GND | SW-420 Module GND, Buzzer Module GND and LED cathode (-) |
| D2 | SW-420 Module DO |
| D8 | 220 Ω resistor ---> LED anode (+) |
| D9 | Buzzer Module SIG |

> The code assumes the SW-420 output becomes HIGH when vibration is detected. Change `VIBRATION_STATE` if your module behaves differently.

## Code
See [`vibration_detector.ino`](./vibration_detector.ino).

## Working Principle
1. The SW-420 sensor reacts to vibration or shaking.
2. The module produces a digital output based on its sensitivity setting.
3. Arduino reads the digital signal on D2.
4. When vibration is detected, the LED and buzzer turn ON.
5. The onboard potentiometer can be used to adjust sensor sensitivity.

## Use Cases
- Vibration alarms
- Machine-monitoring demonstrations
- Anti-tamper projects
- Sensor lessons
