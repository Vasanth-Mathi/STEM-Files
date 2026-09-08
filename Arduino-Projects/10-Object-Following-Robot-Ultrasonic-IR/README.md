# Object Following Robot Using Ultrasonic and IR Sensors

## Description
A four-wheel robot that follows a nearby object using an HC-SR04 ultrasonic sensor for distance and two IR sensors for left/right direction. The robot tries to keep the object within a simple target distance range.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| IR Obstacle Sensor Module | 2 |
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
| 5V | HC-SR04 VCC, Left IR VCC and Right IR VCC |
| GND | HC-SR04 GND, Left IR GND and Right IR GND |
| D2 | HC-SR04 TRIG |
| D3 | HC-SR04 ECHO |
| D4 | Left IR OUT |
| D5 | Right IR OUT |
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

> IR sensor modules may use opposite digital output logic. Change `IR_DETECTED_STATE` if required.

## Code
See [`object_following_robot.ino`](./object_following_robot.ino).

## Working Principle
1. The ultrasonic sensor measures how far the object is from the robot.
2. If the object is farther than the target range, the robot moves forward.
3. If the object is too close, the robot moves backward.
4. When the object is in the target distance range, the left and right IR sensors help identify its direction.
5. If only the left IR sensor detects the object, the robot turns left.
6. If only the right IR sensor detects the object, the robot turns right.
7. If the distance reading is invalid, the robot stops.

## Use Cases
- Object-following robots
- Sensor-fusion demonstrations
- Distance-control lessons
- STEM robotics activities
