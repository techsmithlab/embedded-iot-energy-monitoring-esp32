# Wiring Notes / Open Items

Must be verified against the actual physical modules before the wiring
above is final:

1. ZMPT101B supply voltage - confirm from silkscreen/seller docs; do not
   assume 3.3V or 5V.
2. ZMPT101B output range - confirm peak-to-peak swing at expected AC
   voltage before connecting directly to GPIO34; add conditioning if
   needed.
3. ACS712 output range across full current span - confirm ESP32 ADC
   (3.3V domain) isn't over/under-driven at expected currents.
4. Relay module logic polarity - confirm with `test/relay_test` before
   trusting the `RELAY_ACTIVE_HIGH` default.
5. I2C LCD address - commonly 0x27 or 0x3F; use an I2C scanner if
   `test/lcd_test` shows blank.
6. Common ground integrity - verify continuity across all modules.
7. Protective earth isolation - AC-side protective earth must never be
   tied to ESP32 logic GND.

Until items 1-3 are verified, treat firmware voltage/current numbers as
relative/uncalibrated, not accurate measurements.
