# Digital Dice Using LEDs

## Description
A digital dice project that uses seven LEDs arranged like the dots on a normal dice. Pressing the button generates a random number from 1 to 6 and displays the matching dot pattern.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| LED | 7 |
| 220 Ω Resistor | 7 |
| Push Button | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| GND | Push Button second pin and all LED cathodes (-) |
| D2 | 220 Ω resistor ---> LED 1 anode (+) |
| D3 | 220 Ω resistor ---> LED 2 anode (+) |
| D4 | 220 Ω resistor ---> LED 3 anode (+) |
| D5 | 220 Ω resistor ---> LED 4 anode (+) |
| D6 | 220 Ω resistor ---> LED 5 anode (+) |
| D7 | 220 Ω resistor ---> LED 6 anode (+) |
| D8 | 220 Ω resistor ---> LED 7 anode (+) |
| D9 | Push Button first pin |

## Code
See [`digital_dice_leds.ino`](./digital_dice_leds.ino).

## Working Principle
1. The seven LEDs are arranged in the same positions as dots on a dice face.
2. Arduino waits for the push button to be pressed.
3. A random number from 1 to 6 is generated.
4. The code turns ON the LED pattern that represents that number.
5. The result stays visible until the next button press.

## Use Cases
- Probability activities
- Electronic games
- Random-number lessons
- Interactive STEM projects
