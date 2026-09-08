# Digital Stopwatch Using TM1637 Display

## Description
A digital stopwatch using a 4-digit TM1637 display and two push buttons. One button starts or pauses the stopwatch and the second button resets it to zero.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| 4-Digit TM1637 Display | 1 |
| Push Button | 2 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| 5V | TM1637 Display VCC |
| GND | TM1637 Display GND, Start/Stop Button second pin and Reset Button second pin |
| D2 | TM1637 CLK |
| D3 | TM1637 DIO |
| D4 | Start/Stop Button first pin |
| D5 | Reset Button first pin |

## Code
See [`digital_stopwatch_tm1637.ino`](./digital_stopwatch_tm1637.ino).

This sketch requires the **TM1637Display** library.

## Working Principle
1. Pressing the Start/Stop button toggles the stopwatch between running and paused.
2. Arduino measures elapsed time using `millis()`.
3. The display shows elapsed minutes and seconds.
4. Pressing Reset stops the stopwatch and returns the display to 00:00.
5. The stopwatch counts up to 99 minutes and 59 seconds before rolling over.

## Use Cases
- Sports timing
- Classroom experiments
- Time measurement lessons
- Arduino display projects
