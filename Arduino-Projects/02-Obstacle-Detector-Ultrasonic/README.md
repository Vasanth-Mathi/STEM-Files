# 4-Wheel Obstacle Avoiding Robot Using Ultrasonic Sensor

## Description
This project builds an autonomous **four-wheel, four-motor obstacle avoiding robot** using an Arduino Uno, an HC-SR04 ultrasonic sensor, four DC geared motors, and **two L298N dual H-bridge motor-driver modules**.

Each motor is connected to its own H-bridge channel. Motor Driver 1 controls the two front motors and Motor Driver 2 controls the two rear motors. The Arduino shares the left-side control signals between the front-left and rear-left channels and shares the right-side control signals between the front-right and rear-right channels. This lets the four wheels move as coordinated left and right sides while keeping one motor on each driver channel.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| L298N Dual H-Bridge Motor Driver Module | 2 |
| DC Geared Motor | 4 |
| Wheel | 4 |
| 4-Wheel Robot Chassis | 1 |
| Suitable Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

```text
HC-SR04 ULTRASONIC SENSOR
VCC ---> Arduino 5V
GND ---> Arduino GND
TRIG ---> Arduino D2
ECHO ---> Arduino D3

SHARED LEFT-SIDE CONTROL
Arduino D5 (PWM) ---> Driver 1 ENA
Arduino D5 (PWM) ---> Driver 2 ENA
Arduino D8 ---> Driver 1 IN1
Arduino D8 ---> Driver 2 IN1
Arduino D9 ---> Driver 1 IN2
Arduino D9 ---> Driver 2 IN2

SHARED RIGHT-SIDE CONTROL
Arduino D6 (PWM) ---> Driver 1 ENB
Arduino D6 (PWM) ---> Driver 2 ENB
Arduino D10 ---> Driver 1 IN3
Arduino D10 ---> Driver 2 IN3
Arduino D11 ---> Driver 1 IN4
Arduino D11 ---> Driver 2 IN4

MOTOR DRIVER 1 - FRONT MOTORS
Driver 1 OUT1 ---> Front Left Motor Terminal 1
Driver 1 OUT2 ---> Front Left Motor Terminal 2
Driver 1 OUT3 ---> Front Right Motor Terminal 1
Driver 1 OUT4 ---> Front Right Motor Terminal 2

MOTOR DRIVER 2 - REAR MOTORS
Driver 2 OUT1 ---> Rear Left Motor Terminal 1
Driver 2 OUT2 ---> Rear Left Motor Terminal 2
Driver 2 OUT3 ---> Rear Right Motor Terminal 1
Driver 2 OUT4 ---> Rear Right Motor Terminal 2

MOTOR POWER
Motor Battery Positive ---> Driver 1 Motor Supply / Vs
Motor Battery Positive ---> Driver 2 Motor Supply / Vs
Motor Battery Negative ---> Driver 1 GND
Motor Battery Negative ---> Driver 2 GND
Arduino GND ---> Driver 1 GND
Arduino GND ---> Driver 2 GND
```

### Important Power Notes
- Do **not** power the four motors from the Arduino 5V pin.
- The Arduino, both motor drivers, the HC-SR04, and the motor battery must share a common ground.
- L298N breakout boards differ in their onboard 5V regulator and `5V-EN` jumper arrangement. Follow the markings/instructions for the exact module being used. Do not connect the regulated 5V outputs of two L298N modules together.
- Remove the ENA/ENB jumper caps if PWM speed control is being supplied from Arduino D5 and D6.
- Check the voltage and stall-current requirements of the actual motors and select a suitable battery. The L298N has a noticeable voltage drop and can become hot under high current.
- Before autonomous testing, lift the chassis so the wheels are free and verify that all four motors rotate in the intended direction. Reverse the two wires of any motor that spins opposite to the expected direction.

## Code
See [`obstacle_detector.ino`](./obstacle_detector.ino).

## Working Principle
1. The HC-SR04 is mounted at the front of the robot and repeatedly measures the distance to objects ahead.
2. Arduino sends a 10 microsecond trigger pulse to start a measurement and measures the width of the returned ECHO pulse.
3. When a valid measurement shows that the path is clear, all four motors move forward.
4. If an obstacle is detected within the configured stopping distance, the robot stops.
5. The robot reverses briefly to create turning space.
6. It then performs a pivot turn by driving the left-side motors forward and right-side motors backward.
7. After turning, it stops briefly and takes another ultrasonic measurement before deciding whether to move forward again.
8. If the ultrasonic reading times out or is invalid, the program stops the robot rather than assuming that the path is clear.

> This is a simple front-sensor avoidance algorithm. It does not map the surroundings or compare left and right distances. A later advanced version can add a servo-mounted ultrasonic sensor for directional scanning.

## Use Cases
- Autonomous mobile-robot demonstrations
- Obstacle-avoidance lessons
- Sensor-based navigation experiments
- Robotics workshops
- Delivery-robot prototypes
- Warehouse-robot concepts
- STEM competitions and projects
