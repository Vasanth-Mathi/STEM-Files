# ESP32 One-Way Sensor Communication Using ESP-NOW

## Description
Sends DHT11 temperature and humidity wirelessly from one ESP32 to another ESP32 using ESP-NOW without a Wi-Fi router.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 2 |
| DHT11 Sensor Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| Sender 3.3V | DHT11 VCC |
| Sender GND | DHT11 GND |
| Sender GPIO 4 | DHT11 DATA |

> Replace `receiverMac` with the MAC address printed by the receiving ESP32.
> Both ESP32 boards must use the same ESP-NOW channel.

## Code
See [`espnow_one_way_sensor.ino`](./espnow_one_way_sensor.ino).

## Working Principle
1. Set `SENDER_MODE` to `true` for the sensor ESP32 and enter the receiver MAC address.
2. Set `SENDER_MODE` to `false` for the receiving ESP32.
3. Both devices use the same ESP-NOW Wi-Fi channel.
4. The sender transmits temperature and humidity every two seconds and the receiver prints them in Serial Monitor.

## Use Cases
- ESP32-to-ESP32 communication
- Wireless sensor nodes
- ESP-NOW introduction
- Router-free telemetry
