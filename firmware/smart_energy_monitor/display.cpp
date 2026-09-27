// Requires LiquidCrystal_I2C library. Verify LCD_I2C_ADDRESS if blank
// (see docs/TROUBLESHOOTING.md).
#include "display.h"
#include "config.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

static LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void displayInit() {
  Wire.begin(PIN_LCD_SDA, PIN_LCD_SCL);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void displayClear() { lcd.clear(); }

void displayShowBoot() {
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("SMART ENERGY");
  lcd.setCursor(0, 1); lcd.print("MONITORING");
}

void displayShowVoltageCurrent(float vrms, float irms) {
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("V:"); lcd.print(vrms, 1); lcd.print("V");
  lcd.setCursor(0, 1); lcd.print("I:"); lcd.print(irms, 2); lcd.print("A");
}

void displayShowPowerEnergy(float powerW, float energyKwh) {
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("P:"); lcd.print(powerW, 1); lcd.print("W");
  lcd.setCursor(0, 1); lcd.print("E:"); lcd.print(energyKwh, 3); lcd.print("kWh");
}

void displayShowStatus(bool wifiOk, bool cloudOk) {
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("WiFi: "); lcd.print(wifiOk ? "OK" : "--");
  lcd.setCursor(0, 1); lcd.print("Cloud:"); lcd.print(cloudOk ? "OK" : "--");
}
