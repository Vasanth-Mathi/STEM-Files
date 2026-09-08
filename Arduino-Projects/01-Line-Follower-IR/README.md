# 4-Wheel Line Follower Robot Using IR Sensors

## Description
This project builds an autonomous **four-wheel, four-motor line follower robot** using an Arduino Uno and two IR sensors. The two motors on the left side operate together and the two motors on the right side operate together. The Arduino reads the IR sensors and controls the left and right motor groups through an L298N motor driver so the vehicle follows a black line on a light-coloured surface.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| IR Sensor Module | 2 |
| L298N Motor Driver | 1 |
| DC Geared Motors | 4 |
| Robot Wheels | 4 |
| 4-Wheel Robot Chassis | 1 |
| Motor Battery Pack | 1 |
| Jumper Wires | As required |

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

LEFT-SIDE MOTORS
L298N OUT1 ---> Left Front Motor Terminal 1 + Left Rear Motor Terminal 1
L298N OUT2 ---> Left Front Motor Terminal 2 + Left Rear Motor Terminal 2

RIGHT-SIDE MOTORS
L298N OUT3 ---> Right Front Motor Terminal 1 + Right Rear Motor Terminal 1
L298N OUT4 ---> Right Front Motor Terminal 2 + Right Rear Motor Terminal 2

POWER
Motor Battery Positive ---> L298N Motor Supply
Motor Battery Negative ---> L298N GND
Arduino GND ---> L298N GND
```

> The two motors on each side are connected as one motor group. Check the current rating of the motors and motor driver before connecting two motors to one channel. Use a separate motor battery supply and always connect the Arduino and motor-driver grounds together.

> When using PWM speed control through ENA and ENB, remove the ENA and ENB jumper caps from the L298N module.

## Code
See [`line_follower_ir.ino`](./line_follower_ir.ino).

## Working Principle
1. Two IR sensors continuously observe the surface below the front of the vehicle.
2. Black and light surfaces reflect infrared light differently.
3. The Arduino reads the digital outputs from the left and right IR sensors.
4. The four motors are controlled as two groups: left-front + left-rear and right-front + right-rear.
5. When the robot is centred on the line, both motor groups move forward.
6. When the robot moves away from the path, the Arduino reduces the speed of one side so the four-wheel vehicle turns back toward the line.
7. This correction repeats continuously while the robot moves.

> This program assumes `LOW` represents the black line and `HIGH` represents the lighter surface. Some IR modules use the opposite logic. Reverse the conditions if your sensor modules behave differently.

## Use Cases
- Automated guided vehicles
- Warehouse transport robots
- Factory material movement
- Educational robotics
- Autonomous navigation experiments
- STEM robotics competitions
- Introduction to sensor-based control systems
