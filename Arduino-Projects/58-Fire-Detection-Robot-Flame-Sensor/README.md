# Fire Detection Robot Using Flame Sensor

## Description
A four-wheel robot that moves while checking for a flame using a flame sensor module. When the sensor detects a flame, the robot stops and activates a buzzer.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Flame Sensor Module | 1 |
| Active Buzzer Module | 1 |
| L298N Motor Driver Module | 2 |
| 6V DC Geared Motor | 4 |
| Wheel | 4 |
| 4-Wheel Robot Chassis | 1 |
| 7.4V Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Flame Sensor VCC and Buzzer Module VCC |
| GND | Flame Sensor GND and Buzzer Module GND |
| D2 | Flame Sensor DO |
| D4 | Buzzer Module SIG |
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

| From | Connect To |
|---|---|
| Motor Battery + | Motor Driver 1 Motor Power and Motor Driver 2 Motor Power |
| Motor Battery - | Motor Driver 1 GND and Motor Driver 2 GND |
| Arduino GND | Motor Driver 1 GND and Motor Driver 2 GND |

> Keep the ENA and ENB jumpers fitted on both L298N modules.

> This is an educational flame-detection prototype and must not be used as a certified fire-safety device.

## Code
See [`fire_detection_robot.ino`](./fire_detection_robot.ino).

## Working Principle
1. The flame sensor checks for infrared light produced by a flame.
2. While no flame is detected, the robot moves forward.
3. When the flame sensor is triggered, Arduino stops all four motors.
4. The buzzer turns ON to indicate that a possible flame has been detected.
5. The robot remains stopped while the flame is detected.

## Use Cases
- Fire-sensor demonstrations
- Safety-system prototypes
- Autonomous monitoring concepts
- STEM robotics activities
