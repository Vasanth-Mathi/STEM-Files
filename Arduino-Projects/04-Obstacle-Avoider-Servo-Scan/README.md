# 4-Wheel Obstacle Avoiding Robot with Servo-Mounted Ultrasonic Sensor

## Description
This project builds an autonomous four-wheel obstacle avoiding robot using an Arduino Uno, an HC-SR04 ultrasonic sensor mounted on a hobby servo, four DC geared motors, and **two L298N dual H-bridge motor-driver modules**.

Unlike a basic obstacle avoider that only looks straight ahead, this version can rotate the ultrasonic sensor to look left, centre, and right. When an obstacle is detected in front, the robot stops, reverses slightly, scans both sides, compares the available space, and turns toward the side with the greater measured distance.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Hobby Servo (such as SG90 or equivalent) | 1 |
| L298N Dual H-Bridge Motor Driver Module | 2 |
| DC Geared Motor | 4 |
| Wheel | 4 |
| 4-Wheel Robot Chassis | 1 |
| Suitable Motor Battery Pack | 1 |
| Regulated 5 V Supply for Servo | 1 |
| Jumper Wires | As required |
| Servo mounting bracket / sensor holder | 1 |

## Circuit Connections

```text
HC-SR04 ULTRASONIC SENSOR
VCC ---> Arduino 5V
GND ---> Arduino GND
TRIG ---> Arduino D2
ECHO ---> Arduino D3

SERVO
Servo Signal ---> Arduino D4
Servo VCC ---> External Regulated 5V Supply Positive
Servo GND ---> External Regulated 5V Supply GND
External Servo Supply GND ---> Arduino GND

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

### Important Power and Wiring Notes
- Do **not** power the four DC motors from the Arduino 5V pin.
- Power the servo from a suitable regulated 5 V supply rather than relying on the Arduino 5 V rail during robot operation.
- Arduino GND, both L298N grounds, motor-battery negative, and servo-supply ground must all be connected together as a common reference.
- Do not connect the regulated 5 V outputs from two L298N modules together.
- Remove the ENA and ENB jumper caps from both L298N modules when Arduino D5 and D6 are used for PWM speed control.
- Mount the HC-SR04 firmly on the servo so the sensor points approximately straight ahead when the servo is at the centre angle.
- Servo mounting direction differs between chassis designs. If the programmed left and right scan angles are physically reversed, swap the `LEFT_ANGLE` and `RIGHT_ANGLE` values in the code.
- Before placing the robot on the floor, lift the chassis and verify that all four wheels rotate in the intended direction.

## Code
See [`obstacle_avoider_servo_scan.ino`](./obstacle_avoider_servo_scan.ino).

## Working Principle
1. The ultrasonic sensor normally faces forward at the servo centre position.
2. Arduino repeatedly measures the distance directly in front of the robot.
3. If the path is clear, all four motors move forward.
4. When an obstacle is detected within the configured stopping distance, the robot stops.
5. It reverses briefly to create turning space and stops again.
6. The servo turns the HC-SR04 toward the left and Arduino measures the available distance.
7. The servo then turns the HC-SR04 toward the right and measures again.
8. The sensor returns to the centre position.
9. If both side readings are valid, Arduino compares them and pivots toward the side with more free space.
10. If only one side returns a valid measurement, the robot turns toward that side.
11. If neither side returns a valid ultrasonic measurement, the robot remains stopped rather than assuming an unsafe path is clear.
12. The process repeats continuously.

## Use Cases
- Autonomous mobile robots
- Directional obstacle avoidance
- Sensor-scanning demonstrations
- Robotics navigation lessons
- STEM robotics projects
- Warehouse robot concepts
- Delivery robot prototypes
- Introduction to decision-making algorithms
- Servo and ultrasonic sensor integration
