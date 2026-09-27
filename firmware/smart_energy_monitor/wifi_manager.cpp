#include "wifi_manager.h"
#include "config.h"
#include <WiFi.h>

static unsigned long lastReconnectAttempt = 0;

void wifiInit() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("[WiFi] Connecting to "); Serial.print(WIFI_SSID);
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && (millis() - start) < WIFI_CONNECT_TIMEOUT_MS) {
    delay(300); Serial.print(".");
  }
  Serial.println();
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("[WiFi] Connected. IP: "); Serial.println(WiFi.localIP());
  } else {
    Serial.println("[WiFi] Connection timed out. Will retry in background.");
  }
  lastReconnectAttempt = millis();
}

void wifiHandle() {
  if (WiFi.status() != WL_CONNECTED) {
    unsigned long now = millis();
    if (now - lastReconnectAttempt >= WIFI_RECONNECT_INTERVAL_MS) {
      Serial.println("[WiFi] Reconnecting...");
      WiFi.disconnect();
      WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      lastReconnectAttempt = now;
    }
  }
}

bool wifiIsConnected() { return WiFi.status() == WL_CONNECTED; }
int wifiGetRssi() { return wifiIsConnected() ? WiFi.RSSI() : 0; }
