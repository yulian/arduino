int flag = 0;       // 버튼의 상태를 구분하기 위한 변수
int count = 0;      // 카운터 변수 초기화
int pinNumber = 8;  // 핀 개수
int ledPinNum[] = { 6, 7, 8, 9, 10, 11, 12, 13 };   // LED 제어를 위한 디지털 핀 번호

void setup()
{
  // LED 제어를 위한 출력 모드
  for(int i=0; i<pinNumber; i++) {
    pinMode(ledPinNum[i], OUTPUT);
  }

  // 버튼 제어를 위한 입력 모드
  pinMode(2, INPUT);
}

void loop()
{
  int inputValue = digitalRead(2);
  if (inputValue == HIGH) {           // 푸시 버튼이 눌렸을 때
    if (flag == 0) {                  // 상태 변경
      flag = 1;
    }

  } else {                            // 푸시 버튼이 떼어졌을 때
    if (flag == 1) {
      count++;                        // 카운트값 1씩 증가
      displayBinaryLED(count);        // 카운터값을 LED로 출력
      flag = 0;                       // 상태 구분 변수를 초기화
    }
  }
  delay(100);                         // 100ms 지연 시간
}

void displayBinaryLED(int num)
{
  for (int i = 0; i < pinNumber; i++) {
    int state = (num >> i) & 1;           // 각 비트의 상태를 가져옴
    digitalWrite(ledPinNum[i], state);    // LED 상태를 설정
  }
}
