# ESP32 Blynk IoT Greenhouse Automation System Using DHT11

## Description
Monitors greenhouse temperature and humidity and controls a ventilation fan automatically or manually through Blynk.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| DHT11 Sensor Module | 1 |
| L298N Motor Driver Module | 1 |
| DC Fan | 1 |
| Motor Battery Pack | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 3.3V | DHT11 VCC |
| GND | DHT11 GND and L298N GND |
| GPIO 4 | DHT11 DATA |
| GPIO 26 | L298N IN1 |
| GPIO 27 | L298N IN2 |
| Motor Battery + | L298N motor-power input |
| Motor Battery - | L298N GND |
| Fan | L298N OUT1 and OUT2 |

> Keep the L298N enable jumper fitted for this simple ON/OFF fan-control version.

## Code
See [`blynk_greenhouse_automation.ino`](./blynk_greenhouse_automation.ino).

## Working Principle
1. The DHT11 sends temperature to V0 and humidity to V1.
2. V2 enables automatic fan control.
3. In automatic mode, temperature hysteresis turns the fan on above the high threshold and off below the low threshold.
4. V3 provides manual fan control when automatic mode is disabled.

## Use Cases
- Greenhouse ventilation
- Temperature-control lessons
- Blynk environmental automation
- Hysteresis demonstrations
