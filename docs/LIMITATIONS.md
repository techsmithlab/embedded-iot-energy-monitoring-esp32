# Limitations

1. Sensor accuracy depends on completing proper calibration (see
   [SENSOR_CALIBRATION.md](SENSOR_CALIBRATION.md)) - not automatic.
2. ACS712 has an inherent zero-current offset and output noise that must
   be characterized per-unit.
3. ZMPT101B requires calibration against a trusted reference before its
   output represents real AC voltage.
4. The ESP32 ADC has known non-linearity/noise, especially near the rails.
5. Any direct ADC connection must respect the ESP32's 0-3.3V input limits.
6. Power calculation accuracy depends on waveform sampling quality and
   completed calibration.
7. Power factor matters for accurate real power - the current
   implementation reports apparent power as an approximation, which
   overstates real power for non-resistive loads.
8. Mains wiring requires proper electrical safety at every stage - see
   [SAFETY.md](SAFETY.md).
9. This prototype is not automatically a certified energy meter.
10. USB laptop power is only a development power method, not a
    production power architecture.
