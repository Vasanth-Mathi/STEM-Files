# 4-Wheel Line Follower Robot Using IR Sensors

## Description
This project builds an autonomous four-wheel line follower robot using an Arduino Uno, two IR sensors, four DC geared motors, and **two L298N dual H-bridge motor-driver modules**.

Each DC motor is connected to its own H-bridge channel. Motor Driver 1 controls the two front motors and Motor Driver 2 controls the two rear motors. The Arduino sends the same left-side control signals to the front-left and rear-left channels, and the same right-side control signals to the front-right and rear-right channels. This keeps all four wheels coordinated while avoiding two motors being connected in parallel to one driver channel.

## Components

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| IR Sensor Module | 2 |
| L298N Dual H-Bridge Motor Driver Module | 2 |
| DC Geared Motor | 4 |
| Wheel | 4 |
| 4-Wheel Robot Chassis | 1 |
| Suitable Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

```text
IR SENSORS
Left IR VCC ---> Arduino 5V
Left IR GND ---> Arduino GND
Left IR OUT ---> Arduino D2

Right IR VCC ---> Arduino 5V
Right IR GND ---> Arduino GND
Right IR OUT ---> Arduino D3

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
- The Arduino, both motor drivers, and the motor battery must share a common ground.
- L298N breakout boards differ in their onboard 5V regulator and `5V-EN` jumper arrangement. Follow the markings/instructions for the exact module being used. Do not tie two module 5V regulator outputs together.
- Remove the ENA/ENB jumper caps if PWM speed control is being supplied from Arduino D5 and D6.
- Before autonomous testing, raise the chassis so the wheels are free and verify that all four motors rotate in the intended forward direction. If one motor runs backward, reverse that motor's two output wires.

## Code
See [`line_follower_ir.ino`](./line_follower_ir.ino).

## Working Principle
The two IR sensors are mounted at the front of the chassis so that, when the robot is correctly centred, the black line runs between the sensors and both sensors see the lighter floor.

1. The two IR modules continuously sense the floor.
2. In this project configuration, the program assumes the sensor output becomes `LOW` when that sensor detects the black line and `HIGH` on the lighter floor.
3. When neither sensor sees the black line, all four motors move forward.
4. If the left sensor detects the black line, the robot has drifted toward the right side of the path, so the left-side motors are slowed and the robot steers left.
5. If the right sensor detects the black line, the right-side motors are slowed and the robot steers right.
6. If both sensors detect black at the same time, the program stops the robot. This may represent a wide line, junction, or end marker depending on the track design.
7. Motor Driver 1 controls the front pair and Motor Driver 2 controls the rear pair, while shared Arduino control signals keep the left motors and right motors synchronized.

> IR modules can use different output polarity depending on their comparator circuit and calibration. Verify the sensor output using the Serial Monitor or module indicator LED before running the robot. If the module outputs `HIGH` on black, change `BLACK_STATE` in the code from `LOW` to `HIGH`.

## Use Cases
- Line-following robotics
- Automated guided vehicle demonstrations
- Warehouse transport concepts
- Factory material movement models
- Autonomous navigation experiments
- Sensor-feedback lessons
- STEM robotics competitions
