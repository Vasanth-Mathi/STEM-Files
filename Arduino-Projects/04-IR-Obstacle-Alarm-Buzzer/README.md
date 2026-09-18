# IR Obstacle Alarm Using Buzzer

## Description
A beginner project that connects an IR obstacle sensor to an active buzzer. Arduino sounds the buzzer when the sensor detects a nearby object.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| IR Obstacle Sensor Module | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | IR Sensor VCC and Buzzer Module VCC |
| GND | IR Sensor GND and Buzzer Module GND |
| D2 | IR Sensor DO |
| D8 | Buzzer Module SIG |

> Many IR obstacle modules output LOW when an object is detected. Change `OBJECT_DETECTED_STATE` if your module uses opposite logic.

## Code
See [`ir_obstacle_buzzer.ino`](./ir_obstacle_buzzer.ino).

## Working Principle
1. The IR sensor checks for a nearby reflecting object.
2. Its digital output changes when an object is detected.
3. Arduino reads the sensor through D2.
4. Arduino turns the buzzer ON when an object is detected.
5. The buzzer turns OFF when the path is clear.

## Use Cases
- Simple obstacle alarms
- Sensor-and-output lessons
- Proximity warning demonstrations
- Beginner Arduino experiments
