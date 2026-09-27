# ThingSpeak Integration

See [../../docs/THINGSPEAK_SETUP.md](../../docs/THINGSPEAK_SETUP.md) for
the full setup guide.

## Fields used

| Field | Data |
|---|---|
| Field 1 | Voltage |
| Field 2 | Current |
| Field 3 | Power |
| Field 4 | Energy |
| Field 5 | Relay State |
| Field 6 | Wi-Fi RSSI |
| Field 7 | Apparent Power |
| Field 8 | System Status |

## Implementation

Upload logic lives in `firmware/smart_energy_monitor/cloud.cpp`
(`cloudUploadThingSpeak()`), using `HTTPClient` to perform a GET request
against `THINGSPEAK_SERVER` with all 8 fields as query parameters.
Configure `THINGSPEAK_API_KEY` and `THINGSPEAK_CHANNEL_ID` in
`firmware/smart_energy_monitor/config.h` (never commit real values).
