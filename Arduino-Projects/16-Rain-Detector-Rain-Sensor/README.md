# Rain Detector Using Rain Sensor

## Description
A rain-detection project using a rain sensor plate and control module. When water reaches the sensor plate, Arduino turns ON an LED and buzzer.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Rain Sensor Plate and Module | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Rain Sensor Module VCC and Buzzer Module VCC |
| GND | Rain Sensor Module GND, Buzzer Module GND and LED cathode (-) |
| D2 | Rain Sensor Module DO |
| D8 | 220 Ω resistor ---> LED anode (+) |
| D9 | Buzzer Module SIG |

> The code assumes the module output is LOW when water is detected. Change `RAIN_DETECTED_STATE` if your module behaves differently.

## Code
See [`rain_detector.ino`](./rain_detector.ino).

## Working Principle
1. The rain sensor plate changes conductivity when water droplets touch it.
2. The sensor module compares the plate signal with the level set by its onboard potentiometer.
3. When rain is detected, the digital output changes state.
4. Arduino turns ON the LED and buzzer while rain is detected.

## Use Cases
- Rain alarms
- Weather-station prototypes
- Automatic window concepts
- Water sensor lessons
