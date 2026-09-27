/*
 * PURPOSE: Read raw ADC/voltage from ACS712ELC-20A with ZERO current, to
 * observe zero-current baseline.
 * WIRING: VCC->5V, GND->common GND, OUT->GPIO35 (no mains IP+/IP- needed).
 * EXPECTED (documented result from this project - your module may differ):
 *   Raw ADC ~2928-2942, ADC Voltage ~2.36-2.37V.
 * TROUBLESHOOTING: pinned 0/4095 -> check wiring; big drift -> check 5V
 * supply quality / add decoupling cap. This test does NOT measure current.
 */
#define ACS712_PIN 35
#define ADC_REF_VOLTAGE 3.3f
#define ADC_MAX_VALUE 4095.0f

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  Serial.println("ACS712 zero-current baseline test starting...");
  Serial.println("Ensure NO current is flowing through the sensor.");
}

void loop() {
  int raw = analogRead(ACS712_PIN);
  float voltage = (raw / ADC_MAX_VALUE) * ADC_REF_VOLTAGE;
  Serial.print("ACS712 Raw = "); Serial.print(raw);
  Serial.print("  ADC Voltage = "); Serial.print(voltage, 3); Serial.println(" V");
  delay(500);
}
