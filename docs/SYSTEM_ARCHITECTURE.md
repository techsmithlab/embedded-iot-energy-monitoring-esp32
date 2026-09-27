# System Architecture

```
Power Source
   |
   v
Sensors (ZMPT101B, ACS712)
   |
   v
Signal Conditioning
   |
   v
ESP32 ADC
   |
   v
Signal Processing (offset removal, RMS)
   |
   v
Voltage / Current
   |
   v
Power (apparent; real if synchronized sampling is implemented)
   |
   v
Energy (accumulated over time)
   |
   v
LCD + IoT (ThingSpeak / Blynk)
   |
   v
Remote Monitoring
```

See [../diagrams/system_block_diagram.md](../diagrams/system_block_diagram.md)
and [../diagrams/signal_flow.md](../diagrams/signal_flow.md).

## Firmware module map

| Module | Responsibility |
|---|---|
| `smart_energy_monitor.ino` | Top-level coordination / main loop |
| `config.h` | Pins, calibration constants, credential placeholders |
| `sensors.h/.cpp` | ADC sampling, RMS calculation |
| `display.h/.cpp` | 16x2 I2C LCD screens |
| `relay_control.h/.cpp` | Relay driver, fail-safe logic, serial commands |
| `energy.h/.cpp` | Energy accumulation, NVS persistence |
| `wifi_manager.h/.cpp` | Wi-Fi connect/reconnect/status |
| `cloud.h/.cpp` | ThingSpeak upload, optional Blynk |
| `calibration.h/.cpp` | Interactive zero-offset calibration |

## Why apparent power, not (yet) real power

Voltage and current are sampled sequentially, not simultaneously, so the
firmware computes apparent power `S = Vrms x Irms` (VA) as an
approximation of real power `P = average(v(t) x i(t))` (W). See
[LIMITATIONS.md](LIMITATIONS.md).
