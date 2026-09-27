# Project Manifest

**Project name:** Embedded IoT Architecture for Real-Time Electrical Energy
Acquisition, Monitoring & Telemetry (ESP32-Based IoT Smart Energy
Monitoring and Load Control System)

**Version:** 0.1.0 (Prototype / Development)

**Brand:** Techsmithlab

## Hardware

- ESP32 DevKit x1
- ACS712ELC-20A current sensor module x1
- ZMPT101B voltage sensor module x1
- JQC3F-05VDC-C relay module x1
- 16x2 I2C LCD x1
- 5V USB power source (development only)

Full BOM: `hardware/BOM.md`

## Firmware

- Location: `firmware/smart_energy_monitor/`
- Framework: Arduino for ESP32
- Modules: main `.ino`, `config.h`, `sensors`, `display`, `relay_control`,
  `energy`, `wifi_manager`, `cloud`, `calibration`

## Cloud platforms

- ThingSpeak (primary, 8 fields) - `cloud/thingspeak/`
- Blynk (optional, 7 virtual pins, disabled by default) - `cloud/blynk/`

## Pin mapping

| Function | Module | ESP32 |
|---|---|---|
| Voltage ADC | ZMPT101B OUT | GPIO34 |
| Current ADC | ACS712 OUT | GPIO35 |
| Relay control | JQC3F IN | GPIO26 |
| LCD SDA | I2C LCD | GPIO21 |
| LCD SCL | I2C LCD | GPIO22 |
| 5V | Power | 5V/VIN |
| Ground | Common low-voltage ground | GND |

## Known test status

**Completed / tested:**
- ESP32 connected to laptop via USB
- Relay module tested and confirmed operating
- ACS712 zero-current ADC test: raw ADC ~2928-2942, ~2.36-2.37V observed

**Not yet completed:**
- Full 230V AC measurement
- Final ZMPT101B voltage calibration
- Full ACS712 current calibration under known load
- Accurate real-power measurement
- Power-factor-aware real power measurement
- Long-term energy accuracy validation
- Final mains enclosure validation
- Electrical safety certification
- Production deployment

## Known limitations

See `docs/LIMITATIONS.md` for the full list - summary: calibration
factors are placeholders, apparent power is used as a real-power
approximation, and this is not a certified energy meter.

## File structure

```
embedded-iot-energy-monitoring-esp32/
├── README.md
├── LICENSE
├── .gitignore
├── CHANGELOG.md
├── CONTRIBUTING.md
├── PROJECT_MANIFEST.md
├── firmware/smart_energy_monitor/
│   ├── smart_energy_monitor.ino
│   ├── config.h / config.example.h
│   ├── sensors.h/.cpp
│   ├── display.h/.cpp
│   ├── relay_control.h/.cpp
│   ├── energy.h/.cpp
│   ├── wifi_manager.h/.cpp
│   ├── cloud.h/.cpp
│   └── calibration.h/.cpp
├── test/
│   ├── relay_test/relay_test.ino
│   ├── lcd_test/lcd_test.ino
│   ├── acs712_test/acs712_test.ino
│   ├── zmpt101b_test/zmpt101b_test.ino
│   └── wifi_test/wifi_test.ino
├── hardware/
│   ├── BOM.md
│   ├── pinout.md
│   ├── wiring.md
│   └── wiring_notes.md
├── diagrams/
│   ├── system_block_diagram.md
│   ├── signal_flow.md
│   ├── power_flow.md
│   └── cloud_flow.md
├── docs/
│   ├── PROJECT_OVERVIEW.md, SYSTEM_ARCHITECTURE.md, COMPONENTS.md
│   ├── PIN_CONNECTIONS.md, CIRCUIT_DESCRIPTION.md, POWER_ARCHITECTURE.md
│   ├── SENSOR_CALIBRATION.md, ENERGY_CALCULATION.md, RELAY_CONTROL.md
│   ├── WIFI_SETUP.md, THINGSPEAK_SETUP.md, BLYNK_SETUP.md
│   ├── TESTING.md, TROUBLESHOOTING.md, SAFETY.md, LIMITATIONS.md
│   ├── FUTURE_ENHANCEMENTS.md, ABSTRACT.md, LINKEDIN_POST.md
│   └── PRESENTATION_CONTENT.md, VIVA_QA.md
├── cloud/thingspeak/README.md, cloud/blynk/README.md
├── examples/serial_output.txt, examples/calibration_example.txt
└── screenshots/README.md
```
