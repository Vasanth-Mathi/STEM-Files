# 4-Wheel Obstacle Avoiding Robot Using Ultrasonic Sensor

## Description
This project builds an autonomous **four-wheel, four-motor obstacle avoiding robot** using an Arduino Uno and HC-SR04 ultrasonic sensor. The two motors on the left side operate together and the two motors on the right side operate together. The Arduino measures the distance to objects in front of the robot and changes the motor direction when an obstacle is detected.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| L298N Motor Driver | 1 |
| DC Geared Motors | 4 |
| Robot Wheels | 4 |
| 4-Wheel Robot Chassis | 1 |
| Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

```text
HC-SR04 ULTRASONIC SENSOR
VCC ---> Arduino 5V
GND ---> Arduino GND
TRIG ---> Arduino D2
ECHO ---> Arduino D3

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

> The two motors on each side are connected as one motor group. Verify that the combined motor current is within the motor-driver limits. Use a separate motor supply and connect all grounds together.

## Code
See [`obstacle_detector.ino`](./obstacle_detector.ino).

## Working Principle
1. The HC-SR04 sends ultrasonic pulses in front of the robot.
2. Arduino measures the return time and calculates the distance to the nearest object.
3. When the path is clear, all four motors move forward.
4. When an obstacle is closer than the configured threshold, the robot stops.
5. It moves backward briefly to create space.
6. It then turns by driving the left and right motor groups in opposite directions.
7. After turning, it continues forward and repeats the process.

## Use Cases
- Autonomous mobile robots
- Obstacle-avoidance demonstrations
- Warehouse robot prototypes
- Educational robotics
- Sensor-based navigation
- Smart delivery robot concepts
- STEM competitions and workshops
