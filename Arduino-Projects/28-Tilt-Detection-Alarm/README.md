# Tilt Detection Alarm Using Tilt Sensor

## Description
A tilt alarm that uses a simple ball tilt switch. When the switch changes position and closes the circuit, Arduino activates an LED and buzzer.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Ball Tilt Sensor / Tilt Switch | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| GND | One wire of Tilt Sensor, Buzzer Module GND and LED cathode (-) |
| 5V | Buzzer Module VCC |
| D2 | Other wire of Tilt Sensor |
| D8 | 220 Ω resistor ---> LED anode (+) |
| D9 | Buzzer Module SIG |

> Tilt switch orientation determines when the contact closes. Mount and test it in the position required for your project.

## Code
See [`tilt_detection_alarm.ino`](./tilt_detection_alarm.ino).

## Working Principle
1. Arduino uses its internal pull-up resistor on D2.
2. The tilt switch connects D2 to GND when the internal ball closes the contact.
3. When the switch closes, Arduino detects LOW on D2.
4. The LED and buzzer turn ON while the tilt condition is present.

## Use Cases
- Tilt alarms
- Anti-tamper devices
- Orientation experiments
- STEM sensor projects
