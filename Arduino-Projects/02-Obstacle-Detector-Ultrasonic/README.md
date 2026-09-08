# Obstacle Avoiding Robot Using Ultrasonic Sensor

## Description
A four-wheel robot that detects obstacles using an HC-SR04 ultrasonic sensor. When an obstacle comes too close, the robot stops, moves backward, turns, and continues moving.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
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
| 5V | HC-SR04 VCC |
| GND | HC-SR04 GND |
| D2 | HC-SR04 TRIG |
| D3 | HC-SR04 ECHO |
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
See [`obstacle_detector.ino`](./obstacle_detector.ino).

## Working Principle
1. The HC-SR04 measures the distance in front of the robot.
2. If the path is clear, the robot moves forward.
3. If an obstacle is within 20 cm, the robot stops.
4. The robot moves backward for a short time.
5. It then turns right and checks the path again.
6. If the sensor does not give a valid reading, the robot stops for safety.

## Use Cases
- Obstacle avoiding robots
- Autonomous robot demonstrations
- Distance-sensing lessons
- Robotics workshops
- STEM projects
