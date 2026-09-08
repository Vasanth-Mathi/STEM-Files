# ESP32 Wi-Fi Weather Dashboard Using DHT11 and BMP280

## Description
Shows temperature, humidity, and atmospheric pressure on a simple web dashboard hosted by the ESP32.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| DHT11 Sensor Module | 1 |
| BMP280 Sensor Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 3.3V | DHT11 VCC and BMP280 VCC |
| GND | DHT11 GND and BMP280 GND |
| GPIO 4 | DHT11 DATA |
| GPIO 21 | BMP280 SDA |
| GPIO 22 | BMP280 SCL |

> Some BMP280 modules use I2C address `0x77`. If the sensor is not detected, check the module address.

## Code
See [`wifi_weather_dashboard.ino`](./wifi_weather_dashboard.ino).

## Working Principle
1. The ESP32 connects to Wi-Fi.
2. The DHT11 provides temperature and humidity.
3. The BMP280 provides atmospheric pressure.
4. A browser opening the ESP32 IP address sees the latest sensor values.

## Use Cases
- Weather-station prototypes
- Environmental monitoring
- Web-dashboard lessons
- Multi-sensor IoT practice
