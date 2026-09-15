# ESP32 Two-Way Communication Using ESP-NOW

## Description

This project uses **two ESP32 boards that both send and receive data**. Each board has one push button and one LED. Pressing the button on ESP32 1 controls the LED on ESP32 2, while pressing the button on ESP32 2 controls the LED on ESP32 1.

```text
ESP32 1 Button ---> ESP32 1 ~~~> ESP32 2 ---> ESP32 2 LED
ESP32 2 Button ---> ESP32 2 ~~~> ESP32 1 ---> ESP32 1 LED
```

## Components

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 2 |
| Push Button | 2 |
| LED | 2 |
| 220 Ω Resistor | 2 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 1

| ESP32 1 Pin | Connect To |
|---|---|
| GPIO 4 | Push button to GND |
| GPIO 23 | LED anode through 220 Ω resistor |
| GND | LED cathode and button GND |

### ESP32 2

| ESP32 2 Pin | Connect To |
|---|---|
| GPIO 4 | Push button to GND |
| GPIO 23 | LED anode through 220 Ω resistor |
| GND | LED cathode and button GND |

The buttons use `INPUT_PULLUP`, so no external pull-up resistor is required.

## Code

Upload the correct sketch to each board:

- **ESP32 1:** [`esp32_1.ino`](./esp32_1.ino)
- **ESP32 2:** [`esp32_2.ino`](./esp32_2.ino)

Both sketches use the same packet format but different device IDs.

## Working Principle

1. Each ESP32 reads its own button.
2. Each board broadcasts its button state using ESP-NOW.
3. The receiving board ignores packets sent by itself.
4. The received button state controls the local LED.
5. Communication therefore works in both directions.

## Use Cases

- Bidirectional wireless control
- Interactive classroom models
- ESP-NOW peer communication
- Remote input/output experiments
