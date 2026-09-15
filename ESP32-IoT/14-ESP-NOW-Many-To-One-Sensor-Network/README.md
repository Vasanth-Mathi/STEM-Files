# ESP32 Many-to-One Wireless Sensor Network Using ESP-NOW

## Description

Several ESP32 sensor nodes send their readings to one gateway ESP32. Each sensor node has a unique node ID, allowing the gateway to identify which board produced each reading.

```text
ESP32 Sensor Node 1 ---\
ESP32 Sensor Node 2 ----> ESP32 Gateway ---> Serial Monitor
ESP32 Sensor Node 3 ---/
```

## Components

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 3 or more |
| DHT11 Sensor Module | One per sensor node |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Sensor Nodes - Senders

Repeat this wiring for every sensor node.

| Sensor Node Pin | Connect To |
|---|---|
| 3.3V | DHT11 VCC |
| GND | DHT11 GND |
| GPIO 4 | DHT11 DATA |

### ESP32 Gateway - Receiver

The gateway does not require an external sensor.

| Gateway Connection | Connect To |
|---|---|
| USB / suitable power | Gateway power |

## Code

- **Sensor Node Sender:** [`sensor_node_sender.ino`](./sensor_node_sender.ino)
- **Gateway Receiver:** [`gateway_receiver.ino`](./gateway_receiver.ino)

Change `NODE_ID` in the sender sketch for each additional sensor board.

## Working Principle

1. Every sensor node reads its own DHT11.
2. Each node adds its unique `NODE_ID` to the packet.
3. Sensor nodes broadcast their packets through ESP-NOW.
4. The gateway receives packets from all nodes.
5. The gateway prints the node ID, temperature, humidity, and sequence number.

## Software Requirements

- ESP32 board package by Espressif Systems
- DHT sensor library

## Use Cases

- Wireless sensor networks
- Environmental monitoring
- Many-to-one communication
- Gateway concepts
