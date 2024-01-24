#include <SoftwareSerial.h>       // 소프트웨어로 시리얼 통신을 제어하는 라이브러리
SoftwareSerial BTSerial(12, 13);  // 블루투스 모듈의 TXD: 12번핀, RXD: 13번핀

void setup() {
  // 시리얼 통신 초기화
  // HM-10은 보드 레이트가 9600으로 초기화되어 있음
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // 블루투스 모듈의 입력값이 있을 때 시리얼 모니터에 출력
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // 시리얼 모니터에 입력값이 있을 때 블루투스 모듈에 입력값 전달
  if (Serial.available())
    BTSerial.write(Serial.read());
}
