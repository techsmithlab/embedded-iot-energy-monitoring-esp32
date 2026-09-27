# Wi-Fi Setup

Edit `firmware/smart_energy_monitor/config.h` (copy from
`config.example.h`, which is the template - `config.h` is gitignored):

```cpp
#define WIFI_SSID       "YOUR_WIFI_NAME"
#define WIFI_PASSWORD   "YOUR_WIFI_PASSWORD"
```

ESP32 only supports 2.4GHz Wi-Fi.

## Behavior

- `wifiInit()` attempts connection for up to `WIFI_CONNECT_TIMEOUT_MS`
  (default 15s) at boot, printing progress dots.
- If it can't connect in time, the firmware still boots (sensors/LCD/relay
  work offline) and retries in the background via `wifiHandle()`.
- Reconnect attempts happen every `WIFI_RECONNECT_INTERVAL_MS` (10s
  default) while disconnected.

## Testing in isolation

Use `test/wifi_test/wifi_test.ino` before running the full firmware.
