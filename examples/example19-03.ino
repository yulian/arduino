#include <Servo.h>

// 서보 모터에 연결된 핀 번호
const int scissorServoPin = 10;
const int rockServoPin = 9;
const int paperServoPin = 8;

// 푸시 버튼에 연결된 핀 번호
const int scissorButtonPin = 7;
const int rockButtonPin = 6;
const int paperButtonPin = 5;

// LED에 연결된 핀 번호
const int loseLED = 13;
const int winLED = 12;

// 서보 객체 생성
Servo scissorServo;
Servo rockServo;
Servo paperServo;

void setup() {
  // 서보 모터 핀을 출력으로 설정
  scissorServo.attach(scissorServoPin);
  rockServo.attach(rockServoPin);
  paperServo.attach(paperServoPin);

  // 서보 모터를 초기 위치로 조정
  scissorServo.write(0);
  rockServo.write(0);
  paperServo.write(0);

  // 푸시 버튼 핀을 입력으로 설정
  pinMode(scissorButtonPin, INPUT_PULLUP);
  pinMode(rockButtonPin, INPUT_PULLUP);
  pinMode(paperButtonPin, INPUT_PULLUP);

  // LED 핀을 출력으로 설정
  pinMode(loseLED, OUTPUT);
  pinMode(winLED, OUTPUT);

  // 시리얼 통신 시작
  Serial.begin(9600);
}

void loop() {
  // 가위, 바위, 보 버튼의 상태 읽기
  int scissorButtonState = digitalRead(scissorButtonPin);
  int rockButtonState = digitalRead(rockButtonPin);
  int paperButtonState = digitalRead(paperButtonPin);

  // 상대방 가위바위보(0:가위, 1:바위, 2:보)
  int comState = random(3);

  // 가위 버튼을 누를 때 승패 표시
  if (scissorButtonState == LOW) {
    determineWinner(comState, 0);
    delay(1000);
  }

  // 바위 버튼을 누를 때 승패 표시
  if (rockButtonState == LOW) {
    determineWinner(comState, 1);
    delay(1000);
  }

  // 보 버튼을 누르면 보 모양을 표시
  if (paperButtonState == LOW) {
    determineWinner(comState, 2);
    delay(1000);
  }

  delay(100);
}

// 승자 결정 함수
void determineWinner(int comState, int userState) {
  if ((userState == 0 && comState == 2) ||    // 사용자가 이기는 경우의 조건식
      (userState == 1 && comState == 0) ||
      (userState == 2 && comState == 1)) {
        Serial.println("You win!");
        digitalWrite(winLED, HIGH);
        digitalWrite(loseLED, LOW);
  } else if (comState == userState) {         // 비기는 경우의 조건식
    Serial.println("It's a tie!");
    digitalWrite(winLED, HIGH);
    digitalWrite(loseLED, HIGH);
  } else {                                    // 사용자가 질 경우
    Serial.println("You lose!");
    digitalWrite(winLED, LOW);
    digitalWrite(loseLED, HIGH);
  }

  // 컴퓨터의 가위바위보 상태 표시
  if (comState == 0) {
    displayScissor();
  }
  else if (comState == 1) {
    displayRock();
  }
  else {
    displayPaper();
  }

  // 게임 초기화
  digitalWrite(winLED, LOW);
  digitalWrite(loseLED, LOW);
}

// 가위 모양 표시 함수
void displayScissor() {
  scissorServo.write(90);
  delay(2000);
  scissorServo.write(0);
}

// 바위 모양 표시 함수
void displayRock() {
  rockServo.write(90);
  delay(2000);
  rockServo.write(0);
}

// 보 모양 표시 함수
void displayPaper() {
  paperServo.write(90);
  delay(2000);
  paperServo.write(0);
}
