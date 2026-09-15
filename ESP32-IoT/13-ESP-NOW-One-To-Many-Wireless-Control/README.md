# ESP32 One-to-Many Wireless Control Using ESP-NOW

## Description

One controller ESP32 sends the same command to several receiver ESP32 boards. In this example, one push button controls three LEDs on three separate receiver boards.

```text
                    ---> ESP32 2 Receiver ---> LED
ESP32 1 Controller ---> ESP32 3 Receiver ---> LED
                    ---> ESP32 4 Receiver ---> LED
```

## Components

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 4 |
| Push Button | 1 |
| LED | 3 |
| 220 Ω Resistor | 3 |
| Jumper Wires | As required |

## Circuit Connections

### ESP32 1 - Controller Sender

| ESP32 1 Pin | Connect To |
|---|---|
| GPIO 4 | Push button to GND |
| GND | Button GND |

### ESP32 2, ESP32 3 and ESP32 4 - Receivers

Use the same wiring on every receiver.

| Receiver Pin | Connect To |
|---|---|
| GPIO 23 | LED anode through 220 Ω resistor |
| GND | LED cathode |

## Code

- **ESP32 1 Controller:** [`controller_sender.ino`](./controller_sender.ino)
- **ESP32 2 / 3 / 4 Receivers:** [`receiver.ino`](./receiver.ino)

Upload the same receiver sketch to all receiver boards.

## Working Principle

1. ESP32 1 reads the push button.
2. The controller broadcasts the ON/OFF state.
3. Every receiver on the same ESP-NOW channel receives the packet.
4. Each receiver checks the project identifier.
5. All three LEDs change together.

## Use Cases

- One-to-many wireless communication
- Distributed classroom displays
- Wireless lighting demonstrations
- ESP-NOW broadcast experiments
