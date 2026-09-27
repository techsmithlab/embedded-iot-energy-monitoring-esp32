#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H
#include <Arduino.h>

void wifiInit();
void wifiHandle();
bool wifiIsConnected();
int  wifiGetRssi();

#endif
