# Output Devices

> **Source note:** Component names, basic purpose, connection guidance, and example uses are based on the uploaded **Microcontroller Boards Reference** document. Short student explanations are added to make the material easier to learn. Exact pin labels, voltage limits, polarity, and module variants must be checked on the actual component before wiring.

Output devices turn electrical control signals into light, sound, or another visible/audible result.

| No. | Output Device | How It Works | Basic Connection | Example Use |
|---:|---|---|---|---|
| 25 | IR LED Pair | Emits infrared light that can carry a coded signal. | Use a suitable digital output and current-limiting arrangement as required by the transmitter circuit. | Remote-control transmission |
| 26 | Red LED | Emits red light when current flows in the correct direction. | Use a current-limiting resistor and correct LED polarity. | Alert/error indicator |
| 27 | Green LED | Emits green light when current flows. | Use a current-limiting resistor and correct polarity. | Normal-operation indicator |
| 28 | Blue LED | Emits blue light when current flows. | Use a current-limiting resistor and correct polarity. | Visual effects/status |
| 29 | Yellow LED | Emits yellow light when current flows. | Use a current-limiting resistor and correct polarity. | Warning/state indicator |
| 30 | White LED | Emits white light when current flows. | Use a current-limiting resistor and correct polarity. | General indication/lighting |
| 31 | RGB LED | Contains red, green, and blue light elements that can be combined to produce colours. | Connect common anode/cathode as appropriate and control each colour pin through suitable current limiting. | Mood/status lighting |
| 32 | Buzzer Big | Converts electrical energy into an audible tone/alarm. | Reference connects the buzzer to a digital control output and GND; verify whether the actual buzzer requires a driver. | Audible alerts |
| 33 | 5W Speaker | Converts an audio electrical signal into sound. | Use an appropriate amplifier/audio source; do not drive a 5W speaker directly from a microcontroller pin. | Music, speech, sound effects |
| 34 | Piezoelectric Plate | Produces voltage when mechanically stressed and can also respond mechanically to applied electrical signals depending on use. | Connect according to the intended sensing/generation circuit and protect controller inputs from unsuitable voltages. | Vibration/energy experiments |

## LED Reminder
LEDs need correct polarity and current limiting. A controller pin is a signal source, not an unlimited power supply.
