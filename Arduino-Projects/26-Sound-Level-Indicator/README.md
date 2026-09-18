# Sound Level Indicator Using Sound Sensor

## Description
A sound-level indicator that uses an analog microphone/sound sensor module and three LEDs. The LEDs show low, medium, or high sound level based on the sensor reading.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Analog Sound Sensor Module | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| 220 Ω Resistor | 3 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Sound Sensor VCC |
| GND | Sound Sensor GND and all LED cathodes (-) |
| A0 | Sound Sensor AO |
| D8 | 220 Ω resistor ---> Green LED anode (+) |
| D9 | 220 Ω resistor ---> Yellow LED anode (+) |
| D10 | 220 Ω resistor ---> Red LED anode (+) |

> This is a relative sound indicator, not a calibrated decibel meter.

## Code
See [`sound_level_indicator.ino`](./sound_level_indicator.ino).

## Working Principle
1. The sound sensor converts sound vibrations into an electrical signal.
2. Arduino reads the analog output through A0.
3. The code measures how far the reading moves away from the midpoint.
4. Small changes light the green LED, medium changes light the yellow LED, and larger changes light the red LED.
5. Thresholds can be adjusted for the sensor and room.

## Use Cases
- Noise-level demonstrations
- Microphone sensor lessons
- Interactive displays
- STEM experiments
