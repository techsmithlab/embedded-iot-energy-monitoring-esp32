# Bill of Materials (BOM)

| Component | Quantity | Purpose | Voltage | Interface | Notes |
|---|---|---|---|---|---|
| ESP32 DevKit | 1 | Main controller | 5V (USB) / 3.3V logic | USB, GPIO, ADC, I2C | Any standard ESP32 DevKit with GPIO34/35/26/21/22 exposed |
| ACS712ELC-20A module | 1 | AC current sensing | 5V supply, analog out | Analog (GPIO35) | Verify OUT range vs ESP32 3.3V ADC before direct connection |
| ZMPT101B module | 1 | AC voltage sensing | Verify module-rated supply | Analog (GPIO34) | Do not assume 3.3V or 5V - check the specific module |
| JQC3F-05VDC-C relay module | 1 | Load switching | 5V coil / mains contacts | Digital (GPIO26) | Verify active-high vs active-low before trusting default config |
| 16x2 LCD with I2C backpack | 1 | Local display | Per module (commonly 5V) | I2C (GPIO21/22) | Common address 0x27 or 0x3F |
| USB cable | 1 | Programming + dev power | 5V | USB | Development only |
| Laptop / USB power source | 1 | Development power supply | 5V | USB | NOT the final production power supply |
| Fuse (appropriate rating) | 1+ | AC line protection | Per load rating | AC line | Exact rating requires proper selection |
| Terminal blocks | as needed | Safe AC wiring termination | Mains rated | Screw terminal | Required for any mains-side connections |
| Jumper wires | as needed | Low-voltage prototyping | 3.3V/5V logic | - | ESP32 <-> sensor/LCD/relay LOW-VOLTAGE side only |
| Enclosure | 1 | Physical containment / mains safety | - | - | Required before real deployment; not yet built |
| I2C level shifter (optional) | 0-1 | 3.3V/5V I2C safety margin | 3.3V/5V | I2C | Optional per LCD backpack logic levels |
| Voltage divider / signal conditioning parts (optional) | as needed | Protect ESP32 ADC inputs | - | Analog | REQUIRES VALIDATION against sensor output ranges |

Exact component ratings for signal conditioning have not been finalized
and are marked REQUIRES VALIDATION rather than invented. See
[wiring_notes.md](wiring_notes.md).
