# Resistors

> **Source note:** Component names, basic purpose, connection guidance, and example uses are based on the uploaded **Microcontroller Boards Reference** document. Short student explanations are added to make the material easier to learn. Exact pin labels, voltage limits, polarity, and module variants must be checked on the actual component before wiring.

Resistors limit current, divide voltage, set logic levels, and help bias electronic circuits.

| No. | Resistor | How It Works | Typical Connection / Role | Example Use |
|---:|---|---|---|---|
| 39 | 220 Ω | Limits current by resisting electrical flow. | Commonly placed in series with an LED. | LED current limiting |
| 40 | 330 Ω | Same basic resistor behaviour with a higher resistance value. | Series current limiting where suitable. | LED protection |
| 41 | 470 Ω | Limits current more than 220/330 Ω. | Series resistor in suitable signal/output circuits. | Current limiting |
| 42 | 1 kΩ | Useful for signal limiting, transistor-base networks, and dividers. | Connect according to the circuit requirement. | Signal/current limiting |
| 43 | 4.7 Ω | Low-value resistor listed in the source reference. | Use only where the circuit specifically calls for this value and power rating. | Circuit-specific current control |
| 44 | 10 kΩ | Common value for pull-up, pull-down, and divider circuits. | Between a signal and VCC/GND, or as part of a divider. | Buttons and sensor circuits |
| 45 | 47 kΩ | Higher-value resistor useful where smaller currents are required. | Circuit-dependent divider or bias network. | Signal conditioning |
| 46 | 100 kΩ | High resistance useful in dividers and biasing. | Circuit-dependent. | Voltage divider/bias |
| 47 | 1 MΩ | Very high resistance that allows only a small current. | Used where the design specifically needs high impedance. | Biasing or high-value divider |

## Resistor Reminder
A resistor value alone is not enough for every design. Power rating and circuit purpose also matter.
