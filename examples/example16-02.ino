#include <SoftwareSerial.h>
SoftwareSerial BTSerial(12, 13);  // 블루투스 모듈의 TXD: 12번핀, RXD: 13번핀

void setup() {
  // 시리얼 통신 초기화
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
    char ch = BTSerial.read();
    Serial.println(ch);

    if (ch == '1')
      digitalWrite(11, HIGH);
    else
      digitalWrite(11, LOW);
  }
}
