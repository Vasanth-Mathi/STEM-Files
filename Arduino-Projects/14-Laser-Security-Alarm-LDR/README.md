# Laser Security Alarm Using LDR Sensor

## Description
A security alarm prototype in which a laser beam is aimed at an LDR sensor. When the beam is interrupted, the Arduino detects the drop in light level and activates a buzzer.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| 5V Laser Module | 1 |
| LDR / Photoresistor | 1 |
| 10 kΩ Resistor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Laser Module VCC and one side of LDR |
| GND | Laser Module GND, Buzzer Module GND and one side of 10 kΩ resistor |
| A0 | Other side of LDR and other side of 10 kΩ resistor |
| D9 | Buzzer Module SIG |

> Use only a low-power classroom laser module. Never point a laser toward eyes.

> Adjust `LASER_THRESHOLD` after checking the actual LDR readings.

## Code
See [`laser_security_alarm.ino`](./laser_security_alarm.ino).

## Working Principle
1. The laser continuously shines on the LDR.
2. The LDR and 10 kΩ resistor form a voltage divider read by A0.
3. When the laser reaches the LDR, the analog value stays high with this wiring.
4. If a person or object blocks the beam, the light level falls.
5. When the reading goes below the set threshold, Arduino turns ON the buzzer.

## Use Cases
- Security alarm models
- Beam-break detection
- Light sensor experiments
- STEM demonstrations
