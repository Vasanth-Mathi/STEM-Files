# Quiz Buzzer System Using Push Buttons and LEDs

## Description
A four-player quiz buzzer system. The first player to press a button locks the system, turns ON that player's LED, and sounds the buzzer. Other player buttons are ignored until the reset button is pressed.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| Push Button for Players | 4 |
| Reset Push Button | 1 |
| LED | 4 |
| 220 Ω Resistor | 4 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| GND | Second pin of all 5 push buttons, all LED cathodes (-) and Buzzer Module GND |
| 5V | Buzzer Module VCC |
| D2 | Player 1 Button first pin |
| D3 | Player 2 Button first pin |
| D4 | Player 3 Button first pin |
| D5 | Player 4 Button first pin |
| D6 | 220 Ω resistor ---> Player 1 LED anode (+) |
| D7 | 220 Ω resistor ---> Player 2 LED anode (+) |
| D8 | 220 Ω resistor ---> Player 3 LED anode (+) |
| D9 | 220 Ω resistor ---> Player 4 LED anode (+) |
| D10 | Buzzer Module SIG |
| D11 | Reset Button first pin |

## Code
See [`quiz_buzzer_system.ino`](./quiz_buzzer_system.ino).

## Working Principle
1. Arduino continuously checks the four player buttons.
2. The first button detected becomes the winning buzzer.
3. Arduino turns ON only that player's LED and sounds the buzzer briefly.
4. The system locks so later button presses cannot change the result.
5. Pressing the reset button clears the winner and starts a new round.

## Use Cases
- Classroom quizzes
- STEM competitions
- Reaction games
- Digital input lessons
