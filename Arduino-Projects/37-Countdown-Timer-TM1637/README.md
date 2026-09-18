# Countdown Timer Using TM1637 Display

## Description
A countdown timer using a 4-digit TM1637 display. Pressing the button starts a 60-second countdown shown as minutes and seconds.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| 4-Digit TM1637 Display | 1 |
| Push Button | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | TM1637 Display VCC |
| GND | TM1637 Display GND and Push Button second pin |
| D2 | TM1637 CLK |
| D3 | TM1637 DIO |
| D4 | Push Button first pin |

## Code
See [`countdown_timer_tm1637.ino`](./countdown_timer_tm1637.ino).

This sketch requires the **TM1637Display** library.

## Working Principle
1. The display normally shows 01:00.
2. Pressing the button starts the countdown.
3. Arduino decreases the remaining time once every second.
4. The TM1637 display shows the remaining minutes and seconds.
5. When the timer reaches 00:00, it stops and waits for another button press.

## Use Cases
- Classroom timers
- Game timers
- Timing lessons
- Interactive Arduino projects
