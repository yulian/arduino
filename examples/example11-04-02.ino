#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int count = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.print("Hello World!!");
  lcd.setBacklight(1);
}

void loop()
{
  lcd.setCursor(0, 1);
  lcd.print(count);
  delay(1000);
  count += 1;
}
