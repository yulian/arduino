#include <IRremote.h>
#define IR_RECEIVE_PIN 8  // 적외선 센서가 연결된 디지털 핀 번호
const int RED_PIN = 11;   // RED_PIN 상수를 선언
const int GREEN_PIN = 9;  // GREEN_PIN 상수를 선언
const int BLUE_PIN = 10;  // BLUE_PIN 상수를 선언
unsigned long lastValue = 0;

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  // 삼색 LED와 연결된 핀을 출력 모드로 설정
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  if (IrReceiver.decode()) {  // 적외선 센서의 수신값 해석
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    unsigned long data = IrReceiver.decodedIRData.decodedRawData;

    if(data==0){
      data = lastValue;
    }
    
    if (data == 0xEF10BF00)       // 리모컨의 숫자 1 버튼 누름
      printRGB(255, 105, 180);    // 삼색 LED에 분홍색 불빛 켜기
    else if (data == 0xEE11BF00)  // 리모컨의 숫자 2 버튼 누름
      printRGB(0, 255, 255);      // 삼색 LED에 하늘색 불빛 켜기
    else if (data == 0xED12BF00)  // 리모컨의 숫자 3 버튼 누름
      printRGB(0, 255, 0);        // 삼색 LED에 초록색 불빛 켜기
    else
      printRGB(0, 0, 0);          // 기타 다른 버튼을 누르면 삼색 LED 끔

    delay(30);
    lastValue = data;             // 마지막 신홋값을 lastValue에 저장
    IrReceiver.resume();
  }
}

void printRGB(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}
