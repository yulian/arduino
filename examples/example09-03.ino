void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  int i = random(3);          // 임의의 수 반환 0~(N-1)
  int pinNumber = i+9;        // PWM을 지원하는 핀 번호 가져오기
  int intensity = 0;

  while (intensity <= 255) {  // 서서히 밝아지게 만들기
    analogWrite(pinNumber, intensity++);
    delay(10);
  }

  while (intensity >= 0) {    // 서서히 어두워지게 만들기
    analogWrite(pinNumber, intensity--);
    delay(10);
  }
}
