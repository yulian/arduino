#include <SoftwareSerial.h>
SoftwareSerial BTSerial(12, 13);  // 블루투스 모듈의 TXD: 12번핀, RXD: 13번핀

int brightness = 0;               // 밝기를 제어하는 변수

void setup() {
  // 시리얼 통신 초기화
  Serial.begin(9600);
  BTSerial.begin(9600);

  pinMode(11, OUTPUT);
}

void loop() {
  if (BTSerial.available()) {
    char ch = BTSerial.read();
    Serial.println(ch);

    if (ch == '1')
    {
      brightness-=10;
      if(brightness<0)
        brightness=0;
      analogWrite(11, brightness);
    }
    else
    {
      brightness+=10;
      if(brightness>255)
        brightness=255;
      analogWrite(11, brightness);
    }
  }
}
