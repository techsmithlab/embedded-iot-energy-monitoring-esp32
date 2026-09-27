# Power Architecture

## Development power (current setup)

```
Laptop USB
    |
    +---- ESP32 USB
           |
           +---- 5V low-voltage electronics
```

The ESP32 is powered via USB from a laptop during development. This is a
development/test power source, not the final production power supply.

## Alternative: regulated 5V distribution

```
5V DC
 |
 +---- ESP32 5V/VIN
 +---- ACS712 VCC
 +---- Relay VCC
 +---- LCD VCC as appropriate
```

## Common ground

```
ESP32 GND
 |
 +---- ACS712 GND
 +---- ZMPT101B GND
 +---- Relay GND
 +---- LCD GND
```

## Important cautions

- Do not connect the ESP32 USB 5V rail and an external 5V source to the
  same rail in a way that could cause back-feeding.
- Protective earth must never be connected to ESP32 GND.
- Low-voltage electronics must remain isolated from dangerous mains
  conductors at all times.
