# ESP32 One-Way Sensor Communication Using ESP-NOW

## Description

This project uses **two ESP32 boards**. ESP32 1 reads temperature and humidity from a DHT11 sensor and sends the values wirelessly using ESP-NOW. ESP32 2 receives the packet and displays the readings in Serial Monitor.

```text
DHT11 ---> ESP32 1 Sender ~~~ ESP-NOW ~~~> ESP32 2 Receiver ---> Serial Monitor
```

Both boards must use the same ESP-NOW channel.

## Components

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 2 |
| DHT11 Sensor Module | 1 |
| Jumper Wires | As required |
| USB cable / suitable power source | 2 |

## Circuit Connections

### ESP32 1 - Sender

| ESP32 1 Pin | Connect To |
|---|---|
| 3.3V | DHT11 VCC |
| GND | DHT11 GND |
| GPIO 4 | DHT11 DATA |

### ESP32 2 - Receiver

No external sensor is required.

| ESP32 2 Connection | Connect To |
|---|---|
| USB / suitable power | ESP32 2 power |
| GND | No additional connection required |

## Code

Upload the files separately:

- **ESP32 1 Sender:** [`esp32_sender.ino`](./esp32_sender.ino)
- **ESP32 2 Receiver:** [`esp32_receiver.ino`](./esp32_receiver.ino)

The sketches use ESP-NOW broadcast packets with a project-specific identifier, so a receiver ignores unrelated packets.

## Working Principle

1. ESP32 1 reads the DHT11 every two seconds.
2. It places temperature, humidity, and a sequence number in a packet.
3. ESP32 1 broadcasts the packet through ESP-NOW.
4. ESP32 2 checks that the packet belongs to this project.
5. The receiver prints the readings in Serial Monitor.

## Software Requirements

- ESP32 board package by Espressif Systems
- DHT sensor library
- Arduino-ESP32 3.x API style

## Use Cases

- Wireless sensor nodes
- ESP32-to-ESP32 communication
- Router-free telemetry
- Classroom ESP-NOW demonstrations
