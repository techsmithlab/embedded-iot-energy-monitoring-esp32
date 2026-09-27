/*
 * PURPOSE: Verify ESP32 Wi-Fi connectivity in isolation.
 * CONFIGURE: replace placeholders below for this local test only - do
 * not commit real credentials.
 * EXPECTED: dots while connecting, then "WiFi connected!" + IP.
 * TROUBLESHOOTING: timeout -> check SSID/password, must be 2.4GHz;
 * connects then drops -> check power supply stability.
 */
#include <WiFi.h>
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(115200);
  Serial.println(); Serial.print("Connecting to "); Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 15000) {
    delay(300); Serial.print(".");
  }
  Serial.println();
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi connected!");
    Serial.print("IP address: "); Serial.println(WiFi.localIP());
    Serial.print("RSSI: "); Serial.println(WiFi.RSSI());
  } else {
    Serial.println("WiFi connection FAILED / timed out.");
  }
}

void loop() {
  delay(5000);
  Serial.print("WiFi status: ");
  Serial.println(WiFi.status() == WL_CONNECTED ? "CONNECTED" : "DISCONNECTED");
}
