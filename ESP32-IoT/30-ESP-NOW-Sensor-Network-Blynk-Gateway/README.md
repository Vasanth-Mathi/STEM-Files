# ESP32 ESP-NOW Sensor Network with Blynk IoT Gateway

## Description

This project combines local ESP-NOW communication with cloud IoT monitoring. One or more ESP32 sensor nodes send DHT11 readings to a gateway ESP32. The gateway stays connected to Wi-Fi and forwards the received values to Blynk.

```text
DHT11 ---> Sensor ESP32 ---\
DHT11 ---> Sensor ESP32 ----> ESP-NOW ---> Gateway ESP32 ---> Wi-Fi ---> Blynk
DHT11 ---> Sensor ESP32 ---/
```

The gateway and sensor nodes must operate on the **same 2.4 GHz Wi-Fi channel**.

## Components

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 2 or more |
| DHT11 Sensor Module | One per sensor node |
| 2.4 GHz Wi-Fi Network | 1 |
| Blynk account / template | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Sensor ESP32 Boards - Senders

| Sensor ESP32 Pin | Connect To |
|---|---|
| 3.3V | DHT11 VCC |
| GND | DHT11 GND |
| GPIO 4 | DHT11 DATA |

Repeat this wiring for every sensor node.

### Gateway ESP32 - Receiver

The gateway requires no external sensor.

| Gateway Connection | Connect To |
|---|---|
| USB / suitable power | Gateway ESP32 |
| Wi-Fi | 2.4 GHz network used by Blynk |

## Code

- **Sensor Node Sender:** [`sensor_node_sender.ino`](./sensor_node_sender.ino)
- **Blynk Gateway Receiver:** [`blynk_gateway_receiver.ino`](./blynk_gateway_receiver.ino)

### Before Uploading

1. Enter the Blynk Template ID, Template Name, Auth Token, Wi-Fi name, and Wi-Fi password in the gateway sketch.
2. Upload the gateway sketch first.
3. Open Serial Monitor and note the gateway's Wi-Fi channel.
4. Set `ESPNOW_CHANNEL` in every sensor-node sketch to the same channel.
5. Give each sensor node a unique `NODE_ID`.
6. Configure Blynk datastreams:
   - `V0` = Node ID
   - `V1` = Temperature
   - `V2` = Humidity

## Working Principle

1. The gateway connects to Wi-Fi and Blynk.
2. ESP-NOW starts on the same Wi-Fi radio/channel.
3. Sensor nodes read their DHT11 sensors.
4. Nodes broadcast packets containing node ID, temperature, and humidity.
5. The gateway receives the packet.
6. The gateway forwards the values to Blynk virtual pins.

## Software Requirements

- ESP32 board package by Espressif Systems
- DHT sensor library
- Blynk library

## Use Cases

- IoT gateways
- Wireless sensor networks
- ESP-NOW + cloud integration
- Smart agriculture and environmental monitoring
