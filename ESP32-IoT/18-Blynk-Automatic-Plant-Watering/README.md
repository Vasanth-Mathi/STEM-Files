# ESP32 Blynk IoT Automatic Plant Watering System

## Description
Monitors soil moisture in Blynk and automatically controls a small water pump through a motor driver when the soil becomes dry.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| Capacitive Soil Moisture Sensor | 1 |
| L298N Motor Driver Module | 1 |
| DC Water Pump | 1 |
| Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 3.3V | Soil sensor VCC |
| GND | Soil sensor GND and L298N GND |
| GPIO 34 | Soil sensor analog output |
| GPIO 26 | L298N IN1 |
| GPIO 27 | L298N IN2 |
| Motor Battery + | L298N motor-power input |
| Motor Battery - | L298N GND |
| Pump | L298N OUT1 and OUT2 |

> Calibrate `DRY_THRESHOLD` using readings from your actual soil and sensor.
> Keep the L298N enable jumper fitted for this simple ON/OFF pump-control version.

## Code
See [`blynk_automatic_plant_watering.ino`](./blynk_automatic_plant_watering.ino).

## Working Principle
1. The ESP32 sends the soil-moisture reading to Blynk virtual pin V0.
2. V1 selects automatic or manual mode.
3. In automatic mode, the pump starts when the soil reading crosses the dry threshold.
4. In manual mode, V2 directly controls the pump.

## Use Cases
- Smart irrigation
- Blynk dashboard practice
- Plant-care automation
- Soil-moisture experiments
