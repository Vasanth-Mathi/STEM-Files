# Capacitors

> **Source note:** Component names, basic purpose, connection guidance, and example uses are based on the uploaded **Microcontroller Boards Reference** document. Short student explanations are added to make the material easier to learn. Exact pin labels, voltage limits, polarity, and module variants must be checked on the actual component before wiring.

Capacitors temporarily store electrical charge. They are commonly used for filtering, smoothing, timing, and reducing electrical noise.

| No. | Capacitor | How It Works | Basic Connection / Role | Example Use |
|---:|---|---|---|---|
| 48 | 10 µF Electrolytic | Stores charge and can smooth slower supply changes. | Observe polarity; reference places positive toward the voltage side and negative toward GND in supply filtering. | Decoupling/filtering |
| 49 | 100 µF Electrolytic | Stores more charge than smaller capacitor values. | Observe polarity and voltage rating. | Supply smoothing |
| 50 | 470 µF Electrolytic | Larger energy-storage/smoothing capacitor. | Observe polarity and voltage rating. | Power-supply smoothing |
| 51 | 0.1 µF Ceramic | Responds quickly to high-frequency noise. | Often connected close to a circuit's power pins between supply and GND. | Digital decoupling |
| 52 | 1 µF Ceramic | Non-polarised capacitor useful in filtering and signal circuits. | Connect according to the circuit design. | Noise reduction |
| 53 | 0.01 µF Ceramic | Small non-polarised capacitor useful for higher-frequency filtering. | Connect according to the circuit design. | Signal/noise filtering |

## Capacitor Safety
Electrolytic capacitors are polarised. Reversing them or exceeding their voltage rating can damage the component.
