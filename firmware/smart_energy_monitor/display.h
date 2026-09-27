#ifndef DISPLAY_H
#define DISPLAY_H
#include <Arduino.h>

enum LcdScreen { SCREEN_BOOT = 0, SCREEN_VOLTAGE_CURRENT, SCREEN_POWER_ENERGY, SCREEN_STATUS, SCREEN_COUNT };

void displayInit();
void displayShowBoot();
void displayShowVoltageCurrent(float vrms, float irms);
void displayShowPowerEnergy(float powerW, float energyKwh);
void displayShowStatus(bool wifiOk, bool cloudOk);
void displayClear();

#endif
