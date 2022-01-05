#include "moi.h"

static LiquidCrystal_I2C lcd(0x20, 16, 2);


void init_moi()
{
  lcd.init();
  lcd.backlight();
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
}

void moi_loop()
{
  int value = analogRead(sensor);
   if (value > 700) {
    digitalWrite(13, HIGH);
    digitalWrite(9, HIGH);
  }
  else {
    digitalWrite(13, LOW);
    digitalWrite(9, LOW);
  }
  lcd.begin(16, 2);
  lcd.print("Moi: ");
  lcd.print(value);
  lcd.setCursor(0, 1);
}
