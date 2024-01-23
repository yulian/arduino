void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for(int i=0; i<=255; i++) { // 0부터 255까지 256번 반복
    analogWrite(9, i);        // i값을 PWM이 가능한 디지털 9번 핀에 써서 LED 밝기 조절
    Serial.println(i);
    delay(10);                // 10ms 지연
  }
}
