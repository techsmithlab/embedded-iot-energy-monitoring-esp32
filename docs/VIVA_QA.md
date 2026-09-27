# Viva Questions & Answers

## ESP32 basics

**1. What is the ESP32?**
A low-cost, dual-core microcontroller with built-in Wi-Fi and Bluetooth,
widely used for IoT projects.

**2. Why was ESP32 chosen over Arduino Uno for this project?**
Built-in Wi-Fi (needed for cloud telemetry), more ADC channels, more
memory, and enough processing power for RMS calculations.

**3. How many analog input pins does this project use, and which?**
Two - GPIO34 (voltage sensor) and GPIO35 (current sensor).

**4. Why were GPIO34 and GPIO35 specifically chosen?**
They are ADC1 input-only pins, safe to use as analog inputs without
conflicting with Wi-Fi (which can conflict with some ADC2 pins).

**5. What voltage domain does the ESP32 ADC operate in?**
0-3.3V.

## ADC concepts

**6. What is an ADC?**
An Analog-to-Digital Converter - converts a continuous analog voltage
into a discrete digital value.

**7. What ADC resolution is used?**
12-bit, giving a range of 0-4095.

**8. Why does the code remove a "midpoint offset" before computing RMS?**
AC signals swing above/below zero, but ADC readings are always positive
(0-3.3V); the offset is the "zero" point on the ADC's positive scale and
must be subtracted before RMS makes sense.

**9. What causes ADC noise in this kind of circuit?**
Power supply ripple, long analog wiring, shared grounds with switching
loads (like the relay), and the ADC's own quantization noise.

## ACS712

**10. What type of sensor is the ACS712?**
A Hall-effect based current sensor.

**11. What does "ACS712ELC-20A" mean?**
It's the 20A-rated variant of the ACS712 current sensor module.

**12. What was observed during the zero-current ACS712 test?**
A stable raw ADC baseline of ~2928-2942, corresponding to ~2.36-2.37V,
with zero current flowing.

**13. Why is finding the zero-current offset important?**
Current calculations measure deviation from this baseline, not the raw
ADC value itself.

**14. Does a stable zero-current reading prove accurate current
measurement?**
No - it confirms baseline stability only; accuracy under actual current
requires separate calibration against a known load.

## ZMPT101B

**15. What does the ZMPT101B measure?**
AC line voltage.

**16. Why must the ZMPT101B's supply voltage be verified rather than
assumed?**
Different breakout boards for this module are sold with different rated
supply voltages; using the wrong one could damage it or give wrong
readings.

**17. Why might signal conditioning be needed for the ZMPT101B's output?**
If its output exceeds the ESP32 ADC's 0-3.3V window, it must be scaled
first to avoid clipping or ADC damage.

## RMS and power

**18. What does RMS stand for, and why use it for AC?**
Root Mean Square - the equivalent DC value delivering the same power as
the AC signal; that's why AC ratings use RMS.

**19. Give the RMS voltage formula as implemented here.**
Vrms = sqrt(mean(v_sample^2)), with the midpoint offset already removed.

**20. What is apparent power, and how is it calculated?**
S = Vrms x Irms, in VA (volt-amps).

**21. What is real power, and how does it differ from apparent power?**
P = average(v(t) x i(t)), in Watts - accounts for phase relationship, so
it can be less than apparent power for non-resistive loads.

**22. Why does this project report apparent power instead of real power?**
It samples voltage and current sequentially, not simultaneously, so it
can't yet compute the instantaneous v(t)*i(t) product real power needs.

**23. What is power factor?**
The ratio of real power to apparent power (P/S).

## Energy

**24. What formula accumulates energy here?**
Energy_Wh += Power_W x elapsed_time_hours.

**25. How is Wh converted to kWh?**
Divide by 1000.

**26. Why save accumulated energy periodically instead of every loop?**
To reduce wear on flash memory, which has limited write cycles.

**27. What ESP32 library provides persistent storage here?**
`Preferences`, wrapping the ESP32's NVS partition.

## Relay / load control

**28. What relay module is used, and what does it control?**
JQC3F-05VDC-C, used to switch the connected AC load.

**29. What does active-high vs active-low relay logic mean?**
Whether the relay energizes on a HIGH or LOW control input - varies by
breakout board.

**30. What is the relay's default state at boot, and why?**
OFF - a fail-safe so the load doesn't unexpectedly energize on power-up.

**31. Does losing Wi-Fi turn the relay ON in this design?**
No - relay state only changes via explicit commands.

## I2C / LCD

**32. What protocol does the 16x2 LCD use here?**
I2C, via a backpack module, using SDA/SCL.

**33. Which ESP32 pins are used for I2C here?**
GPIO21 (SDA) and GPIO22 (SCL).

**34. What are the two common I2C addresses for these LCD backpacks?**
0x27 and 0x3F.

**35. What tool finds an unknown I2C address?**
An I2C scanner sketch.

## Wi-Fi

**36. What Wi-Fi bands does ESP32 support?**
2.4GHz only, not 5GHz.

**37. What happens if Wi-Fi fails at boot?**
The device continues operating locally and retries connecting in the
background at a fixed interval.

## ThingSpeak / Blynk

**38. What is ThingSpeak?**
A cloud IoT platform (by MathWorks) for collecting, visualizing, and
analyzing sensor data via channels/fields.

**39. What is the minimum update interval for a free ThingSpeak channel?**
15 seconds.

**40. How many ThingSpeak fields does this project use, and what are
they?**
Eight: Voltage, Current, Power, Energy, Relay State, Wi-Fi RSSI, Apparent
Power, System Status.

**41. What is Blynk used for here?**
An optional mobile-app dashboard, alternative/companion to ThingSpeak.

**42. Why are Wi-Fi passwords and API keys kept out of the repository?**
To avoid leaking private credentials publicly; placeholders are
committed, real values stay local in a gitignored file.

## Calibration

**43. What two things does calibration determine per sensor?**
Zero-offset (ADC midpoint, no signal) and scale factor (units per ADC-RMS
count).

**44. Why disconnect mains before ACS712 zero calibration?**
To ensure zero current, required to correctly measure the true baseline.

**45. Why can't this project's ZMPT101B calibration factor be trusted
yet?**
It hasn't been compared against a known reference AC voltage under safe
conditions - the current factor is a placeholder (1.0).

## Embedded systems / IoT concepts

**46. Why use `millis()`-based timing instead of `delay()`?**
Lets multiple tasks (sensor reads, LCD updates, cloud uploads) run on
independent schedules without blocking the whole program.

**47. What does "non-blocking" mean in embedded firmware?**
Code that doesn't halt execution while waiting, so other tasks can still
run.

**48. Why prefer modular firmware (separate .h/.cpp per feature)?**
Improves readability, eases testing individual subsystems, and separates
responsibilities clearly.

## Electrical safety

**49. Why must protective earth never connect to ESP32's logic ground?**
They serve different purposes - tying them could create a dangerous or
incorrect current path.

**50. Why shouldn't mains wiring be built on a breadboard?**
Breadboards aren't rated for mains voltage/current and offer no
insulation, creating serious shock/fire risk.

**51. Who should verify final mains wiring before deployment?**
A qualified electrician or other competent person.

**52. What does "not a certified energy meter" mean for this project?**
Readings, even once calibrated, are for educational/monitoring purposes
only and haven't been through formal metrology certification, so they
shouldn't be used for billing or legal/commercial measurement.
