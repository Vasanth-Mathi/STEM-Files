# Push Button Controlled LED

## Description
A simple beginner Arduino project that uses a push button as an input and an LED as an output. When the button is pressed, Arduino turns the LED ON.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Push Button | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| GND | Push button terminal and LED cathode (-) |
| D2 | Other push button terminal |
| D8 | 220 Ω resistor ---> LED anode (+) |

> The sketch uses Arduino's internal pull-up resistor, so an external button resistor is not required.

## Code
See [`push_button_led.ino`](./push_button_led.ino).

## Working Principle
1. Arduino keeps D2 HIGH using the internal pull-up resistor.
2. Pressing the button connects D2 to GND.
3. Arduino reads the button as LOW.
4. The program turns the LED ON while the button is pressed.
5. Releasing the button turns the LED OFF.

## Use Cases
- Learning digital input
- Learning digital output
- Push-button experiments
- Beginner Arduino lessons
