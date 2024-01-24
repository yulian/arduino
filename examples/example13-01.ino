#include <IRremote.h>
#define IR_RECEIVE_PIN 8  // 적외선 센서가 연결된 디지털 핀 번호

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  if (IrReceiver.decode()) {  // 적외선 센서의 수신값 해석
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    unsigned long data = IrReceiver.decodedIRData.decodedRawData;
    if (data == 0xF30CBF00)   // 적외선 리모컨의 숫자 0을 누를 때 수신하는 값
      digitalWrite(9, HIGH);
    else
      digitalWrite(9, LOW);
    delay(30);
    IrReceiver.resume();
  }
}
