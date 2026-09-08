# Clap Controlled Light Using Sound Sensor

## Description
A clap-controlled light prototype using a sound sensor module. Each detected clap toggles the model light between ON and OFF.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Sound Sensor Module with Digital Output | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Sound Sensor VCC |
| GND | Sound Sensor GND and LED cathode (-) |
| D2 | Sound Sensor DO |
| D9 | 220 Ω resistor ---> LED anode (+) |

> Adjust the sound sensor sensitivity so normal background noise does not trigger the project.

## Code
See [`clap_controlled_light.ino`](./clap_controlled_light.ino).

## Working Principle
1. The sound sensor detects a sharp sound such as a clap.
2. Arduino watches the digital output from the sensor.
3. When a new clap is detected, Arduino changes the current light state.
4. A short debounce time prevents one clap from being counted many times.
5. The LED stays in its new state until another clap is detected.

## Use Cases
- Clap switches
- Interactive lighting
- Sound sensor lessons
- Home automation prototypes
