#ifndef RELAY_CONTROL_H
#define RELAY_CONTROL_H
#include <Arduino.h>

void relayInit();
void relayOn();
void relayOff();
void relayToggle();
bool getRelayState();
void relayHandleSerialCommand(const String &cmd);

#endif
