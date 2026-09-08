# Automatic Hand Sanitizer Dispenser Using Ultrasonic Sensor

## Description
A touchless hand-sanitizer dispenser model that uses an HC-SR04 ultrasonic sensor to detect a hand. A servo briefly moves a lever that presses the sanitizer pump.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Small Hobby Servo Motor | 1 |
| Sanitizer Bottle with Pump | 1 |
| Simple Servo Pressing Mechanism | 1 |
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
See [`automatic_hand_sanitizer.ino`](./automatic_hand_sanitizer.ino).

## Working Principle
1. The ultrasonic sensor measures the distance to a hand.
2. When a hand is detected within the set range, Arduino moves the servo to press the pump.
3. The servo holds the press briefly and then returns to the resting position.
4. A cooldown delay prevents repeated dispensing while the same hand remains in place.

## Use Cases
- Touchless sanitizer dispensers
- Hygiene automation
- Ultrasonic sensor projects
- Servo mechanism lessons
