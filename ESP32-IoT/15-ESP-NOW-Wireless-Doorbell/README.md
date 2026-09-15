# ESP32 Wireless Doorbell Using ESP-NOW

## Description

This project uses two ESP32 boards to build a router-free wireless doorbell. ESP32 1 is placed near the door with a push button. ESP32 2 receives the ring command and activates an LED and active buzzer.

```text
Button ---> ESP32 1 Sender ~~~ ESP-NOW ~~~> ESP32 2 Receiver ---> LED + Buzzer
```

## Components

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 2 |
| Push Button | 1 |
| Active Buzzer Module | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 1 - Doorbell Sender

| ESP32 1 Pin | Connect To |
|---|---|
| GPIO 4 | Push button to GND |
| GND | Button GND |

### ESP32 2 - Doorbell Receiver

| ESP32 2 Pin | Connect To |
|---|---|
| GPIO 23 | LED anode through 220 Ω resistor |
| GPIO 22 | Active buzzer signal input |
| GND | LED cathode and buzzer GND |
| 3.3V or suitable module supply | Buzzer VCC, according to module rating |

> Use a low-current active buzzer module that is compatible with ESP32 logic. A high-current buzzer should be driven through a transistor or MOSFET.

## Code

- **ESP32 1 Sender:** [`doorbell_sender.ino`](./doorbell_sender.ino)
- **ESP32 2 Receiver:** [`doorbell_receiver.ino`](./doorbell_receiver.ino)

## Working Principle

1. ESP32 1 debounces the doorbell push button.
2. A valid button press sends one ring packet.
3. ESP32 2 checks the packet identifier.
4. The receiver turns on the LED and buzzer for a short time.
5. No Wi-Fi router is required.

## Use Cases

- Wireless doorbells
- Event-based communication
- Home-automation prototypes
- ESP-NOW demonstrations
