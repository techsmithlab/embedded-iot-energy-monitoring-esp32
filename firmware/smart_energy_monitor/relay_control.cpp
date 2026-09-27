#include "relay_control.h"
#include "config.h"

static bool relayState = false;

static void writeRelayPin(bool on) {
#if RELAY_ACTIVE_HIGH
  digitalWrite(PIN_RELAY_IN, on ? HIGH : LOW);
#else
  digitalWrite(PIN_RELAY_IN, on ? LOW : HIGH);
#endif
}

void relayInit() {
  pinMode(PIN_RELAY_IN, OUTPUT);
#if RELAY_DEFAULT_STATE_OFF
  relayState = false;
#endif
  writeRelayPin(relayState);
}

void relayOn() { relayState = true; writeRelayPin(true); }
void relayOff() { relayState = false; writeRelayPin(false); }
void relayToggle() { relayState = !relayState; writeRelayPin(relayState); }
bool getRelayState() { return relayState; }

void relayHandleSerialCommand(const String &cmd) {
  String c = cmd; c.trim(); c.toUpperCase();
  if (c == "ON") { relayOn(); Serial.println("[RELAY] Turned ON"); }
  else if (c == "OFF") { relayOff(); Serial.println("[RELAY] Turned OFF"); }
  else if (c == "STATUS") { Serial.print("[RELAY] State: "); Serial.println(getRelayState() ? "ON" : "OFF"); }
}
