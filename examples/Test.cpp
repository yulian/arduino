#include "Test.h"

Test::Test(int pin)
{
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void Test::Blink()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(1000);
}
