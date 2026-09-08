# Edge Detection Robot Using IR Sensors

## Description
A four-wheel robot that detects the edge of a table or platform using two downward-facing IR sensors. When an edge is detected, the robot reverses and turns away from the edge.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| IR Sensor Module | 2 |
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
| 5V | Left IR VCC and Right IR VCC |
| GND | Left IR GND and Right IR GND |
| D2 | Left IR OUT |
| D3 | Right IR OUT |
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

> Test the IR output over the actual surface first. Change `FLOOR_STATE` if your modules use opposite logic.

## Code
See [`edge_detection_robot.ino`](./edge_detection_robot.ino).

## Working Principle
1. The two IR sensors point downward toward the floor or table surface.
2. When both sensors detect the surface, the robot moves forward.
3. If the left sensor reaches an edge, the robot reverses and turns right.
4. If the right sensor reaches an edge, the robot reverses and turns left.
5. If both sensors detect an edge, the robot reverses and pivots before moving again.

## Use Cases
- Edge-avoidance robots
- Table-top robotics
- IR reflection lessons
- STEM robotics activities
