# Electronic Reaction Time Game Using LED and Push Button

## Description
A reaction-time game in which the player waits for an LED to turn ON and then presses a button as quickly as possible. Arduino measures the response time in milliseconds and prints it in the Serial Monitor.

## Components

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Push Button | 1 |
| Active Buzzer Module | 1 |
| Jumper Wires | As required |

## Circuit Connections

### Arduino Connections

| Arduino Pin | Connect To |
|---|---|
| GND | Push Button second pin, LED cathode (-) and Buzzer Module GND |
| 5V | Buzzer Module VCC |
| D2 | Push Button first pin |
| D8 | 220 Ω resistor ---> LED anode (+) |
| D9 | Buzzer Module SIG |

## Code
See [`reaction_time_game.ino`](./reaction_time_game.ino).

## Working Principle
1. Arduino waits for a random period so the player cannot predict the start.
2. The LED turns ON and the buzzer gives a short start signal.
3. Arduino records the starting time.
4. The player presses the button as quickly as possible.
5. Arduino calculates the elapsed time and prints the reaction time in milliseconds.
6. A new round starts after a short pause.

## Use Cases
- Reaction-time experiments
- Human response studies
- Interactive games
- Coding lessons
