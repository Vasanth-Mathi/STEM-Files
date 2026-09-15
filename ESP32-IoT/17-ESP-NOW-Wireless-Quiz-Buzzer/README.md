# ESP32 Wireless Classroom Quiz Buzzer Using ESP-NOW

## Description

This project uses several ESP32 player units and one ESP32 host. Each player has a push button. The host records the **first valid button packet** and ignores later players until the teacher presses reset.

```text
Player ESP32 1 ---\
Player ESP32 2 ----> Host ESP32 ---> Winner LED + Buzzer
Player ESP32 3 ---/
```

## Components

| Component | Quantity |
|---|---:|
| ESP32 Dev Module | 3 or more |
| Player Push Button | One per player |
| Winner LED | 1 |
| 220 Ω Resistor | 1 |
| Active Buzzer | 1 |
| Reset Push Button | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Player ESP32 Boards - Senders

Use the same wiring on each player unit.

| Player ESP32 Pin | Connect To |
|---|---|
| GPIO 4 | Player button to GND |
| GND | Button GND |

### Host ESP32 - Receiver

| Host ESP32 Pin | Connect To |
|---|---|
| GPIO 23 | Winner LED through 220 Ω resistor |
| GPIO 22 | Active buzzer signal |
| GPIO 19 | Reset push button to GND |
| GND | LED cathode, buzzer GND, reset-button GND |

## Code

- **Player Sender:** [`player_sender.ino`](./player_sender.ino)
- **Host Receiver:** [`host_receiver.ino`](./host_receiver.ino)

Upload `player_sender.ino` to every player board and change `PLAYER_ID` so every player has a different number.

## Working Principle

1. A player presses a button.
2. The player ESP32 sends its `PLAYER_ID`.
3. The host accepts the first valid packet.
4. The host lights the winner LED, sounds the buzzer, and prints the player number.
5. Later packets are ignored until the host reset button is pressed.

## Use Cases

- Classroom quiz systems
- Wireless competitions
- First-response logic
- Event-based ESP-NOW networks
