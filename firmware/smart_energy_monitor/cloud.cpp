/*
 * ThingSpeak: HTTPClient GET to update endpoint, min 15s interval (free tier).
 * Blynk: only meaningful if BLYNK_ENABLED=1 and Blynk library installed;
 * guarded by #if so this file compiles either way.
 */
#include "cloud.h"
#include "config.h"
#include <WiFi.h>
#include <HTTPClient.h>

#if BLYNK_ENABLED
  #define BLYNK_TEMPLATE_ID_DEF BLYNK_TEMPLATE_ID
  #define BLYNK_TEMPLATE_NAME_DEF BLYNK_TEMPLATE_NAME
  #include <BlynkSimpleEsp32.h>
  BlynkTimer blynkTimer;
#endif

static bool lastThingSpeakOk = false;

void cloudInit() {
#if BLYNK_ENABLED
  Blynk.config(BLYNK_AUTH_TOKEN);
#endif
}

void cloudHandle() {
#if BLYNK_ENABLED
  if (Blynk.connected()) { Blynk.run(); } else { Blynk.connect(1000); }
#endif
}

bool cloudUploadThingSpeak(const TelemetryData &data) {
#if THINGSPEAK_ENABLED
  if (WiFi.status() != WL_CONNECTED) { lastThingSpeakOk = false; return false; }

  HTTPClient http;
  String url = String(THINGSPEAK_SERVER) +
               "?api_key=" + THINGSPEAK_API_KEY +
               "&field1=" + String(data.vrms, 2) +
               "&field2=" + String(data.irms, 3) +
               "&field3=" + String(data.powerW, 2) +
               "&field4=" + String(data.energyKwh, 4) +
               "&field5=" + String(data.relayOn ? 1 : 0) +
               "&field6=" + String(data.wifiRssi) +
               "&field7=" + String(data.apparentPowerVA, 2) +
               "&field8=" + String(data.statusText);

  http.begin(url);
  int httpCode = http.GET();
  http.end();

  lastThingSpeakOk = (httpCode == 200);
  if (!lastThingSpeakOk) {
    Serial.print("[ThingSpeak] Upload failed, HTTP code: ");
    Serial.println(httpCode);
  }
  return lastThingSpeakOk;
#else
  (void)data;
  return false;
#endif
}

bool cloudIsThingSpeakOk() { return lastThingSpeakOk; }

#if BLYNK_ENABLED
BLYNK_CONNECTED() { Serial.println("[Blynk] Connected"); }
#endif
