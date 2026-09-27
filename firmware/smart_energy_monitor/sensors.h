#ifndef SENSORS_H
#define SENSORS_H
#include <Arduino.h>

struct SensorReadings {
  float vrms;
  float irms;
  float apparentPower;
  int   voltageOffset;
  int   currentOffset;
  bool  valid;
};

void sensorsInit();
int sensorsMeasureZeroOffset(uint8_t adcPin, uint16_t samples);
SensorReadings sensorsRead();

#endif
