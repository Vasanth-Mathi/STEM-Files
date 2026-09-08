# Obstacle Avoiding Robot Using Ultrasonic Sensor and Servo Motor

## Description
A four-wheel robot that detects obstacles using an HC-SR04 ultrasonic sensor mounted on a servo motor. When an obstacle is detected, the servo turns the sensor left and right. The Arduino compares both distances and turns the robot toward the side with more free space.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Small Servo Motor (such as SG90) | 1 |
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
| 5V | HC-SR04 VCC and Servo VCC |
| GND | HC-SR04 GND and Servo GND |
| D2 | HC-SR04 TRIG |
| D3 | HC-SR04 ECHO |
| D4 | Servo Signal |
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

> For this beginner version, the small servo and HC-SR04 are powered from the Arduino 5V pin. A USB power bank is preferred for this project because a servo can draw more current than a simple sensor. If the Arduino resets or the servo jitters while moving, use a stronger 5V USB supply or power the servo separately.

> The motor battery voltage must match the motors being used. Do not automatically use 12V with 6V motors.

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
