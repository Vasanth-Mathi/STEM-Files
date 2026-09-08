# Air Quality Monitoring System Using MQ-135 Sensor

## Description
An air-quality monitoring prototype using an MQ-135 gas sensor module. Arduino displays the raw sensor value and a simple relative air-quality level on an LCD.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| MQ-135 Air Quality Sensor Module | 1 |
| 16x2 I2C LCD | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | MQ-135 VCC and I2C LCD VCC |
| GND | MQ-135 GND and I2C LCD GND |
| A0 | MQ-135 AO |
| A4 | I2C LCD SDA |
| A5 | I2C LCD SCL |

> The LOW/MEDIUM/HIGH labels are relative sensor levels, not certified air-quality or ppm measurements.

## Code
See [`air_quality_monitor.ino`](./air_quality_monitor.ino).

This sketch requires a **LiquidCrystal_I2C** library.

## Working Principle
1. The MQ-135 sensor changes its analog output in response to several gases in the surrounding air.
2. Arduino reads the raw analog value through A0.
3. The code compares the value with simple classroom thresholds.
4. The LCD shows the raw value and labels the reading as LOW, MEDIUM, or HIGH.
5. The sensor requires warm-up and calibration for meaningful gas concentration measurements.

## Use Cases
- Air-quality demonstrations
- Environmental monitoring lessons
- Gas-sensor experiments
- Smart classroom projects
