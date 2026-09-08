# ESP32 Wi-Fi Access Point with Local Control Page

## Description
Creates its own Wi-Fi network and controls an LED from a local web page without using a router or Internet connection.

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
See [`wifi_access_point_control.ino`](./wifi_access_point_control.ino).

## Working Principle
1. The ESP32 creates the Wi-Fi network ESP32-Control.
2. A phone or laptop connects directly to that network.
3. The ESP32 hosts a local control page at its access-point IP address.
4. The page controls the LED without Internet access.

## Use Cases
- Soft-AP demonstrations
- Offline wireless control
- Local IoT networks
- Wi-Fi networking lessons
