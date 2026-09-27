# Wiring Guide

## ZMPT101B (voltage sensor)
| Pin | Connects to |
|---|---|
| VCC | Module-rated supply - verify exact voltage on your module first |
| GND | Common low-voltage GND |
| OUT | ESP32 GPIO34 (through signal conditioning if range requires it) |

## ACS712ELC-20A (current sensor)
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | Common low-voltage GND |
| OUT | ESP32 GPIO35 - verify output stays within 0-3.3V ADC domain |

## JQC3F-05VDC-C relay module
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | Common low-voltage GND |
| IN | ESP32 GPIO26 |

## 16x2 I2C LCD
| Pin | Connects to |
|---|---|
| VCC | Per module spec (commonly 5V) |
| GND | Common low-voltage GND |
| SDA | ESP32 GPIO21 |
| SCL | ESP32 GPIO22 |

## Power architecture (development)

```
Laptop USB
    |
    +---- ESP32 USB
           |
           +---- 5V low-voltage electronics
```

Alternative regulated 5V rail:

```
5V DC
 |
 +---- ESP32 5V/VIN
 +---- ACS712 VCC
 +---- Relay VCC
 +---- LCD VCC (as appropriate)
```

Common low-voltage ground:

```
ESP32 GND
 |
 +---- ACS712 GND
 +---- ZMPT101B GND
 +---- Relay GND
 +---- LCD GND
```

Do not connect the ESP32's USB 5V rail and an external 5V source to the
same rail in a way that could cause back-feeding.

## AC side (mains - dangerous, see [../docs/SAFETY.md](../docs/SAFETY.md))

```
3-PIN AC PLUG
 |
 +---- LIVE
 |      |
 |     FUSE
 |      |
 |   ACS712 IP+
 |      |
 |   ACS712 IP-
 |      |
 |   RELAY COM
 |      |
 |   RELAY NO
 |      |
 |    LOAD
 |
 +---- NEUTRAL -------------------- LOAD
 |
 +---- EARTH ---------------------- protective earth (never tied to ESP32 GND)
```

ZMPT101B senses AC voltage across the Line/Neutral points per its own
module design - refer to that module's own documentation. This diagram
is conceptual, not a certified electrical drawing.
