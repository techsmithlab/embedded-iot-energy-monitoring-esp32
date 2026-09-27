# ESP32 Pin Table

| Function | Module | ESP32 Pin |
|---|---|---|
| Voltage ADC | ZMPT101B OUT | GPIO34 |
| Current ADC | ACS712 OUT | GPIO35 |
| Relay control | JQC3F-05VDC-C IN | GPIO26 |
| LCD SDA | I2C 16x2 LCD | GPIO21 |
| LCD SCL | I2C 16x2 LCD | GPIO22 |
| Power | 5V development supply | 5V / VIN |
| Ground | Common low-voltage ground | GND |

This mapping is used consistently across `firmware/`, `test/`, and every
doc in `docs/`.

## Low-voltage vs mains

**LOW-VOLTAGE (breadboard-safe):** ESP32<->ZMPT101B, ESP32<->ACS712,
ESP32<->Relay IN/VCC/GND, ESP32<->LCD SDA/SCL/VCC/GND.

**MAINS (dangerous - see [../docs/SAFETY.md](../docs/SAFETY.md)):** AC
plug Live/Neutral/Earth, fuse, ACS712 IP+/IP-, Relay COM/NO/NC, ZMPT101B
AC sensing terminals, load wiring.
