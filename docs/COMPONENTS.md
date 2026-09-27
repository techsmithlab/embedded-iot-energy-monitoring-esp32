# Components

See [../hardware/BOM.md](../hardware/BOM.md) for the full BOM.

- **ESP32 DevKit** - dual-core Wi-Fi/BLE microcontroller; main processing unit.
- **ACS712ELC-20A** - Hall-effect current sensor module (+-20A variant).
- **ZMPT101B** - AC voltage sensing module.
- **JQC3F-05VDC-C** - 5V-coil relay module for load switching.
- **16x2 I2C LCD** - local display.

## Why these components

ESP32 for built-in Wi-Fi/ADC/community support; ACS712 and ZMPT101B are
common, breadboard-friendly AC sensing choices for hobbyist/academic
projects; a relay gives simple on/off control for this prototype stage;
an I2C LCD keeps wiring simple (2 data pins).

Exact electrical specs for the specific modules used have not all been
independently verified - see
[../hardware/wiring_notes.md](../hardware/wiring_notes.md).
