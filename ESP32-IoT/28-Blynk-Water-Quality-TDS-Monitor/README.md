# ESP32 Blynk IoT Water Quality Monitoring Prototype Using TDS Sensor

## Description
Estimates total dissolved solids from a compatible analog TDS sensor and sends the estimated value to Blynk.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| Analog TDS Sensor Module with ESP32-safe output | 1 |
| TDS Probe | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| Sensor-rated VCC | TDS module VCC |
| GND | TDS module GND |
| GPIO 34 | TDS module analog output, kept at or below 3.3 V |

> Use a TDS interface whose analog output stays within the ESP32 ADC input range.
> The TDS equation is an educational estimate and requires calibration and temperature compensation for accurate measurement.
> This is a water-quality learning prototype, not a certified drinking-water test.

## Code
See [`blynk_water_quality_tds.ino`](./blynk_water_quality_tds.ino).

## Working Principle
1. The ESP32 averages several ADC samples from the TDS sensor.
2. The average ADC value is converted to voltage.
3. A common educational polynomial estimates TDS in parts per million.
4. V0 receives estimated TDS and V1 receives the measured input voltage.

## Use Cases
- Water-quality experiments
- TDS demonstrations
- IoT water monitoring
- Sensor calibration lessons
