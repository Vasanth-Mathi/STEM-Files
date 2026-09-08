# Visitor Counter Using IR Sensors

## Description
A visitor counter that uses two IR sensors at a doorway. The order in which the sensors are triggered is used to decide whether a person entered or left, and the current count is shown on an LCD.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| IR Obstacle Sensor Module | 2 |
| 16x2 I2C LCD | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | IR Sensor 1 VCC, IR Sensor 2 VCC and I2C LCD VCC |
| GND | IR Sensor 1 GND, IR Sensor 2 GND and I2C LCD GND |
| D2 | IR Sensor 1 OUT |
| D3 | IR Sensor 2 OUT |
| A4 | I2C LCD SDA |
| A5 | I2C LCD SCL |

> The code assumes the IR modules output LOW when a person is detected. Change `DETECTED_STATE` if required.

## Code
See [`visitor_counter.ino`](./visitor_counter.ino).

This sketch requires a **LiquidCrystal_I2C** library.

## Working Principle
1. The two IR sensors are placed a short distance apart at the doorway.
2. If Sensor 1 is triggered before Sensor 2, the count increases by one.
3. If Sensor 2 is triggered before Sensor 1, the count decreases by one.
4. The count never goes below zero.
5. The current number of visitors is displayed on the LCD.

## Use Cases
- Room occupancy counters
- Entrance monitoring
- Direction detection lessons
- Automation projects
