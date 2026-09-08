# Greenhouse Temperature Monitor Using DHT11 Sensor

## Description
A greenhouse monitoring project that uses a DHT11 sensor to measure temperature and humidity. The current readings are shown on a 16x2 I2C LCD.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| DHT11 Sensor Module | 1 |
| 16x2 I2C LCD | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | DHT11 VCC and I2C LCD VCC |
| GND | DHT11 GND and I2C LCD GND |
| D2 | DHT11 DATA |
| A4 | I2C LCD SDA |
| A5 | I2C LCD SCL |

## Code
See [`greenhouse_temperature_monitor.ino`](./greenhouse_temperature_monitor.ino).

This sketch requires a **DHT sensor library** and a **LiquidCrystal_I2C** library.

## Working Principle
1. The DHT11 measures greenhouse temperature and relative humidity.
2. Arduino reads the sensor through D2.
3. Valid temperature and humidity values are shown on the LCD.
4. The display updates every two seconds.

## Use Cases
- Greenhouse monitoring
- Plant-growth experiments
- Environmental data lessons
- Smart agriculture projects
