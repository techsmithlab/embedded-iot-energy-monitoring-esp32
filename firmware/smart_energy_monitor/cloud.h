#ifndef CLOUD_H
#define CLOUD_H
#include <Arduino.h>

struct TelemetryData {
  float vrms;
  float irms;
  float powerW;
  float energyKwh;
  bool  relayOn;
  int   wifiRssi;
  float apparentPowerVA;
  const char *statusText;
};

void cloudInit();
void cloudHandle();
bool cloudUploadThingSpeak(const TelemetryData &data);
bool cloudIsThingSpeakOk();

#endif
