# Soil Moisture Monitor Using Capacitive Soil Moisture Sensor

## Description
A soil moisture monitor that uses a capacitive soil moisture sensor and three LEDs to show wet, medium, or dry soil conditions.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Capacitive Soil Moisture Sensor | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| 220 Ω Resistor | 3 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Capacitive Soil Moisture Sensor VCC |
| GND | Sensor GND and all LED cathodes (-) |
| A0 | Sensor AOUT |
| D8 | 220 Ω resistor ---> Green LED anode (+) |
| D9 | 220 Ω resistor ---> Yellow LED anode (+) |
| D10 | 220 Ω resistor ---> Red LED anode (+) |

> Sensor output ranges vary. Check wet and dry readings in the Serial Monitor and adjust the thresholds.

## Code
See [`soil_moisture_monitor.ino`](./soil_moisture_monitor.ino).

## Working Principle
1. The capacitive sensor changes its analog output according to soil moisture.
2. Arduino reads the sensor through A0.
3. With many common capacitive modules, wetter soil gives a lower reading and drier soil gives a higher reading.
4. The green LED indicates wet soil, yellow indicates medium moisture, and red indicates dry soil.
5. The values must be calibrated using the actual sensor and soil.

## Use Cases
- Plant monitoring
- Agriculture lessons
- Soil experiments
- Smart gardening prototypes
