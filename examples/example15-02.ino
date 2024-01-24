const int melody[] = {    // 음계 별 주파수를 저장한 변수 선언
  262,	                  // '도'의 주파수
  294,	                  // '레'의 주파수
  330,	                  // '미'의 주파수
  349,                    // '파'의 주파수
  392,                    // '솔'의 주파수
  440,	                  // '라'의 주파수
  494,	                  // '시'의 주파수
  523,	                  // '(높은)도'의 주파수
};

const int PIEZO_PIN = 13; // 피에조 스피커에 연결된 디지털 핀 번호

void setup()
{
  pinMode(10, OUTPUT);    // 10번 핀을 트리거로 사용
  pinMode(9, INPUT);      // 9번 핀을 에코로 사용
  Serial.begin(9600);
}

void loop()
{
  // 초음파 신호 송신
  digitalWrite(10, LOW);
  delayMicroseconds(2);
  digitalWrite(10, HIGH);
  delayMicroseconds(10);
  digitalWrite(10, LOW);

  // 초음파 신호 수신
  pinMode(9, INPUT);
  double duration = pulseIn(9, HIGH);
  double cm = duration * 340 / 10000 / 2;

  // 측정 거리를 출력
  Serial.println(cm);

  // 거리에 따른 음계 출력
  if (cm < 3)
    tone(PIEZO_PIN, melody[0], 500);
  else if (cm < 6)
    tone(PIEZO_PIN, melody[1], 500);
  else if (cm < 9)
    tone(PIEZO_PIN, melody[2], 500);
  else if (cm < 12)
    tone(PIEZO_PIN, melody[3], 500);
  else if (cm < 15)
    tone(PIEZO_PIN, melody[4], 500);
  else if (cm < 18)
    tone(PIEZO_PIN, melody[5], 500);
  else if (cm < 21)
    tone(PIEZO_PIN, melody[6], 500);
  else if (cm < 24)
    tone(PIEZO_PIN, melody[7], 500);
  else
    ;   // 어떤 음도 출력하지 않는 코드
  delay(100);
}
