// 각 LED에 연결된 핀 번호
const int redLEDPin = 13;
const int greenLEDPin = 12;
const int blueLEDPin = 11;

// 각 버튼에 연결된 핀 번호
const int redButtonPin = 10;
const int greenButtonPin = 9;
const int blueButtonPin = 8;

// 피에조 스피커에 연결된 핀 번호
const int piezoPin = 2;

int memory[5];          // 기억하기 저장 변수
int answer[5];          // 따라 하기 저장 변수
int memoryLength = 5;   // 기억하기 단계
int answerCount = 0;    // 따라 하기 횟수
int playMode = 0;       // 0: 기억하기 모드, 1: 따라 하기 모드
int interval = 1000;    // 기억하기 LED의 출력 지연 시간

void setup() {
  // 각 LED 핀을 출력으로 설정
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

  // 각 버튼 핀을 입력으로 설정
  pinMode(redButtonPin, INPUT_PULLUP);
  pinMode(greenButtonPin, INPUT_PULLUP);
  pinMode(blueButtonPin, INPUT_PULLUP);

  // 시리얼 통신 초기화
  Serial.begin(9600);

  // 랜덤 시드 설정
  randomSeed(analogRead(0));
}

void loop() {

  if (playMode == 0) {
    // 게임 단계 생성 및 LED 점멸
    generateSequence();
    playMemoryGame();
    playMode = 1;
  }
  else {
    int redButtonValue = digitalRead(redButtonPin);
    int greenButtonValue = digitalRead(greenButtonPin);
    int blueButtonValue = digitalRead(blueButtonPin);

    // 누르는 버튼에 따라 따라 하기 정보 저장
    if (redButtonValue == LOW) {
      answer[answerCount++] = 0;
      delay(500);
    }
    else if (greenButtonValue == LOW) {
      answer[answerCount++] = 1;
      delay(500);
    }
    else if (blueButtonValue == LOW) {
      answer[answerCount++] = 2;
      delay(500);
    }

    if (answerCount >= memoryLength) {
      // 성공 여부에 따른 소리 출력
      int isSuccess = checkSuccess();
      if (isSuccess)
        winSound();
      else
        loseSound();

      // 게임 초기화
      answerCount = 0;
      playMode = 0;
    }
  }
}

// 기억하기 순서 생성
void generateSequence() {
  for (int i = 0; i < memoryLength; i++) {
    memory[i] = random(3);
    Serial.print(memory[i]);
    Serial.print(" ");
  }
  Serial.println();
}

// 기억력 게임 시작
void playMemoryGame() {

  // 게임 시작을 알리는 버저음
  tone(piezoPin, 440, 500);
  delay(1000);

  for (int i = 0; i < memoryLength; i++) {
    int currentLED = memory[i];
    if (currentLED == 0) {
      digitalWrite(redLEDPin, HIGH);
      delay(interval);
      digitalWrite(redLEDPin, LOW);
      delay(500);
    } else if (currentLED == 1) {
      digitalWrite(greenLEDPin, HIGH);
      delay(interval);
      digitalWrite(greenLEDPin, LOW);
      delay(500);
    } else if (currentLED == 2) {
      digitalWrite(blueLEDPin, HIGH);
      delay(interval);
      digitalWrite(blueLEDPin, LOW);
      delay(500);
    }
  }

  // 따라 하기 시작을 알리는 버저음
  tone(piezoPin, 440, 500);
  noTone(piezoPin);
}

// 성공 여부 확인 및 결과 반환
int checkSuccess() {
  int isSuccess = 1;
  for (int i = 0; i < memoryLength; i++) {
    Serial.print(answer[i]);
    Serial.print(" ");
    if (memory[i] != answer[i]) {
      isSuccess = 0;
    }
  }
  Serial.println();
  return isSuccess;
}

// 순서를 맞췄을 때 출력하는 소리
void winSound() {
  tone(piezoPin, 1000, 200);
  delay(300);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 1500, 300);
  delay(400);
  noTone(piezoPin);
  delay(500);
}

// 순서가 틀렸을 때 출력하는 소리
void loseSound() {
  tone(piezoPin, 1500, 300);
  delay(300);
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 1000, 200);
  delay(400);
  noTone(piezoPin);
  delay(500);
}
