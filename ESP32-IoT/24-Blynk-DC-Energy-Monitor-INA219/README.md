# ESP32 Blynk IoT DC Energy Monitoring Prototype Using INA219

## Description
Measures low-voltage DC bus voltage, current, power, and accumulated energy with an INA219 sensor and displays the values in Blynk.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| INA219 Current Sensor Module | 1 |
| Low-Voltage DC Load | 1 |
| Low-Voltage DC Supply | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 3.3V | INA219 VCC |
| GND | INA219 GND |
| GPIO 21 | INA219 SDA |
| GPIO 22 | INA219 SCL |
| INA219 VIN+ | Positive side of low-voltage supply |
| INA219 VIN- | Positive input of the DC load |

> Use only a safe low-voltage DC circuit for this student project. Do not use this circuit to measure household mains electricity.

## Code
See [`blynk_dc_energy_monitor_ina219.ino`](./blynk_dc_energy_monitor_ina219.ino).

## Working Principle
1. The INA219 measures DC bus voltage and current.
2. The sketch calculates power and integrates it over time to estimate watt-hours.
3. Voltage, current, power, and energy are sent to Blynk V0 to V3.
4. The project stays on low-voltage DC instead of requiring students to work with mains electricity.

## Use Cases
- Energy-monitoring lessons
- Current and power experiments
- Blynk data visualization
- Low-voltage electronics
