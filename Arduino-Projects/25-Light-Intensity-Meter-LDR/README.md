# Light Intensity Meter Using LDR Sensor

## Description
A simple light intensity meter that uses an LDR and a 16x2 I2C LCD. The project displays the raw light reading and an approximate relative light percentage.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| LDR / Photoresistor | 1 |
| 10 kΩ Resistor | 1 |
| 16x2 I2C LCD | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | One side of LDR and I2C LCD VCC |
| GND | One side of 10 kΩ resistor and I2C LCD GND |
| A0 | Other side of LDR and other side of 10 kΩ resistor |
| A4 | I2C LCD SDA |
| A5 | I2C LCD SCL |

> The percentage is a relative classroom value, not a calibrated lux measurement.

## Code
See [`light_intensity_meter.ino`](./light_intensity_meter.ino).

This sketch requires a **LiquidCrystal_I2C** library.

## Working Principle
1. The LDR and 10 kΩ resistor form a voltage divider.
2. Arduino reads the divider voltage through A0.
3. With this wiring, more light normally produces a higher analog reading.
4. Arduino maps the reading to an approximate 0 to 100 percent relative value.
5. The raw reading and percentage are displayed on the LCD.

## Use Cases
- Light-level experiments
- Automatic lighting lessons
- Environmental monitoring
- LDR sensor demonstrations
