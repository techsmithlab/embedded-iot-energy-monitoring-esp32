# Circuit Description

## Low-voltage side

The ESP32 reads the conditioned ZMPT101B output (proportional to AC line
voltage) on GPIO34 and the conditioned ACS712 output (proportional to AC
line current) on GPIO35. Both sensors share the 5V/low-voltage rail and a
common ground with the ESP32, relay coil, and LCD backpack. The ESP32
drives the relay module's IN pin (GPIO26); the relay's mains contacts are
isolated internally from the low-voltage coil side. The 16x2 LCD is
driven over I2C (GPIO21/22).

## AC side (mains - conceptual only)

Live passes through a fuse, then the ACS712's current-sensing path
(IP+/IP-), then the relay's COM/NO contacts, to the load. Neutral runs
directly to the load. Earth is a separate protective conductor, never
connected to ESP32 logic ground. ZMPT101B senses AC voltage per its own
isolated design. See [../hardware/wiring.md](../hardware/wiring.md) and
[SAFETY.md](SAFETY.md).

This description is conceptual and has not been reviewed by a licensed
electrician; it is not a certified circuit design.
