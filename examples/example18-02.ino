const int irPin = 2;        // 적외선 추적 센서를 연결한 핀 번호

void setup() {
  Serial.begin(9600);       // 시리얼 통신 시작
  pinMode(irPin, INPUT);    // 센서 핀을 입력 모드로 설정
}

void loop() {
  // 적외선 센서에서 값을 읽음
  int sensorValue = digitalRead(irPin);

  // 시리얼 모니터에 값을 출력
  Serial.print("IR Sensor Value: ");
  Serial.println(sensorValue);

  // 측정 대기 시간
  delay(500);
}
