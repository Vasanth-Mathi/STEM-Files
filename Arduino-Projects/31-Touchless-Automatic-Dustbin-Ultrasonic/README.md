# Touchless Automatic Dustbin Using Ultrasonic Sensor

## Description
A touchless dustbin model that uses an HC-SR04 ultrasonic sensor to detect a hand. When a hand comes close, a servo opens the lid and closes it after a short delay.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Small Hobby Servo Motor | 1 |
| Dustbin / Model Lid | 1 |
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

> This beginner circuit powers one small hobby servo from Arduino 5V. Use a good USB power source. If the Arduino resets or the servo jitters under load, the servo needs a separate suitable 5V supply with common GND.

## Code
See [`touchless_automatic_dustbin.ino`](./touchless_automatic_dustbin.ino).

## Working Principle
1. The ultrasonic sensor continuously checks for a nearby hand.
2. When the measured distance is within the opening range, Arduino rotates the servo to open the lid.
3. The lid stays open briefly.
4. The servo then returns to the closed position.
5. A short delay prevents repeated rapid opening.

## Use Cases
- Touchless bins
- Hygiene projects
- Ultrasonic sensor demonstrations
- Servo automation lessons
