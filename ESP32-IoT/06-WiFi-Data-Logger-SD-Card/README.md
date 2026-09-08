# ESP32 Wi-Fi Data Logger Using DHT11 and SD Card

## Description
Records temperature and humidity with Internet-synchronized timestamps to a CSV file on a microSD card.

## Components

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| DHT11 Sensor Module | 1 |
| MicroSD Card Module | 1 |
| MicroSD Card | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 Connections

| ESP32 Pin / Connection | Connect To |
|---|---|
| 3.3V | DHT11 VCC |
| GND | DHT11 GND and SD GND |
| GPIO 4 | DHT11 DATA |
| GPIO 5 | SD CS |
| GPIO 18 | SD SCK |
| GPIO 19 | SD MISO |
| GPIO 23 | SD MOSI |
| SD VCC | Use the voltage required by your SD module |

> MicroSD modules differ. Check whether your module expects 3.3 V or includes its own regulator/level shifting before wiring VCC.

## Code
See [`wifi_data_logger_sd_card.ino`](./wifi_data_logger_sd_card.ino).

## Working Principle
1. The ESP32 connects to Wi-Fi and synchronizes its clock.
2. The DHT11 is read once every minute.
3. Each reading is saved to `data.csv` on the microSD card.
4. The timestamp lets students compare values over time.

## Use Cases
- Environmental data logging
- CSV datasets
- Long-term experiments
- IoT data-collection lessons
