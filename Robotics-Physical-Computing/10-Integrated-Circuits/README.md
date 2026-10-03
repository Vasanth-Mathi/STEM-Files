# Integrated Circuits

> **Source note:** Component names, basic purpose, connection guidance, and example uses are based on the uploaded **Microcontroller Boards Reference** document. Short student explanations are added to make the material easier to learn. Exact pin labels, voltage limits, polarity, and module variants must be checked on the actual component before wiring.

Integrated circuits combine many electronic functions inside one package.

| No. | IC | How It Works | Basic Connection | Example Use |
|---:|---|---|---|---|
| 58 | UM3561 Tone Generator IC | Generates electronic tone/sound patterns. | Connect power/GND correctly and route its output through the required sound-driving circuit. | Sound effects and alarms |
| 59 | L293D Driver IC | Contains driver stages for controlling DC motors or stepper-motor coils from logic signals. | Controller outputs to driver inputs, motors to driver outputs, and suitable logic/motor power with common reference as required. | Motor control |
| 60 | LM358 | Dual operational amplifier used for amplification and signal conditioning. | Connect supply pins correctly, then inputs/outputs according to the chosen amplifier/filter circuit. | Amplification and filters |
| 61 | Timer IC | Generates time delays or pulses when used with the correct resistor/capacitor network. | Follow the exact timer IC datasheet and desired timing circuit. | Timing and pulse generation |
| 62 | 7805 Voltage Regulator | Regulates a suitable higher DC input down to approximately 5V within its operating limits. | Input to unregulated source, GND to ground, output to load; use recommended bypass capacitors. | Stable 5V supply |
| 63 | ULN2003 | Darlington transistor array that lets low-current logic signals control higher-current loads. | Controller outputs to ULN2003 inputs, matching outputs to loads, and connect supply/common pins as required by the load circuit. | Motors or relays |

## IC Rule
Do not wire an IC only by name. Find its pin diagram and confirm orientation before power is applied.
