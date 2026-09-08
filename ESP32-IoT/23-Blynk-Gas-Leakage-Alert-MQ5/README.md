# ESP32 Blynk IoT Gas Leakage Alert System Using MQ5

## Description
Monitors an MQ5 gas-sensor module, activates a local buzzer, and sends a Blynk event when the calibrated gas threshold is exceeded.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| MQ5 Gas Sensor Module | 1 |
| Active Buzzer | 1 |
| Voltage-Divider Resistors | 2 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 5V / VIN | MQ5 VCC |
| GND | MQ5 GND and buzzer GND |
| MQ5 AO | Voltage divider input |
| GPIO 34 | Voltage-divider output, kept at or below 3.3 V |
| GPIO 23 | Buzzer signal |

> MQ5 modules require warm-up and calibration. `GAS_THRESHOLD` is an example value, not a universal gas concentration limit.
> Do not allow the MQ5 analog output to exceed the ESP32 ADC input range. Use a suitable voltage divider when the module is powered from 5 V.
> This project is an educational prototype and must not replace a certified gas-leak detector.

## Code
See [`blynk_gas_leakage_mq5.ino`](./blynk_gas_leakage_mq5.ino).

## Working Principle
1. The MQ5 analog level is sampled through a safe voltage divider.
2. The raw reading is sent to Blynk virtual pin V0.
3. A reading above the example threshold turns on the buzzer and logs the Blynk event `gas_alert`.
4. The alarm clears when the reading falls below the threshold.

## Use Cases
- Gas-sensor lessons
- IoT alarm prototypes
- Blynk notifications
- Safety-system demonstrations
