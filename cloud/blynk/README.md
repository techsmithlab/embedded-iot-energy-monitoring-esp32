# Blynk Integration (Optional)

See [../../docs/BLYNK_SETUP.md](../../docs/BLYNK_SETUP.md) for the full
setup guide.

## Virtual pins used

| Virtual Pin | Data |
|---|---|
| V0 | Voltage |
| V1 | Current |
| V2 | Power |
| V3 | Energy |
| V4 | Relay State |
| V5 | Wi-Fi RSSI |
| V6 | System Status |

## Implementation

Connection/handling logic lives in `firmware/smart_energy_monitor/cloud.cpp`,
gated behind `#if BLYNK_ENABLED` so the firmware compiles cleanly whether
or not you use Blynk. Enable via `BLYNK_ENABLED 1` in `config.h` and
install the Blynk library first.
