# ThingSpeak Setup

## 1. Account creation
Create a free account at https://thingspeak.com.

## 2. Channel creation
Create a new channel (e.g. "ESP32 Smart Energy Monitor").

## 3. Fields

| Field | Label |
|---|---|
| Field 1 | Voltage |
| Field 2 | Current |
| Field 3 | Power |
| Field 4 | Energy |
| Field 5 | Relay State |
| Field 6 | Wi-Fi RSSI |
| Field 7 | Apparent Power |
| Field 8 | System Status |

## 4. API key
Open the channel's API Keys tab, copy the Write API Key.

## 5. ESP32 configuration

```cpp
#define THINGSPEAK_ENABLED     1
#define THINGSPEAK_API_KEY     "YOUR_THINGSPEAK_WRITE_API_KEY"
#define THINGSPEAK_CHANNEL_ID  "YOUR_CHANNEL_ID"
```

Never commit real values - `config.h` is gitignored.

## 6. Upload
`cloudUploadThingSpeak()` runs every `CLOUD_UPLOAD_INTERVAL_MS` (15000ms
default). Free-tier ThingSpeak enforces a minimum 15s interval.

## 7. Dashboard verification
Open the channel's Private/Public View to see live charts per field.

## 8. Troubleshooting
- No data: check Wi-Fi first, then API key/channel ID.
- HTTP error printed to Serial: cross-check against ThingSpeak's API docs.
- Updates rejected: ensure `CLOUD_UPLOAD_INTERVAL_MS` >= 15000.
