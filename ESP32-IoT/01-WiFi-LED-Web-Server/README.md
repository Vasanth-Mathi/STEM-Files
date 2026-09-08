# ESP32 Wi-Fi LED Control Using Web Server

## Description
Controls an LED from a web page served directly by an ESP32 connected to a Wi-Fi network.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| GPIO 23 | LED anode through 220 Ω resistor |
| GND | LED cathode |

## Code
See [`wifi_led_web_server.ino`](./wifi_led_web_server.ino).

## Working Principle
1. The ESP32 connects to the configured Wi-Fi network.
2. A small web server starts on port 80.
3. Opening the ESP32 IP address shows ON and OFF controls.
4. The web requests change the LED connected to GPIO 23.

## Use Cases
- Wi-Fi basics
- Embedded web-server lessons
- Remote output control
- IoT introduction
