// 플레이어 버튼 및 LED 핀 번호
const int p1Button = 13;
const int p2Button = 2;
const int p1Led = 12;
const int p2Led = 3;

// 게임 시작을 알리는 LED 핀 번호
const int gameStartLed = 7;

// 버튼을 누른 순서를 저장하는 변수
int p1Pressed = 0;
int p2Pressed = 0;

// 게임 시작과 종료를 알리는 변수
int isStarted = 0;

void setup() {
  // 버튼과 LED 핀 설정
  pinMode(p1Button, INPUT_PULLUP);
  pinMode(p2Button, INPUT_PULLUP);
  pinMode(p1Led, OUTPUT);
  pinMode(p2Led, OUTPUT);
  pinMode(gameStartLed, OUTPUT);
}

void loop() {
  // 게임 시작
  if (isStarted == 0) {
    int second = random(5);
    delay(1000 * second);
    digitalWrite(gameStartLed, HIGH);
    isStarted = 1;
  }

  // 각 플레이어의 버튼 상태를 읽음
  int p1State = digitalRead(p1Button);
  int p2State = digitalRead(p2Button);

  // 플레이어 1이 먼저 버튼을 누른 경우
  if (isStarted == 1 && p1State == LOW && p1Pressed == 0 && p2Pressed == 0) {
    p1Pressed = 1;
    digitalWrite(p1Led, HIGH);    // LED를 켜서 플레이어 1의 승리를 나타냄
    resetGame();
  }

  // 플레이어 2가 먼저 버튼을 누른 경우
  if (isStarted == 1 && p2State == LOW && p1Pressed == 0 && p2Pressed == 0) {
    p2Pressed = 1;
    digitalWrite(p2Led, HIGH);    // LED를 켜서 플레이어 2의 승리를 나타냄
    resetGame();
  }

  // 잠시 대기
  delay(100);
}

// 게임 초기화 함수
void resetGame() {
  delay(2000);
  digitalWrite(p1Led, LOW);
  digitalWrite(p2Led, LOW);
  digitalWrite(gameStartLed, LOW);
  isStarted = 0;
  p1Pressed = 0;
  p2Pressed = 0;
}
