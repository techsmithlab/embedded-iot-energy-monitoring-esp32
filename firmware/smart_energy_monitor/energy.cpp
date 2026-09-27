#include "energy.h"
#include "config.h"
#include <Preferences.h>

static Preferences prefs;
static double accumulatedWh = 0.0;
static unsigned long lastUpdateMs = 0;
static unsigned long lastSaveMs = 0;
static const char *NVS_NAMESPACE = "energymon";
static const char *NVS_KEY_WH = "wh";

void energyInit() {
  prefs.begin(NVS_NAMESPACE, false);
  accumulatedWh = prefs.getDouble(NVS_KEY_WH, 0.0);
  lastUpdateMs = millis();
  lastSaveMs = millis();
}

void energyUpdate(float powerW) {
  unsigned long now = millis();
  unsigned long elapsedMs = now - lastUpdateMs;
  lastUpdateMs = now;
  double elapsedHours = (double)elapsedMs / 3600000.0;
  accumulatedWh += (double)powerW * elapsedHours;
  if (accumulatedWh < 0) accumulatedWh = 0;
}

float energyGetWh() { return (float)accumulatedWh; }
float energyGetKwh() { return (float)(accumulatedWh / 1000.0); }

void energyReset() {
  accumulatedWh = 0.0;
  prefs.putDouble(NVS_KEY_WH, accumulatedWh);
}

void energyMaybeSaveToNvs() {
  unsigned long now = millis();
  if (now - lastSaveMs >= ENERGY_SAVE_INTERVAL_MS) {
    prefs.putDouble(NVS_KEY_WH, accumulatedWh);
    lastSaveMs = now;
  }
}
