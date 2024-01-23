#include <Servo.h>

Servo myServo;

void setup() {
  
  // 아두이노의 디지털 9번핀을 서보모터 제어에 사용
  myServo.attach(9);
  
  // PIR센서의 값을 읽을 디지털 핀을 7번으로 설정
  pinMode(7, INPUT);
}

void loop() {
  
  // PIR 센서로 움직임 감지 시 서보 모터 제어
  int detect = digitalRead(7);
  if(detect == HIGH) {
    myServo.write(90);    // 서보 모터의 각도를 90°로 조절합니다.
    delay(5000);
  }
  else {
    myServo.write(0);     // 서보 모터의 각도를 0°로 조절합니다.
    delay(100);
  }
}
