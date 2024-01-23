#include <Servo.h>

Servo myServo;

void setup()
{
  // 아두이노의 디지털 9번 핀을 서보 모터 제어에 사용하기 위해 매핑
  myServo.attach(9);
}

void loop()
{
  // 서보 모터의 각도를 0~180°까지 바꿈
  for(int angle=0; angle<=180; angle++) {
    myServo.write(angle);
    delay(100); // 원활한 작동을 위해 지연 시간 추가
  }
}
