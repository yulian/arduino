void setup()              // 전원이 들어오면 가장 먼저 한 번만 실행
{
  pinMode(13, OUTPUT);    // 13번 핀을 출력 모드로 선언
}

void loop()               // 수 마이크로초 주기로 반복 실행
{
  digitalWrite(13, HIGH); // 13번 핀에 HIGH 신호를 보냄
  delay(1000);            // 1000ms(1초) 동안 지연
  digitalWrite(13, HIGH); // 13번 핀에 LOW 신호를 보냄
  delay(1000);            // 1000ms(1초) 동안 지연
}
