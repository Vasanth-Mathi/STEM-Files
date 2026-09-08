# ESP32 Blynk IoT Air Quality Monitoring and Alert System Using MQ135

## Description
Reads an MQ135 air-quality sensor, sends the raw sensor level to Blynk, and logs an alert event when the calibrated threshold is exceeded.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| MQ135 Sensor Module | 1 |
| Voltage-Divider Resistors | 2 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 5V / VIN | MQ135 VCC |
| GND | MQ135 GND |
| MQ135 AO | Voltage divider input |
| GPIO 34 | Voltage-divider output, kept at or below 3.3 V |

> MQ135 readings depend strongly on warm-up, sensor variation, environment, and calibration. `ALERT_THRESHOLD` is only a starting value.
> Do not allow the MQ135 analog output to exceed the ESP32 ADC input range. Use a suitable voltage divider when the sensor module is powered from 5 V.
> This is an educational air-quality indicator, not a certified air-quality instrument.

## Code
See [`blynk_air_quality_mq135.ino`](./blynk_air_quality_mq135.ino).

## Working Principle
1. The ESP32 reads the MQ135 analog output through an ADC-safe voltage divider.
2. The raw value is sent to Blynk virtual pin V0.
3. When the reading rises above the example threshold, the sketch logs the Blynk event `air_quality_alert`.
4. The alert is reset after the reading returns below the threshold.

## Use Cases
- Air-quality experiments
- Blynk event notifications
- Gas-sensor calibration lessons
- Environmental monitoring
