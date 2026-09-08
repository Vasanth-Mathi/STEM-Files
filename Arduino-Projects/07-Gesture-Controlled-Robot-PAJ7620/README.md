# Gesture Controlled Robot Car Using PAJ7620 Gesture Sensor

## Description
A four-wheel robot car controlled by hand gestures detected by a 5 V PAJ7620 gesture sensor module, such as Grove Gesture V1.0. Swipe gestures are converted into movement commands by the Arduino.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| PAJ7620 Gesture Sensor Module (5V Grove type) | 1 |
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
| 5V | Grove Gesture Sensor VCC |
| GND | Grove Gesture Sensor GND |
| A4 | Grove Gesture Sensor SDA |
| A5 | Grove Gesture Sensor SCL |
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

> Use a 5 V PAJ7620 gesture module designed for Arduino Uno. Do not substitute a bare 3.3 V gesture sensor without checking its voltage requirements.

## Code
See [`gesture_controlled_robot.ino`](./gesture_controlled_robot.ino).

This sketch requires the **Grove Gesture / PAJ7620** Arduino library.

## Working Principle
1. The gesture sensor communicates with Arduino through I2C.
2. An upward gesture moves the robot forward.
3. A downward gesture moves the robot backward.
4. Left and right gestures turn the robot in the matching direction.
5. A wave gesture stops the robot.
6. The command is repeated whenever a new gesture is detected.

## Use Cases
- Gesture interfaces
- Human-machine interaction
- Robot control experiments
- STEM robotics activities
