# ESP32 Wi-Fi Network Scanner

## Description
Scans nearby 2.4 GHz Wi-Fi networks and displays their SSID, signal strength, and security status in the Serial Monitor.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| USB Cable | 1 |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| USB | Computer for power, programming, and Serial Monitor |

## Code
See [`wifi_network_scanner.ino`](./wifi_network_scanner.ino).

## Working Principle
1. The ESP32 switches to Wi-Fi station mode.
2. It scans for nearby Wi-Fi access points.
3. Each detected network is printed with RSSI signal strength and security information.
4. The scan repeats after a short delay.

## Use Cases
- Wireless-network lessons
- Signal-strength experiments
- Wi-Fi troubleshooting practice
- ESP32 communication basics
