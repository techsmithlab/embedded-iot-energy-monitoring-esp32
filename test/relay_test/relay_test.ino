/*
 * PURPOSE: Verify JQC3F-05VDC-C relay wiring/logic polarity.
 * WIRING: Relay VCC->5V, GND->GND, IN->GPIO26 (do not wire mains side).
 * EXPECTED: toggles every 2s, printing ON/OFF; module LED/click follows.
 * TROUBLESHOOTING: no click -> check VCC/GND/supply; stays energized ->
 * flip ACTIVE_HIGH.
 */
#define RELAY_PIN 26
#define ACTIVE_HIGH 1
bool state = false;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
#if ACTIVE_HIGH
  digitalWrite(RELAY_PIN, LOW);
#else
  digitalWrite(RELAY_PIN, HIGH);
#endif
  Serial.println("Relay test starting (fail-safe OFF at boot)...");
}

void loop() {
  state = !state;
#if ACTIVE_HIGH
  digitalWrite(RELAY_PIN, state ? HIGH : LOW);
#else
  digitalWrite(RELAY_PIN, state ? LOW : HIGH);
#endif
  Serial.println(state ? "Relay -> ON" : "Relay -> OFF");
  delay(2000);
}
