/*
 * smart_energy_monitor.ino
 * ESP32-Based IoT Smart Energy Monitoring and Load Control System
 *
 * STATUS: Prototype/development. Relay control tested & working; ACS712
 * zero-current baseline observed & documented; full voltage/current
 * calibration and real (vs apparent) power NOT yet done. See docs/LIMITATIONS.md.
 *
 * Required libraries: LiquidCrystal_I2C (+ Blynk if BLYNK_ENABLED).
 * Built-in ESP32 core: WiFi, HTTPClient, Wire, Preferences.
 */
#include "config.h"
#include "sensors.h"
#include "display.h"
#include "relay_control.h"
#include "energy.h"
#include "wifi_manager.h"
#include "cloud.h"
#include "calibration.h"

static unsigned long lastSensorRead = 0;
static unsigned long lastLcdUpdate = 0;
static unsigned long lastCloudUpload = 0;
static uint8_t lcdScreenIndex = SCREEN_VOLTAGE_CURRENT;
static SensorReadings currentReadings;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  delay(200);
  Serial.println();
  Serial.println("=== Smart Energy Monitor booting ===");

  relayInit();
  sensorsInit();
  displayInit();
  displayShowBoot();
  energyInit();
  wifiInit();
  cloudInit();

  delay(1500);
  displayClear();

  Serial.println("=== Setup complete ===");
  Serial.println("Serial commands: ON, OFF, STATUS, CAL, CALSTATUS");
}

static void handleSerialCommands() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd.length() == 0) return;
    String upper = cmd; upper.toUpperCase();
    if (upper == "CAL") calibrationRunZeroOffsetRoutine();
    else if (upper == "CALSTATUS") calibrationPrintStatus();
    else relayHandleSerialCommand(cmd);
  }
}

void loop() {
  handleSerialCommands();
  wifiHandle();
  cloudHandle();

  unsigned long now = millis();

  if (now - lastSensorRead >= SENSOR_READ_INTERVAL_MS) {
    lastSensorRead = now;
    currentReadings = sensorsRead();
    // apparentPower used as energy input - approximation, see docs/LIMITATIONS.md
    energyUpdate(currentReadings.apparentPower);
    energyMaybeSaveToNvs();

#if DEBUG_SERIAL
    Serial.print("[SENSOR] Vrms(raw-scaled)="); Serial.print(currentReadings.vrms, 3);
    Serial.print(" Irms(raw-scaled)="); Serial.print(currentReadings.irms, 3);
    Serial.print(" S(approx)="); Serial.print(currentReadings.apparentPower, 3);
    Serial.print(" Energy(kWh)="); Serial.println(energyGetKwh(), 4);
#endif
  }

  if (now - lastLcdUpdate >= LCD_UPDATE_INTERVAL_MS) {
    lastLcdUpdate = now;
    switch (lcdScreenIndex) {
      case SCREEN_VOLTAGE_CURRENT: displayShowVoltageCurrent(currentReadings.vrms, currentReadings.irms); break;
      case SCREEN_POWER_ENERGY: displayShowPowerEnergy(currentReadings.apparentPower, energyGetKwh()); break;
      case SCREEN_STATUS: displayShowStatus(wifiIsConnected(), cloudIsThingSpeakOk()); break;
      default: displayShowVoltageCurrent(currentReadings.vrms, currentReadings.irms); break;
    }
    lcdScreenIndex++;
    if (lcdScreenIndex >= SCREEN_COUNT || lcdScreenIndex == SCREEN_BOOT) lcdScreenIndex = SCREEN_VOLTAGE_CURRENT;
  }

  if (now - lastCloudUpload >= CLOUD_UPLOAD_INTERVAL_MS) {
    lastCloudUpload = now;
    TelemetryData data;
    data.vrms = currentReadings.vrms;
    data.irms = currentReadings.irms;
    data.powerW = currentReadings.apparentPower;
    data.energyKwh = energyGetKwh();
    data.relayOn = getRelayState();
    data.wifiRssi = wifiGetRssi();
    data.apparentPowerVA = currentReadings.apparentPower;
    data.statusText = wifiIsConnected() ? "OK" : "WIFI_DOWN";
    cloudUploadThingSpeak(data);
  }
}
