#ifndef Test_h
#define Test_h
#include "Arduino.h"

class Test
{
  public:
    Test(int pin);
    void Blink();
  private:
  int _pin;
};

#endif
