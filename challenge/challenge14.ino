#include <IRremote.h>

const int IR_RECEIVE_PIN = 4; // 적외선 센서가 연결된 디지털 핀 번호
const int MOTOR_PIN_A = 5;    // 왼쪽 DC모터의 빨간색 단자
const int MOTOR_PIN_B = 6;    // 왼쪽 DC모터의 검은색 단자
const int MOTOR_PIN_C = 9;    // 오른쪽 DC모터의 빨간색 단자
const int MOTOR_PIN_D = 10;   // 오른쪽 DC모터의 검은색 단자
unsigned long lastValue = 0;  // 적외선 수신 오류 제어 변수

void setup() {

  // 적외선 센서 활성화
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  
  // DC 모터와 연결된 디지털 핀을 출력 모드로 설정
  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);
  pinMode(MOTOR_PIN_C, OUTPUT);
  pinMode(MOTOR_PIN_D, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  if (IrReceiver.decode()) {    // 적외선 센서의 수신값 해석
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    unsigned long data = IrReceiver.decodedIRData.decodedRawData;

    if(data==0){
      data = lastValue;
    }

    // 적외선 신홋값에 따라 모터 제어
    if (data == 0xEE11BF00)         // 2번 버튼을 눌러 전진
      moveForward();
    else if (data == 0xE619BF00)    // 8번 버튼을 눌러 후진
      moveBackward();
    else if (data == 0xEB14BF00)    // 4번 버튼을 눌러 좌회전
      turnLeft();
    else if (data == 0xE916BF00)    // 6번 버튼을 눌러 우회전
      turnRight();
    else                            // 기타 버튼을 눌러 멈춤
      stopMoving();

    delay(30);
    lastValue = data;               // 정상적으로 수신된 값 저장
    IrReceiver.resume();            // 다음 신호를 받기 위해 초기화
  }
}

void moveForward() {
  analogWrite(MOTOR_PIN_A, 0);          // 왼쪽 DC모터를 역방향으로 회전
  analogWrite(MOTOR_PIN_B, 255);
  analogWrite(MOTOR_PIN_C, 255);        // 오른쪽 DC모터를 정방향으로 회전
  analogWrite(MOTOR_PIN_D, 0);
}

void moveBackward() {
  analogWrite(MOTOR_PIN_A, 255);        // 왼쪽 DC모터를 정방향으로 회전
  analogWrite(MOTOR_PIN_B, 0);
  analogWrite(MOTOR_PIN_C, 0);          // 오른쪽 DC모터를 역방향으로 회전
  analogWrite(MOTOR_PIN_D, 255);
}

void turnLeft() {
  analogWrite(MOTOR_PIN_A, 0);          // 왼쪽 DC모터를 역방향으로 느리게 회전
  analogWrite(MOTOR_PIN_B, 100);
  analogWrite(MOTOR_PIN_C, 255);        // 오른쪽 DC모터를 정방향으로 빠르게 회전
  analogWrite(MOTOR_PIN_D, 0);
}

void turnRight() {
  analogWrite(MOTOR_PIN_A, 0);          // 왼쪽 DC모터를 역방향으로 빠르게 회전
  analogWrite(MOTOR_PIN_B, 255);
  analogWrite(MOTOR_PIN_C, 100);        // 오른쪽 DC모터를 정방향으로 느리게 회전
  analogWrite(MOTOR_PIN_D, 0);
}

void stopMoving() {
  analogWrite(MOTOR_PIN_A, 0);          // 모든 DC모터의 속도를 0으로 설정
  analogWrite(MOTOR_PIN_B, 0);
  analogWrite(MOTOR_PIN_C, 0);
  analogWrite(MOTOR_PIN_D, 0);
}
