#include <IRremote.h>
#define IR_RECEIVE_PIN 8  // 적외선 센서가 연결된 디지털 핀 번호
int brightness = 0;       // 밝기를 제어하는 변수
unsigned long lastValue = 0;

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(9, OUTPUT);     // 밝기를 제어할 LED의 핀 번호
  Serial.begin(9600);
}

void loop() {
  
  if (IrReceiver.decode()) {    // 적외선 센서의 수신값 해석
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    unsigned long data = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(brightness); // 밝기 변수값 출력

    if(data==0){
      data = lastValue;
    }

    if (data == 0xEF10BF00)       // 숫자 1 버튼이 눌리면 LED를 어둡게
    {
      brightness-=10;
      if(brightness<0)
        brightness=0;
      analogWrite(9, brightness);
    }
    else if (data == 0xEE11BF00)  // 숫자 2 버튼이 눌리면 LED를 밝게
    {
      brightness+=10;
      if(brightness>255)
        brightness=255;
      analogWrite(9, brightness);
    }

    delay(30);
    lastValue = data;             // 마지막 신홋값을 lastValue에 저장
    IrReceiver.resume();
  }
}
