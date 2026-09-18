# Rainwater Tank Level Monitor Using Ultrasonic Sensor

## Description
A rainwater tank level monitor that uses an HC-SR04 mounted above the water surface. Arduino measures the distance from the sensor to the water and displays an estimated tank fill percentage.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| 16x2 I2C LCD | 1 |
| Mounting Support | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | HC-SR04 VCC and I2C LCD VCC |
| GND | HC-SR04 GND and I2C LCD GND |
| D2 | HC-SR04 TRIG |
| D3 | HC-SR04 ECHO |
| A4 | I2C LCD SDA |
| A5 | I2C LCD SCL |

> Set `TANK_DEPTH_CM` to the measured distance from the sensor face to the lowest water level used as 0%.

> The standard HC-SR04 is not waterproof. Mount it above the water where it cannot be splashed or submerged.

## Code
See [`rainwater_tank_level_monitor.ino`](./rainwater_tank_level_monitor.ino).

This sketch requires a **LiquidCrystal_I2C** library.

## Working Principle
1. The ultrasonic sensor is mounted at the top of the tank facing downward.
2. Arduino measures the distance from the sensor to the water surface.
3. A smaller distance means the tank is fuller.
4. The code compares the measured distance with the configured tank depth.
5. The estimated fill percentage is displayed on the LCD.

## Use Cases
- Rainwater harvesting systems
- Tank level monitoring
- Water conservation lessons
- Ultrasonic sensor projects
