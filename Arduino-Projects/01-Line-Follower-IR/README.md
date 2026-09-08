# Line Follower Robot Using IR Sensors

## Description
A line follower robot is an autonomous robot that follows a black line on a white surface using two IR sensors. The Arduino reads the sensor outputs and controls two DC motors through an L298N motor driver to keep the robot aligned with the path.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| IR Sensor Module | 2 |
| L298N Motor Driver | 1 |
| DC Geared Motors | 2 |
| Robot Wheels | 2 |
| Battery Pack | 1 |
| Jumper Wires | As required |
| Robot Chassis | 1 |

## Circuit Connections

```text
LEFT IR SENSOR
VCC ---> Arduino 5V
GND ---> Arduino GND
OUT ---> Arduino D2

RIGHT IR SENSOR
VCC ---> Arduino 5V
GND ---> Arduino GND
OUT ---> Arduino D3

L298N MOTOR DRIVER
ENA ---> Arduino D5
IN1 ---> Arduino D8
IN2 ---> Arduino D9
ENB ---> Arduino D6
IN3 ---> Arduino D10
IN4 ---> Arduino D11

OUT1 ---> Left Motor Terminal 1
OUT2 ---> Left Motor Terminal 2
OUT3 ---> Right Motor Terminal 1
OUT4 ---> Right Motor Terminal 2

L298N GND ---> Arduino GND
Battery Positive ---> L298N Motor Supply
Battery Negative ---> L298N GND
```

> When using PWM speed control through ENA and ENB, remove the ENA and ENB jumper caps from the L298N module.

## Code
See [`line_follower_ir.ino`](./line_follower_ir.ino).

## Working Principle
1. Two IR sensors continuously observe the surface below the robot.
2. Black and white surfaces reflect infrared light differently.
3. The sensor modules send digital signals to the Arduino.
4. The Arduino compares the left and right sensor readings.
5. Based on the readings, it changes the speed of the left and right motors.
6. The L298N motor driver supplies the required motor current.
7. The robot repeatedly corrects its direction and follows the line.

> Sensor modules may use opposite logic depending on their design and calibration. This project assumes `LOW` represents the black line and `HIGH` represents the white surface. Reverse the conditions in the code if your modules behave differently.

## Use Cases
- Automated guided vehicles
- Factory material transportation
- Warehouse robots
- Educational robotics
- Hospital delivery robots
- Industrial automation
