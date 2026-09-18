# Gas Leakage Detector Using MQ-5 Gas Sensor

## Description
An educational gas-leakage detector using an MQ-5 gas sensor module. The Arduino monitors the sensor value and activates an LED and buzzer when the reading rises above a chosen threshold.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| MQ-5 Gas Sensor Module | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | MQ-5 VCC and Buzzer Module VCC |
| GND | MQ-5 GND, Buzzer Module GND and LED cathode (-) |
| A0 | MQ-5 AO |
| D8 | 220 Ω resistor ---> LED anode (+) |
| D9 | Buzzer Module SIG |

> This is an educational prototype, not a certified gas-leak alarm. MQ sensors need warm-up and calibration for meaningful measurements.

## Code
See [`gas_leakage_detector.ino`](./gas_leakage_detector.ino).

## Working Principle
1. The MQ-5 sensor changes its output when combustible gas concentration changes.
2. Arduino reads the analog output on A0.
3. When the reading rises above the set threshold, the LED and buzzer turn ON.
4. When the reading falls below the threshold, the alarm turns OFF.
5. The threshold must be adjusted after allowing the sensor to warm up.

## Use Cases
- Gas-sensor demonstrations
- Kitchen safety prototypes
- Industrial safety lessons
- Analog sensor experiments
