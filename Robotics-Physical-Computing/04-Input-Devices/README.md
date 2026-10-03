# Input Devices

> **Source note:** Component names, basic purpose, connection guidance, and example uses are based on the uploaded **Microcontroller Boards Reference** document. Short student explanations are added to make the material easier to learn. Exact pin labels, voltage limits, polarity, and module variants must be checked on the actual component before wiring.

Input devices allow a person to give commands or values to a physical-computing system.

| No. | Input Device | How It Works | Basic Connection | Example Use |
|---:|---|---|---|---|
| 20 | 4x3 Matrix Keypad | Keys connect row and column lines. The controller scans those lines to identify which key is pressed. | Connect keypad row/column lines to digital pins according to the keypad layout. | Password or security input |
| 21 | Push Button | Makes or breaks an electrical connection when pressed. | Connect one terminal to a digital input and the other to GND; use a suitable pull-up arrangement. | Start/stop/control input |
| 22 | 10k Variable Potentiometer | Acts as an adjustable voltage divider when its knob is turned. | One outer pin to 5V, the other to GND, and the centre wiper to an analog input. | Brightness or value control |
| 23 | Condenser Microphone | Converts sound pressure changes into a small electrical signal. | The reference requires biasing and an amplifier/input circuit rather than direct raw use. | Audio or voice experiments |
| 24 | Tic Tac Switch | A momentary mechanical switch used as a simple digital input. | Connect between a digital input and GND with an appropriate pull-up arrangement. | Mode or function selection |

## Student Question
For every input, ask: **Is the signal digital, analog, or encoded through several pins?**
