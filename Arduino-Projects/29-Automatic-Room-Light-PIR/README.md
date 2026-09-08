# Automatic Room Light Using PIR Sensor

## Description
An automatic room-light prototype that uses a PIR sensor to detect movement. The model light turns ON when motion is detected and turns OFF after no movement has been detected for a set time.

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
| 5V | PIR VCC |
| GND | PIR GND and LED cathode (-) |
| D2 | PIR OUT |
| D9 | 220 Ω resistor ---> LED anode (+) |

> The LED represents a room light. Do not connect a mains lamp directly to Arduino.

## Code
See [`automatic_room_light.ino`](./automatic_room_light.ino).

## Working Principle
1. The PIR sensor detects movement in the room.
2. When motion is detected, Arduino turns ON the LED immediately.
3. Arduino remembers the time of the latest motion.
4. If no new motion is detected for the set delay, the LED turns OFF.

## Use Cases
- Automatic room lighting
- Energy-saving demonstrations
- Occupancy sensing
- Home automation lessons
