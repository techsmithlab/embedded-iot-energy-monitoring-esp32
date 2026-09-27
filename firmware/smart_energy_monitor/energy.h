#ifndef ENERGY_H
#define ENERGY_H
#include <Arduino.h>

void energyInit();
void energyUpdate(float powerW);
float energyGetWh();
float energyGetKwh();
void energyReset();
void energyMaybeSaveToNvs();

#endif
