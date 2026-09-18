# Flame Detector Using Flame Sensor

## Description
A simple flame-detection prototype that uses a flame sensor module. When the sensor detects flame-related infrared light, Arduino turns ON an LED and buzzer.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Flame Sensor Module | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | Flame Sensor VCC and Buzzer Module VCC |
| GND | Flame Sensor GND, Buzzer Module GND and LED cathode (-) |
| D2 | Flame Sensor DO |
| D8 | 220 Ω resistor ---> LED anode (+) |
| D9 | Buzzer Module SIG |

> This is an educational prototype and must not replace a certified fire detector.

> Change `FLAME_DETECTED_STATE` if your sensor module uses opposite output logic.

## Code
See [`flame_detector.ino`](./flame_detector.ino).

## Working Principle
1. The flame sensor continuously checks for infrared light in its detection range.
2. The module produces a digital output when the set detection level is reached.
3. Arduino reads this output through D2.
4. When a flame is detected, the LED and buzzer turn ON.
5. When no flame is detected, both outputs turn OFF.

## Use Cases
- Flame-sensor lessons
- Fire-detection prototypes
- Safety-system demonstrations
- STEM experiments
