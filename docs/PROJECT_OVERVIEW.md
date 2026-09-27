# Project Overview

**Title:** Embedded IoT Architecture for Real-Time Electrical Energy Acquisition, Monitoring & Telemetry
**Alternative description:** ESP32-Based IoT Smart Energy Monitoring and Load Control System
**Domain:** Embedded Systems + IoT + Electrical Energy Monitoring + Load Control
**Status:** Prototype / Development

## Purpose

1. Measure AC voltage using ZMPT101B.
2. Measure AC current using ACS712ELC-20A.
3. Process sensor data on the ESP32.
4. Calculate electrical power.
5. Calculate accumulated energy consumption.
6. Display measurements on a 16x2 I2C LCD.
7. Control an electrical load through a JQC3F-05VDC-C relay.
8. Send measurement data through ESP32 Wi-Fi.
9. Provide cloud/IoT monitoring using ThingSpeak and/or Blynk.
10. Provide a foundation for remote electrical energy monitoring and load control.

## Scope boundaries

This is a prototype and learning project. It is explicitly not: a
certified or calibrated energy meter, a production-ready mains device, or
a substitute for a qualified electrician when working with 230V AC. See
[SAFETY.md](SAFETY.md) and [LIMITATIONS.md](LIMITATIONS.md).
