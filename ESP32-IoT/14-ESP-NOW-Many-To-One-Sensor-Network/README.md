# ESP32 Many-to-One Wireless Sensor Network Using ESP-NOW

## Description
Uses several ESP32 sensor nodes to send temperature and humidity readings to one gateway ESP32.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 3 or more |
| DHT11 Sensor Module | For each sensor node |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| Each sensor-node 3.3V | DHT11 VCC |
| Each sensor-node GND | DHT11 GND |
| Each sensor-node GPIO 4 | DHT11 DATA |

> Give every sensor node a different `NODE_ID` and use the same gateway MAC address and ESP-NOW channel.

## Code
See [`espnow_many_to_one_sensor_network.ino`](./espnow_many_to_one_sensor_network.ino).

## Working Principle
1. Set `SENSOR_NODE_MODE` to `true` on sensor nodes and assign each a unique `NODE_ID`.
2. Enter the gateway MAC address in every sensor node.
3. Set `SENSOR_NODE_MODE` to `false` on the gateway ESP32.
4. The gateway receives readings from all nodes and identifies each reading using its node ID.

## Use Cases
- Wireless sensor networks
- Many-to-one communication
- Environmental monitoring networks
- ESP-NOW gateway concepts
