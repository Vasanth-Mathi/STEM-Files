# Soil Moisture Dryness Indicator Using LED

## Description
A simple analog-sensor project using a capacitive soil-moisture sensor and one LED. The LED turns ON when the measured soil condition is drier than the selected threshold.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Capacitive Soil Moisture Sensor | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Soil Moisture Sensor VCC, if supported by the module |
| GND | Soil Moisture Sensor GND and LED cathode (-) |
| A0 | Soil Moisture Sensor AO |
| D8 | 220 Ω resistor ---> LED anode (+) |

> Calibrate the sensor in your own dry and wet soil. The example assumes a higher analog value means drier soil, which is common for many capacitive modules but is not universal.

## Code
See [`soil_moisture_led.ino`](./soil_moisture_led.ino).

## Working Principle
1. The capacitive sensor produces an analog value related to soil moisture.
2. Arduino reads the value through A0.
3. The program compares the reading with `DRY_THRESHOLD`.
4. If the soil is considered dry, the LED turns ON.
5. If the soil is sufficiently moist, the LED turns OFF.

## Use Cases
- Soil-moisture lessons
- Plant-care indicators
- Analog-threshold experiments
- Agriculture STEM activities
