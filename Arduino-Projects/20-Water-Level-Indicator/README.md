# Water Level Indicator Using Water Level Sensor

## Description
A simple water-level indicator that reads an analog water level sensor and shows low, medium, or high water level using three LEDs.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Water Level Sensor Module | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| 220 Ω Resistor | 3 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Water Level Sensor VCC |
| GND | Water Level Sensor GND and all LED cathodes (-) |
| A0 | Water Level Sensor SIG |
| D8 | 220 Ω resistor ---> Green LED anode (+) |
| D9 | 220 Ω resistor ---> Yellow LED anode (+) |
| D10 | 220 Ω resistor ---> Red LED anode (+) |

## Code
See [`water_level_indicator.ino`](./water_level_indicator.ino).

## Working Principle
1. The water level sensor produces an analog value that changes as more of the sensing area is covered by water.
2. Arduino reads the value through A0.
3. A low reading lights the green LED.
4. A medium reading lights the yellow LED.
5. A high reading lights the red LED.
6. The threshold values should be adjusted for the actual sensor and container.

## Use Cases
- Tank level demonstrations
- Water monitoring lessons
- Analog sensor experiments
- STEM projects
