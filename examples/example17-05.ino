#include <Adafruit_NeoPixel.h>

#define PIN       2 // 제어를 위한 디지털 핀 번호
#define NUMPIXELS 4 // 네오픽셀의 LED 수

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // 네오픽셀 라이브러리 초기화
  pixels.begin();
}

void loop() {
  setColor();
  delay(100);
}

// 임의의 RGB 색상을 변경하는 함수
void setColor() {
  for (int i=0; i<4; i++) {
    int redColor = random(0, 256);
    int greenColor = random(0,256);
    int blueColor = random(0, 256);
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
    pixels.show();
  }
}
