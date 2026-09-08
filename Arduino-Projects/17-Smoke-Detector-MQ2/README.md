# Smoke Detector Using MQ-2 Sensor

## Description
An educational smoke detector using an MQ-2 sensor module. Arduino monitors the analog sensor output and activates an LED and buzzer when the reading exceeds a selected threshold.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| MQ-2 Smoke / Gas Sensor Module | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | MQ-2 VCC and Buzzer Module VCC |
| GND | MQ-2 GND, Buzzer Module GND and LED cathode (-) |
| A0 | MQ-2 AO |
| D8 | 220 Ω resistor ---> LED anode (+) |
| D9 | Buzzer Module SIG |

> This is an educational prototype and must not replace a certified smoke alarm.

## Code
See [`smoke_detector.ino`](./smoke_detector.ino).

## Working Principle
1. The MQ-2 sensor responds to smoke and several combustible gases.
2. Arduino reads its analog output through A0.
3. When the sensor reading rises above the chosen threshold, the alarm turns ON.
4. The Serial Monitor can be used to observe values and choose a suitable threshold.
5. The sensor requires warm-up before readings become stable.

## Use Cases
- Smoke-sensor demonstrations
- Alarm-system prototypes
- Analog sensor lessons
- STEM safety projects
