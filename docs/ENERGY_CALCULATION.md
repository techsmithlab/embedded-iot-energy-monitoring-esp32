# Energy Calculation

## Power

Apparent power (implemented): `S = Vrms x Irms` (VA)
Real power (documented, not fully implemented): `P = average(v(t) x i(t))` (W)

Because voltage/current are sampled sequentially, the firmware computes
`S` and uses it as an approximation of `P`. Accurate only near power
factor 1 (resistive loads); overstates real power for reactive/inductive
loads. See [LIMITATIONS.md](LIMITATIONS.md).

## Energy accumulation

```
Energy_Wh += Power_W x elapsed_time_hours
kWh = Wh / 1000
```

`energyUpdate(powerW)` integrates power over elapsed time each cycle; the
running total is periodically (not every cycle, to limit flash wear)
persisted to ESP32 NVS via `Preferences`. `energyReset()` zeroes and
persists the reset.

## Accuracy caveats

Reported energy is only as accurate as: (1) voltage/current calibration,
(2) the apparent-vs-real-power approximation, and (3) sampling loop
stability. Not billing-grade accurate.
