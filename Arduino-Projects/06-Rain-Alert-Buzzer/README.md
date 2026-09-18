# Rain Alert Using Buzzer

## Description
A simple rain-detection project that uses the digital output of a rain sensor module. When water is detected on the sensor plate, Arduino sounds an active buzzer.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Rain Sensor Module with Sensor Plate | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Rain Sensor VCC and Buzzer Module VCC |
| GND | Rain Sensor GND and Buzzer Module GND |
| D2 | Rain Sensor DO |
| D8 | Buzzer Module SIG |

> Adjust the rain-sensor module's onboard sensitivity control if required. Change `RAIN_DETECTED_STATE` if your module uses opposite digital logic.

## Code
See [`rain_alert_buzzer.ino`](./rain_alert_buzzer.ino).

## Working Principle
1. Water on the rain-sensor plate changes its electrical behaviour.
2. The sensor module compares the reading with its adjusted threshold.
3. The module changes the digital output when rain or water is detected.
4. Arduino reads the signal through D2.
5. The buzzer sounds while water is detected.

## Use Cases
- Rain-alert demonstrations
- Weather-sensor lessons
- Water-detection experiments
- Beginner alarm systems
