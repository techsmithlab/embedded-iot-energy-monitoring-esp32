/*
 * PURPOSE: Read raw ADC waveform from ZMPT101B to verify wiring/output
 * range BEFORE trusting it on GPIO34.
 * WIRING: VCC-> verify exact rated supply for your module (do not
 * assume 3.3V/5V), GND->common GND, OUT->GPIO34.
 * SAFETY: only apply an AC reference under safe, competent conditions -
 * never expose bare mains conductors on a breadboard. Can also be run
 * with no AC input to see the quiescent baseline. See docs/SAFETY.md.
 * TROUBLESHOOTING: pinned 0/4095 -> output range may exceed ESP32's
 * 0-3.3V window, do not connect directly without verifying.
 */
#define ZMPT_PIN 34
#define ADC_REF_VOLTAGE 3.3f
#define ADC_MAX_VALUE 4095.0f

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  Serial.println("ZMPT101B raw ADC test starting...");
  Serial.println("NOT YET VALIDATED: verify module output range before trusting GPIO34.");
}

void loop() {
  int raw = analogRead(ZMPT_PIN);
  float voltage = (raw / ADC_MAX_VALUE) * ADC_REF_VOLTAGE;
  Serial.print("ZMPT101B Raw = "); Serial.print(raw);
  Serial.print("  ADC Voltage = "); Serial.print(voltage, 3); Serial.println(" V");
  delay(20);
}
