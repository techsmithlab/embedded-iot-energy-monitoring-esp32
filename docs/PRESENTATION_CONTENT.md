# Presentation Content (12-15 slides)

## Slide 1 - Title
Embedded IoT Architecture for Real-Time Electrical Energy Acquisition,
Monitoring & Telemetry (ESP32-Based IoT Smart Energy Monitoring and Load
Control System)

## Slide 2 - Domain
Embedded Systems + IoT + Electrical Energy Monitoring + Load Control

## Slide 3 - Problem Statement
Consumers and small facilities often lack accessible, real-time
visibility into their electrical energy usage, making it hard to
identify waste or control loads remotely without expensive proprietary
metering hardware.

## Slide 4 - Objectives
Measure AC voltage/current, process on ESP32, display locally, control
load via relay, stream telemetry to a cloud dashboard.

## Slide 5 - Existing Systems
Commercial smart meters exist but are often costly, proprietary, and not
easily extensible for hobbyist/academic experimentation.

## Slide 6 - Proposed System
Modular ESP32 firmware combining sensor acquisition, local display,
relay-based load control, and dual-path cloud telemetry.

## Slide 7 - Components
ESP32 DevKit, ACS712ELC-20A, ZMPT101B, JQC3F-05VDC-C relay, 16x2 I2C LCD.

## Slide 8 - Block Diagram
See diagrams/system_block_diagram.md.

## Slide 9 - Circuit / Pin Connections
GPIO34=ZMPT101B, GPIO35=ACS712, GPIO26=Relay, GPIO21/22=LCD I2C.

## Slide 10 - Working Principle
Analog signals -> ESP32 ADC -> offset removal -> RMS -> power -> energy
-> display + upload.

## Slide 11 - Software Architecture
Modular firmware: sensors, display, relay_control, energy, wifi_manager,
cloud, calibration.

## Slide 12 - IoT / Cloud Architecture
ESP32 -> Wi-Fi -> ThingSpeak (8 fields) and/or Blynk (7 virtual pins) ->
dashboard.

## Slide 13 - Testing
Relay and LCD tested and working. ACS712 zero-current baseline observed
and stable. Full calibration and live-load testing pending.

## Slide 14 - Results / Current Status
Prototype/development stage; digital subsystems validated, analog
calibration and safe mains testing are next milestones.

## Slide 15 - Future Scope
Real power via synchronized sampling, power factor, overcurrent/
overvoltage protection, MQTT/Home Assistant, OTA, custom PCB/enclosure.
