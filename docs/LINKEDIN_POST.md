# LinkedIn Post

**Embedded IoT Architecture for Real-Time Electrical Energy Acquisition,
Monitoring & Telemetry**

I've been building an ESP32-based smart energy monitoring and load
control prototype - combining embedded systems, analog sensing, and IoT
telemetry in one project.

What it does:
- Senses AC voltage (ZMPT101B) and AC current (ACS712ELC-20A)
- Processes readings on an ESP32, calculating power and accumulated
  energy consumption
- Displays live readings on a 16x2 I2C LCD
- Controls a connected load through a JQC3F-05VDC-C relay, with a
  fail-safe default-OFF startup state
- Streams telemetry over Wi-Fi to ThingSpeak (and optionally Blynk)

Where it stands today:
Relay control, LCD display, and the ACS712's zero-current baseline have
all been tested and confirmed working. Full sensor calibration, safe
live-AC-load testing, and power-factor-aware real power measurement are
still in progress - an honest work-in-progress, not a finished product.

What I'm taking from it:
Hands-on experience with embedded ADC signal processing, RMS calculation,
IoT cloud telemetry pipelines, and how to approach mains-adjacent
electronics safely and methodically.

#ESP32 #IoT #EmbeddedSystems #EnergyMonitoring #SmartEnergy #ACS712
#ZMPT101B #Arduino #ThingSpeak #Blynk #WiFi #Relay #Electronics
#EnergyMeter #Telemetry

- Techsmithlab
