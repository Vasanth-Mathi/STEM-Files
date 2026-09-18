# Ultrasonic Distance Alarm Using Buzzer

## Description
A simple distance-alarm project using an HC-SR04 ultrasonic sensor and an active buzzer. The buzzer sounds when an object comes within the selected distance.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | HC-SR04 VCC and Buzzer Module VCC |
| GND | HC-SR04 GND and Buzzer Module GND |
| D2 | HC-SR04 TRIG |
| D3 | HC-SR04 ECHO |
| D8 | Buzzer Module SIG |

## Code
See [`ultrasonic_distance_buzzer.ino`](./ultrasonic_distance_buzzer.ino).

## Working Principle
1. Arduino triggers the HC-SR04 sensor.
2. The sensor returns an echo pulse.
3. Arduino converts the echo time into distance.
4. If a valid object distance is at or below `ALERT_DISTANCE_CM`, the buzzer turns ON.
5. The buzzer remains OFF for invalid readings or objects outside the alert range.

## Use Cases
- Distance alarms
- Parking-assistance demonstrations
- Proximity-warning systems
- Ultrasonic-sensor lessons
