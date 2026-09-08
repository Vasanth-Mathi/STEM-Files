# Obstacle Avoiding Robot Using Ultrasonic Sensor and Servo Motor

## Description
A four-wheel robot that detects obstacles using an HC-SR04 ultrasonic sensor mounted on a servo motor. When an obstacle is detected, the servo turns the sensor left and right. The Arduino compares both distances and turns the robot toward the side with more free space.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Servo Motor | 1 |
| L298N Motor Driver Module | 2 |
| 6V DC Geared Motor | 4 |
| Wheel | 4 |
| 4-Wheel Robot Chassis | 1 |
| 7.4V Battery Pack | 1 |
| Regulated 5V Supply for Servo | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | HC-SR04 VCC |
| GND | HC-SR04 GND and Servo Supply GND |
| D2 | HC-SR04 TRIG |
| D3 | HC-SR04 ECHO |
| D4 | Servo Signal |
| D8 | Motor Driver 1 IN1 and Motor Driver 2 IN1 |
| D9 | Motor Driver 1 IN2 and Motor Driver 2 IN2 |
| D10 | Motor Driver 1 IN3 and Motor Driver 2 IN3 |
| D11 | Motor Driver 1 IN4 and Motor Driver 2 IN4 |

### Servo Connections

| Servo Wire | Connect To |
|---|---|
| Signal | Arduino D4 |
| VCC | Regulated 5V Supply + |
| GND | Regulated 5V Supply GND and Arduino GND |

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
| Battery + | Arduino VIN, Motor Driver 1 Motor Power, Motor Driver 2 Motor Power |
| Battery - | Arduino GND, Motor Driver 1 GND, Motor Driver 2 GND |
| Regulated 5V + | Servo VCC |
| Regulated 5V GND | Servo GND and Arduino GND |

Keep the **ENA and ENB jumpers fitted** on both L298N modules.

## Code
See [`obstacle_avoider_servo_scan.ino`](./obstacle_avoider_servo_scan.ino).

## Working Principle
1. The ultrasonic sensor looks straight ahead and measures distance.
2. If the path is clear, the robot moves forward.
3. If an obstacle is detected, the robot stops and moves backward slightly.
4. The servo turns the ultrasonic sensor to the left and measures the distance.
5. The servo turns the sensor to the right and measures again.
6. Arduino compares both readings.
7. The robot turns toward the side with more free space.
8. If no valid distance is measured, the robot stops for safety.

## Use Cases
- Obstacle avoiding robots
- Autonomous navigation projects
- Servo motor experiments
- Ultrasonic sensor projects
- Robotics workshops
- STEM projects
