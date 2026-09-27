# Relay Control

Hardware: JQC3F-05VDC-C, ESP32 control pin GPIO26.

## Logic polarity

Configurable via `RELAY_ACTIVE_HIGH` in `config.h` - not assumed. Verify
with `test/relay_test/relay_test.ino` before trusting the default.

## API

```cpp
void relayInit();
void relayOn();
void relayOff();
void relayToggle();
bool getRelayState();
void relayHandleSerialCommand(const String &cmd); // "ON"/"OFF"/"STATUS"
```

## Fail-safe behavior

- Relay always defaults to OFF at boot (`RELAY_DEFAULT_STATE_OFF`).
- Wi-Fi failure does not automatically turn the relay ON.
- Invalid sensor readings do not automatically enable a load - relay
  state only changes via explicit serial commands.

## Serial test commands

`ON`, `OFF`, `STATUS` (115200 baud).

## Safety

The relay's mains-side COM/NO/NC terminals are always dangerous once
wired to the load circuit. See [SAFETY.md](SAFETY.md).
