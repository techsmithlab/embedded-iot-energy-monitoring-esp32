# Sensor Calibration Procedure

Calibration determines: (1) the zero-offset (ADC midpoint, no signal),
and (2) the scale factor (physical units per ADC-RMS count). Until both
are done, treat readings as uncalibrated/relative.

## ACS712 (current)

1. Disconnect mains entirely from the current-sensing path.
2. Ensure zero current is flowing.
3. Read 1000+ ADC samples (the firmware's `CAL` serial command does this).
4. Calculate the average zero-offset.
5. Save it into `ACS_ADC_MIDPOINT_DEFAULT` in `config.h`.
6. Verify stability across runs/power cycles.
7. Only if properly equipped, apply a known safe test current (e.g. a
   clamp-meter cross-check on a low-power resistive load).
8. Calculate `CURRENT_CALIBRATION_FACTOR` from the known current and
   measured ADC-RMS value; update `config.h`.

## ZMPT101B (voltage)

1. Verify the correct supply voltage for your module (see
   [../hardware/wiring_notes.md](../hardware/wiring_notes.md)).
2. Verify output range does not exceed the ESP32's 0-3.3V ADC window.
3. Only under safe conditions, apply a known reference AC voltage.
4. Read the waveform, compute ADC-RMS.
5. Compare against a trusted reference meter.
6. Calculate `VOLTAGE_CALIBRATION_FACTOR` = (reference Vrms)/(ADC-RMS);
   update `config.h`.
7. Repeat at a couple of safe reference voltages to sanity-check linearity.

Never handle exposed 230V wiring without proper training, PPE, and
isolation. See [SAFETY.md](SAFETY.md).
