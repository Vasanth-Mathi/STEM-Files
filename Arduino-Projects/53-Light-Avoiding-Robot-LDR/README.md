# Light Avoiding Robot Using LDR Sensors

## Description
A four-wheel robot that moves away from bright light using two LDR sensors. The Arduino compares the light falling on the left and right sensors and steers the robot toward the darker side.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| LDR / Photoresistor | 2 |
| 10 kΩ Resistor | 2 |
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
| 5V | Left LDR and Right LDR |
| GND | Both 10 kΩ resistors |
| A0 | Left LDR and Left 10 kΩ resistor junction |
| A1 | Right LDR and Right 10 kΩ resistor junction |
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

## Code
See [`light_avoiding_robot.ino`](./light_avoiding_robot.ino).

## Working Principle
1. The two LDR circuits measure light on the left and right sides of the robot.
2. A higher analog reading means more light with the wiring used in this project.
3. If the left side is brighter, the robot turns right.
4. If the right side is brighter, the robot turns left.
5. If both sides are strongly illuminated, the robot moves backward.
6. If the light level is low, the robot moves forward.

## Use Cases
- Light-response experiments
- Autonomous robot demonstrations
- LDR sensor lessons
- STEM robotics activities
