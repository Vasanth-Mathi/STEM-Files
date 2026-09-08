# ESP32 Internet Clock Using Wi-Fi, NTP and OLED Display

## Description
Gets accurate time from an Internet time server and displays it on a small OLED screen.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| 0.96-inch I2C OLED Display | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 3.3V | OLED VCC |
| GND | OLED GND |
| GPIO 21 | OLED SDA |
| GPIO 22 | OLED SCL |

> `GMT_OFFSET_SECONDS` is set for India Standard Time. Change it when using the project in another time zone.

## Code
See [`wifi_internet_clock_ntp.ino`](./wifi_internet_clock_ntp.ino).

## Working Principle
1. The ESP32 connects to Wi-Fi.
2. It synchronizes time using NTP through `configTime()`.
3. The current time is read from the ESP32 system clock.
4. The OLED is refreshed every second.

## Use Cases
- Digital clock projects
- NTP lessons
- Internet-connected displays
- Time-based automation foundations
