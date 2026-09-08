# Line Follower Robot Using IR Sensors

## Description
A four-wheel robot that follows a black line using two IR sensors. The Arduino checks the left and right IR sensors and turns the robot whenever it moves away from the line.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| IR Sensor Module | 2 |
| L298N Motor Driver Module | 2 |
| 6V DC Geared Motor | 4 |
| Wheel | 4 |
| 4-Wheel Robot Chassis | 1 |
| 7.4V Motor Battery Pack | 1 |
| USB Power Bank or 7-12V Arduino Power Supply | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Left IR VCC and Right IR VCC |
| GND | Left IR GND and Right IR GND |
| D2 | Left IR OUT |
| D3 | Right IR OUT |
| D8 | Motor Driver 1 IN1 and Motor Driver 2 IN1 |
| D9 | Motor Driver 1 IN2 and Motor Driver 2 IN2 |
| D10 | Motor Driver 1 IN3 and Motor Driver 2 IN3 |
| D11 | Motor Driver 1 IN4 and Motor Driver 2 IN4 |

### Motor Connections

| Motor | Connect To |
|---|---|
| Front Left Motor | Motor Driver 1 OUT1 and OUT2 |
| Front Right Motor | Motor Driver 1 OUT3 and OUT4 |
| Rear Left Motor | Motor Driver 2 OUT1 and OUT2 |
| Rear Right Motor | Motor Driver 2 OUT3 and OUT4 |

### Power Connections

| Power Source | Connect To |
|---|---|
| USB Power Bank or 7-12V Arduino Supply | Arduino USB port or DC jack |
| Motor Battery + | Motor Driver 1 Motor Power and Motor Driver 2 Motor Power |
| Motor Battery - | Motor Driver 1 GND and Motor Driver 2 GND |
| Arduino GND | Motor Driver 1 GND and Motor Driver 2 GND |

Keep the **ENA and ENB jumpers fitted** on both L298N modules.

> The motor battery voltage must match the motors being used. Do not automatically use 12V with 6V motors.

## Code
See [`line_follower_ir.ino`](./line_follower_ir.ino).

## Working Principle
1. The two IR sensors check the floor in front of the robot.
2. When both sensors are on the normal floor, the robot moves forward.
3. If the left sensor detects the black line, the robot turns left.
4. If the right sensor detects the black line, the robot turns right.
5. If both sensors detect black, the robot stops.

> The code assumes the IR sensor gives `LOW` on the black line. If your sensor gives `HIGH` on black, change `BLACK_STATE` in the code to `HIGH`.

## Use Cases
- Line-following robots
- Automated guided vehicles
- Warehouse robot demonstrations
- Sensor-based navigation lessons
- STEM robotics activities
