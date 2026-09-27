# Abstract

Rising electricity demand and the need for consumers to understand and
manage their own energy usage motivate low-cost, accessible energy
monitoring solutions. This project presents an ESP32-based embedded IoT
system for real-time electrical energy acquisition, monitoring, and
telemetry, combined with basic relay-based load control.

The system uses a ZMPT101B module to sense AC line voltage and an
ACS712ELC-20A Hall-effect module to sense AC line current. The ESP32
microcontroller samples both signals, removes their DC offset, computes
RMS voltage and current, and derives apparent power and accumulated
energy consumption. Readings are displayed locally on a 16x2 I2C LCD and
transmitted over Wi-Fi to cloud platforms (ThingSpeak and, optionally,
Blynk) for remote visualization. A JQC3F-05VDC-C relay module, controlled
by the ESP32, provides basic on/off control of a connected AC load, with
a fail-safe default-OFF state at boot.

As a prototype, the system has validated its digital subsystems: relay
switching, LCD display, and ACS712 zero-current ADC behavior have all
been tested and confirmed stable. Full voltage/current calibration
against a trusted reference, safe live-load AC testing, and
power-factor-aware real-power calculation remain future work, and are
explicitly documented as not yet completed rather than assumed. Planned
extensions include synchronized voltage/current sampling for true
real-power measurement, overcurrent/overvoltage protection, and a custom
enclosure suitable for safe mains deployment.

This project is intended as an academic and portfolio demonstration of
embedded systems and IoT integration techniques, and is explicitly not
presented as a certified or production-ready energy meter.
