# ESP32 ESP-NOW Sensor Network with Blynk IoT Gateway

## Description
Uses ESP-NOW sensor nodes for local wireless communication and one gateway ESP32 to forward received sensor data to Blynk over Wi-Fi.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 2 or more |
| DHT11 Sensor Module | For each sensor node |
| Wi-Fi Network | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| Each sensor-node 3.3V | DHT11 VCC |
| Each sensor-node GND | DHT11 GND |
| Each sensor-node GPIO 4 | DHT11 DATA |
| Gateway | No external sensor required |

> ESP-NOW devices communicating with a Wi-Fi-connected gateway must use the same 2.4 GHz channel as the gateway's Wi-Fi network. Set `ESPNOW_CHANNEL` to match.
> Replace `gatewayMac` with the gateway ESP32 station MAC address printed in Serial Monitor.
> Give each sensor node a unique `NODE_ID`.

## Code
See [`espnow_blynk_gateway.ino`](./espnow_blynk_gateway.ino).

## Working Principle
1. Set `GATEWAY_MODE` to `true` for one ESP32 and configure its Blynk and Wi-Fi credentials.
2. The gateway joins Wi-Fi, initializes ESP-NOW on the same 2.4 GHz channel, and receives sensor packets.
3. Set `GATEWAY_MODE` to `false` on sensor nodes, assign unique node IDs, and enter the gateway MAC address.
4. The gateway forwards the latest node ID, temperature, and humidity to Blynk V0, V1, and V2.

## Use Cases
- ESP-NOW and cloud integration
- IoT gateways
- Wireless sensor networks
- Advanced ESP32 communication projects
