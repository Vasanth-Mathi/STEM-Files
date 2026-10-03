# Transistors and Diodes

> **Source note:** Component names, basic purpose, connection guidance, and example uses are based on the uploaded **Microcontroller Boards Reference** document. Short student explanations are added to make the material easier to learn. Exact pin labels, voltage limits, polarity, and module variants must be checked on the actual component before wiring.

Transistors can switch or amplify electrical signals. Diodes mainly allow current in one direction and can protect circuits from reverse voltage.

| No. | Component | How It Works | Basic Connection | Example Use |
|---:|---|---|---|---|
| 54 | NPN Transistor 2N2222 | A small base control current can control a larger collector-emitter current. | Reference: collector toward the load/supply side, emitter to GND, base through a current-limiting resistor to the control signal. Verify the actual pinout. | Switching or amplification |
| 55 | PNP Transistor 2N2907 | A PNP transistor switches from the high side using a suitable base voltage relative to its emitter. | Reference: emitter toward positive supply, collector to load, base through a resistor. Verify actual pinout. | High-side switching/amplification |
| 56 | MOSFET IRF540N | Gate voltage controls current through drain and source with very little steady gate current. | Reference: drain to load, source to GND, gate from control through a gate resistor. Verify whether the device is suitable for the controller's gate voltage. | Higher-power load switching |
| 57 | Diode 1N4007 | Conducts primarily in one direction and blocks reverse current within its ratings. | Identify the banded cathode and install according to the intended rectifier/protection circuit. | Rectification/reverse protection |

## Important
Transistor and MOSFET pin orders vary by part/package. Always check the component marking and datasheet before wiring.
