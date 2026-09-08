# ESP32 Multi-Sensor Smart Agriculture System Using Blynk IoT

## Description
Combines temperature, humidity, soil moisture, rain detection, and pump control in one Blynk-based agriculture monitoring system.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| DHT11 Sensor Module | 1 |
| Capacitive Soil Moisture Sensor | 1 |
| Rain Sensor Module | 1 |
| L298N Motor Driver Module | 1 |
| DC Water Pump | 1 |
| Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 3.3V | DHT11 VCC, soil sensor VCC, and rain sensor VCC |
| GND | All sensor GND pins and L298N GND |
| GPIO 4 | DHT11 DATA |
| GPIO 34 | Soil sensor analog output |
| GPIO 27 | Rain sensor digital output |
| GPIO 25 | L298N IN1 |
| GPIO 26 | L298N IN2 |
| Motor Battery + | L298N motor-power input |
| Motor Battery - | L298N GND |
| Pump | L298N OUT1 and OUT2 |

> Calibrate the soil-moisture threshold and rain-sensor polarity for the modules used in class.
> Keep the L298N enable jumper fitted for this simple ON/OFF pump-control version.

## Code
See [`blynk_smart_agriculture_system.ino`](./blynk_smart_agriculture_system.ino).

## Working Principle
1. Temperature, humidity, soil moisture, and rain status are sent to V0 through V3.
2. V4 enables automatic irrigation and V5 provides manual pump control.
3. Automatic irrigation starts the pump only when soil is dry and rain is not detected.
4. The project combines sensing, decision-making, cloud monitoring, and physical action.

## Use Cases
- Smart agriculture
- Multi-sensor IoT
- Irrigation automation
- Agriculture STEM demonstrations
