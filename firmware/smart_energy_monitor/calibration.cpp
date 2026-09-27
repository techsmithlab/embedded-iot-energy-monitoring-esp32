#include "calibration.h"
#include "config.h"
#include "sensors.h"

void calibrationRunZeroOffsetRoutine() {
  Serial.println("=================================================");
  Serial.println(" CALIBRATION: ZERO-OFFSET MEASUREMENT");
  Serial.println(" Ensure ACS712 carries ZERO current and ZMPT101B");
  Serial.println(" has no AC input connected before continuing.");
  Serial.println("=================================================");

  const uint16_t samples = 1000;
  int acsOffset = sensorsMeasureZeroOffset(PIN_ACS712_OUT, samples);
  Serial.print("[CAL] ACS712 zero-offset ADC (avg of "); Serial.print(samples); Serial.print(" samples): "); Serial.println(acsOffset);

  int zmptOffset = sensorsMeasureZeroOffset(PIN_ZMPT101B_OUT, samples);
  Serial.print("[CAL] ZMPT101B zero-offset ADC (avg of "); Serial.print(samples); Serial.print(" samples): "); Serial.println(zmptOffset);

  Serial.println("[CAL] Update ACS_ADC_MIDPOINT_DEFAULT / ZMPT_ADC_MIDPOINT_DEFAULT");
  Serial.println("[CAL] in config.h with these values, then recompile.");
  Serial.println("[CAL] This does NOT calibrate scale factors (V/A per ADC count).");
  Serial.println("[CAL] Follow docs/SENSOR_CALIBRATION.md for full calibration.");
}

void calibrationPrintStatus() {
  Serial.println("[CAL] Current calibration constants (config.h):");
  Serial.print("  ZMPT_ADC_MIDPOINT_DEFAULT = "); Serial.println(ZMPT_ADC_MIDPOINT_DEFAULT);
  Serial.print("  ACS_ADC_MIDPOINT_DEFAULT  = "); Serial.println(ACS_ADC_MIDPOINT_DEFAULT);
  Serial.print("  VOLTAGE_CALIBRATION_FACTOR = "); Serial.println(VOLTAGE_CALIBRATION_FACTOR, 6);
  Serial.print("  CURRENT_CALIBRATION_FACTOR = "); Serial.println(CURRENT_CALIBRATION_FACTOR, 6);
  Serial.println("[CAL] NOTE: factors of 1.0 mean NOT YET CALIBRATED.");
}
