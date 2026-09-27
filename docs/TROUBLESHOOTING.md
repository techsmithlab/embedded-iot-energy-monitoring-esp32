# Troubleshooting

| Symptom | Likely cause / fix |
|---|---|
| LCD blank | Wrong I2C address (try 0x27 <-> 0x3F); check SDA/SCL wiring |
| LCD backlight but no text | Adjust contrast potentiometer on backpack |
| Wrong I2C address | Run an I2C scanner sketch |
| ESP32 not detected | Check USB cable (data-capable), install CP210x/CH340 driver, hold BOOT during upload |
| Serial port busy | Close other Serial Monitor/IDE instances |
| GPIO34 reading wrong | Check ZMPT101B wiring/supply voltage |
| GPIO35 reading wrong | Check ACS712 wiring/5V supply |
| ACS712 offset unstable | Noisy supply - add decoupling cap; ensure zero current during test |
| ZMPT101B output too high | Exceeds 0-3.3V ADC window - add/adjust conditioning |
| Relay not switching | Check VCC/GND/IN wiring and supply current capability |
| Relay logic inverted | Toggle `RELAY_ACTIVE_HIGH`, re-test |
| Wi-Fi failure | Confirm 2.4GHz, SSID/password, router range |
| ThingSpeak failure | Check API key/channel ID, upload interval >=15s, HTTP code |
| Blynk authentication failure | Confirm Auth Token/Template ID/Name match console |
| Cloud data not updating | Check Wi-Fi first, then cloud credentials, then interval |
| Energy value resetting | Check NVS write success, avoid brownouts, call `energyReset()` intentionally only |
| ADC saturation | Pinned at 0/4095 - check conditioning vs 3.3V domain |
| ADC noise | Add decoupling caps, shorten analog wiring, check shared grounds |
| Sensor calibration errors | Re-run SENSOR_CALIBRATION.md, verify zero-offset stability first |
