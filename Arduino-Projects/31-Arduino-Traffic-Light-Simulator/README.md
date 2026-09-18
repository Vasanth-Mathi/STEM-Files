# Arduino Traffic Light Simulator Using LEDs

## Description
A simple traffic-light simulator using red, yellow, and green LEDs. Arduino changes the LEDs in a timed sequence similar to a basic road traffic signal.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Green LED | 1 |
| 220 Ω Resistor | 3 |
| Breadboard | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| GND | All LED cathodes (-) |
| D8 | 220 Ω resistor ---> Red LED anode (+) |
| D9 | 220 Ω resistor ---> Yellow LED anode (+) |
| D10 | 220 Ω resistor ---> Green LED anode (+) |

## Code
See [`traffic_light_simulator.ino`](./traffic_light_simulator.ino).

## Working Principle
1. The green LED turns ON to represent traffic moving.
2. After the green period, the yellow LED turns ON as a warning.
3. The red LED then turns ON to stop traffic.
4. The sequence repeats continuously with fixed time delays.

## Use Cases
- Traffic-signal demonstrations
- Timing and sequence lessons
- Smart-city models
- Beginner Arduino projects
