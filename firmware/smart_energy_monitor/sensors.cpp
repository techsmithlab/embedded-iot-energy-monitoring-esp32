/*
 * NOT YET VALIDATED: calibration factors are placeholders (see config.h).
 * Voltage/current sampled sequentially, not synchronized -> apparent
 * power only (S = Vrms*Irms), not true real power. See docs/LIMITATIONS.md.
 */
#include "sensors.h"
#include "config.h"

static int voltageOffset = ZMPT_ADC_MIDPOINT_DEFAULT;
static int currentOffset = ACS_ADC_MIDPOINT_DEFAULT;

void sensorsInit() {
  analogReadResolution(ADC_RESOLUTION_BITS);
  pinMode(PIN_ZMPT101B_OUT, INPUT);
  pinMode(PIN_ACS712_OUT, INPUT);
}

int sensorsMeasureZeroOffset(uint8_t adcPin, uint16_t samples) {
  long sum = 0;
  for (uint16_t i = 0; i < samples; i++) {
    sum += analogRead(adcPin);
    delayMicroseconds(SAMPLE_INTERVAL_US);
  }
  return (int)(sum / (long)samples);
}

static float computeRmsAdc(uint8_t pin, int offset, unsigned long windowMs) {
  unsigned long start = millis();
  double sumSq = 0;
  unsigned long count = 0;
  while (millis() - start < windowMs) {
    int raw = analogRead(pin);
    int centered = raw - offset;
    sumSq += (double)centered * (double)centered;
    count++;
    delayMicroseconds(SAMPLE_INTERVAL_US);
  }
  if (count == 0) return 0.0f;
  return (float)sqrt(sumSq / (double)count);
}

SensorReadings sensorsRead() {
  SensorReadings r;
  r.voltageOffset = voltageOffset;
  r.currentOffset = currentOffset;

  float vRmsAdc = computeRmsAdc(PIN_ZMPT101B_OUT, voltageOffset, SAMPLE_WINDOW_MS);
  float iRmsAdc = computeRmsAdc(PIN_ACS712_OUT, currentOffset, SAMPLE_WINDOW_MS);

  r.vrms = vRmsAdc * VOLTAGE_CALIBRATION_FACTOR;
  r.irms = iRmsAdc * CURRENT_CALIBRATION_FACTOR;
  r.apparentPower = r.vrms * r.irms;
  r.valid = (vRmsAdc >= 0) && (iRmsAdc >= 0);
  return r;
}
