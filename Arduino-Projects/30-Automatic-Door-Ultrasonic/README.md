# Automatic Door Opening System Using Ultrasonic Sensor

## Description
An automatic door model that uses an HC-SR04 ultrasonic sensor to detect a person approaching. When someone comes within the set distance, a servo opens the model door and closes it again when the area is clear.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Small Hobby Servo Motor | 1 |
| Model Door / Cardboard Mechanism | 1 |
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
See [`automatic_door_opening.ino`](./automatic_door_opening.ino).

## Working Principle
1. The ultrasonic sensor measures the distance in front of the model door.
2. If a person or object is detected within the opening distance, Arduino turns the servo to the open angle.
3. When the path is clear again, Arduino returns the servo to the closed angle.
4. Invalid ultrasonic readings do not open the door.

## Use Cases
- Automatic door models
- Contactless entry demonstrations
- Ultrasonic sensor lessons
- Servo motor projects
