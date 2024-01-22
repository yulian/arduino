void setup()
{
  pinMode(13, OUTPUT);    // 빨간색 LED(13번 핀)를 출력 모드로 설정
  pinMode(12, OUTPUT);    // 주황색 LED(12번 핀)를 출력 모드로 설정
  pinMode(11, OUTPUT);    // 초록색 LED(11번 핀)를 출력 모드로 설정
}

void loop()
{
  digitalWrite(13, HIGH); // 빨간색 LED(13번 핀) 켜기
  digitalWrite(12, LOW);  // 주황색 LED(12번 핀) 끄기
  digitalWrite(11, LOW);  // 초록색 LED(11번 핀) 끄기
  delay(3000);            // 3초 동안 지연

  digitalWrite(13, LOW);  // 빨간색 LED(13번 핀) 끄기
  digitalWrite(12, HIGH); // 주황색 LED(12번 핀) 켜기
  digitalWrite(11, LOW);  // 초록색 LED(11번 핀) 끄기
  delay(1000);            // 1초 동안 지연

  digitalWrite(13, LOW);  // 빨간색 LED(13번 핀) 끄기
  digitalWrite(12, LOW);  // 주황색 LED(12번 핀) 끄기
  digitalWrite(11, HIGH); // 초록색 LED(11번 핀) 켜기
  delay(2000);            // 2초 동안 지연
}
