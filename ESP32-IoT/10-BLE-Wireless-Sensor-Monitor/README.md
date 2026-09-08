# ESP32 BLE Wireless Temperature and Humidity Monitor Using DHT11

## Description
Publishes DHT11 temperature and humidity as BLE notifications that can be viewed on a BLE client application.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| DHT11 Sensor Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 3.3V | DHT11 VCC |
| GND | DHT11 GND |
| GPIO 4 | DHT11 DATA |

## Code
See [`ble_wireless_sensor_monitor.ino`](./ble_wireless_sensor_monitor.ino).

## Working Principle
1. The ESP32 starts a BLE service named `ESP32-Sensor`.
2. A phone or computer connects to the BLE device.
3. The DHT11 is read every two seconds.
4. Temperature and humidity are sent as notification text through the BLE characteristic.

## Use Cases
- BLE sensor lessons
- Phone-based monitoring
- Wireless telemetry
- Environmental sensing
