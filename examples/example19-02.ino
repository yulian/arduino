int ledPins[] = {13, 12, 11, 10, 9, 8};   // 각 LED에 연결된 핀 번호
int buttonPin = 7;                        // 버튼에 연결된 핀 번호

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // 핀 모드 설정 및 시리얼 통신 초기화
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // 버튼 상태 읽기
  int buttonState = digitalRead(buttonPin);

  // 버튼이 눌리면 주사위 굴리기
  if (buttonState == LOW) {
    rollDice();
    delay(1000);
  }
}

// 주사위 굴리는 함수
void rollDice() {
  // 주사위 숫자 선택
  int diceNumber = random(1, 7);

  // 결과 출력
  Serial.print("Dice number: ");
  Serial.println(diceNumber);

  // LED 활성화
  displayLED(diceNumber);
}

// LED를 표시하는 함수
void displayLED(int number) {

  // 모든 LED 끄기
  for (int i=0; i < 6; i++){
    digitalWrite(ledPins[i], LOW);
  }

  // 주어진 숫자에 해당하는 LED 켜기
  for (int i=0; i < number; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}
