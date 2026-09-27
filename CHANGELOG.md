# Changelog

All notable changes to this project are documented here.
Format loosely follows [Keep a Changelog](https://keepachangelog.com/).

## [0.1.0] - Initial prototype

### Added
- Modular ESP32 firmware: sensors, display, relay_control, energy,
  wifi_manager, cloud, calibration modules.
- ZMPT101B voltage sensing and ACS712 current sensing on GPIO34/GPIO35.
- RMS-based voltage/current calculation with configurable calibration
  constants (not yet calibrated to a reference).
- Apparent power (S = Vrms x Irms) and energy accumulation (Wh/kWh) with
  NVS persistence.
- 16x2 I2C LCD interface cycling through voltage/current, power/energy,
  and Wi-Fi/cloud status screens.
- JQC3F-05VDC-C relay control with configurable active-high/low logic and
  fail-safe default-OFF startup.
- Wi-Fi connection manager with reconnect handling.
- ThingSpeak telemetry (8 fields) and optional Blynk scaffold (7 virtual
  pins, disabled by default).
- Interactive serial calibration routine (`CAL` / `CALSTATUS` commands).
- Independent test sketches: relay, LCD, ACS712, ZMPT101B, Wi-Fi.
- Full documentation set under `docs/`, `hardware/`, and `diagrams/`.

### Tested
- Relay switching (on/off, via `test/relay_test`).
- ACS712 zero-current ADC baseline (~2928-2942 raw, ~2.36-2.37V).
- ESP32 USB-powered development workflow.

### Known limitations (see docs/LIMITATIONS.md)
- Voltage/current calibration factors are placeholders (1.0), not yet
  calibrated against a reference meter.
- Real (power-factor-aware) power calculation not yet implemented;
  apparent power is used as an approximation.
- No live 230V AC testing has been performed yet.
