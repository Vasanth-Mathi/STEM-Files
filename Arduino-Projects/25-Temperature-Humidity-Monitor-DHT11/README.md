# Temperature and Humidity Monitor Using DHT11 Sensor

## Description
A temperature and humidity monitor that uses a DHT11 sensor and a 16x2 I2C LCD. Arduino reads both environmental values and displays them on the screen.

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
See [`temperature_humidity_monitor.ino`](./temperature_humidity_monitor.ino).

This sketch requires a **DHT sensor library** and a **LiquidCrystal_I2C** library.

## Working Principle
1. The DHT11 measures temperature and relative humidity.
2. Arduino requests the readings through the DHT11 data pin.
3. If the sensor returns valid data, the temperature and humidity are shown on the LCD.
4. The values update at a slow interval suitable for the DHT11 sensor.

## Use Cases
- Weather-station models
- Indoor climate monitoring
- Greenhouse lessons
- Environmental STEM projects
