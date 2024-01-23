#include <LiquidCrystal_I2C.h>

// 16x2 LCD 객체를 생성(LCD의 주솟값은 32)
LiquidCrystal_I2C lcd(32, 16, 2);
int count = 0;

void setup()
{
  lcd.init();       // LCD 초기화
  lcd.backlight();  // 백라이트 켜기
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Hello World!!");
  lcd.setCursor(0,1);
  lcd.print(count++);
  delay(1000);
}
