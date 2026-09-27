/*
 * PURPOSE: Verify 16x2 I2C LCD wiring/address.
 * WIRING: VCC->5V, GND->GND, SDA->GPIO21, SCL->GPIO22.
 * REQUIRES: LiquidCrystal_I2C library.
 * EXPECTED: LCD shows "LCD TEST OK"/"I2C Working", backlight on.
 * TROUBLESHOOTING: blank -> try 0x3F instead of 0x27; backlight-only ->
 * adjust contrast pot; run I2C scanner if unsure.
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define LCD_ADDRESS 0x27
#define SDA_PIN 21
#define SCL_PIN 22
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("LCD TEST OK");
  lcd.setCursor(0, 1); lcd.print("I2C Working");
  Serial.println("LCD test running...");
}

void loop() {}
