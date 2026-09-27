# Testing

## Completed / tested

1. ESP32 connected to laptop via USB - confirmed working.
2. Relay module tested and confirmed operating (`test/relay_test`).
3. ACS712 zero-current ADC test performed (`test/acs712_test`).

### ACS712 zero-current test results (actual observed data)

| Raw ADC | ADC-equivalent Voltage |
|---|---|
| 2928 | 2.360 V |
| 2935 | 2.365 V |
| 2939 | 2.368 V |
| 2942 | 2.371 V |

Overall range: raw ADC ~2928-2942, voltage ~2.36-2.37V. Interpretation:
sensor output was stable during the no-current test. This confirms wiring
and a stable baseline - it does not by itself prove accurate current
measurement under load.

## Not yet completed

1. Full 230V AC measurement.
2. Final ZMPT101B voltage calibration.
3. Full ACS712 current calibration under known load.
4. Accurate real-power measurement.
5. Power-factor-aware real power measurement.
6. Long-term energy accuracy validation.
7. Final mains enclosure validation.
8. Electrical safety certification.
9. Production deployment.

## Test sketches

| Sketch | Verifies |
|---|---|
| `test/relay_test` | Relay wiring & logic polarity |
| `test/lcd_test` | LCD wiring & I2C address |
| `test/acs712_test` | ACS712 zero-current baseline |
| `test/zmpt101b_test` | ZMPT101B raw ADC output/waveform |
| `test/wifi_test` | Wi-Fi connectivity in isolation |
