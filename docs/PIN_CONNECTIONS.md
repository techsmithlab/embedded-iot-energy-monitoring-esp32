# Pin Connections

See [../hardware/pinout.md](../hardware/pinout.md) and
[../hardware/wiring.md](../hardware/wiring.md).

| Function | Module | ESP32 |
|---|---|---|
| Voltage ADC | ZMPT101B OUT | GPIO34 |
| Current ADC | ACS712 OUT | GPIO35 |
| Relay control | JQC3F IN | GPIO26 |
| LCD SDA | I2C LCD | GPIO21 |
| LCD SCL | I2C LCD | GPIO22 |
| 5V | Power | 5V/VIN |
| Ground | Common low-voltage ground | GND |

Enforced consistently in `config.h`, all `test/` sketches, and every
diagram in `diagrams/`.
