const int soundSensorPin = A0;      // 소리 감지 센서 모듈을 연결한 핀 번호
const int ledPin = 13;              // 아두이노에 LED를 연결한 핀 번호

int clapCount = 0;                  // 박수 소리를 감지하기 위한 변수
unsigned long previousTime = 0;     // 이전 시간을 저장하는 변수
unsigned long clapInterval = 500;   // 박수 소리의 간격을 정의하는 변수
const int thresholdValue = 100;     // 박수 소리 감지를 위한 임계치 설정

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //밀리초 단위의 현재 시간
  unsigned long currentTime = millis();

  //소리 감지 센서 모듈에서 값을 읽음
  int sensorValue = analogRead(soundSensorPin);

  // 시리얼 모니터에 값을 출력
  Serial.println(sensorValue);

  // 임계치 이상의 소리가 감지되면 박수 소리를 인식
  if (sensorValue > thresholdValue) {
    if (currentTime - previousTime > clapInterval) {
      clapCount++;
      previousTime = currentTime;
    }
  }

  // 박수 소리가 감지되면 LED의 상태를 변경
  if (clapCount >= 1) {
    int status = digitalRead(ledPin);
    digitalWrite(ledPin, !status);
    clapCount = 0;    // 박수 소리 감지 횟수 초기화
  }

  //지연시간
  delay(50);
}
