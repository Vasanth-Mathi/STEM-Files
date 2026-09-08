# ESP32 Blynk IoT Classroom Environment Monitoring System

## Description
Combines temperature, humidity, light, and sound sensing to create a simple classroom environment dashboard in Blynk.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| DHT11 Sensor Module | 1 |
| LDR / Photoresistor | 1 |
| 10 kΩ Resistor | 1 |
| Analog Sound Sensor Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 3.3V | DHT11 VCC, LDR divider supply, and sound-sensor VCC |
| GND | DHT11 GND, 10 kΩ resistor, and sound-sensor GND |
| GPIO 4 | DHT11 DATA |
| GPIO 34 | LDR and 10 kΩ resistor junction |
| GPIO 35 | Sound sensor analog output |

> The LDR and sound values are relative ADC readings. Calibrate them if you need meaningful classroom thresholds.

## Code
See [`blynk_classroom_environment_monitor.ino`](./blynk_classroom_environment_monitor.ino).

## Working Principle
1. The DHT11 measures temperature and humidity.
2. The LDR divider provides a relative light-level reading.
3. The analog sound sensor provides a relative sound-level reading.
4. Blynk displays temperature on V0, humidity on V1, light on V2, and sound on V3.

## Use Cases
- Classroom environment studies
- Multi-sensor dashboards
- STEM data collection
- Comfort-condition experiments
