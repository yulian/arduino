void setup()
{
  Serial.begin(9600);             // 시리얼 통신 초기화
}

void loop()
{
  int readValue = analogRead(A0); // A0 단자에서 측정되는 아날로그 신홋값을 저장
  Serial.println(readValue);      // 아날로그 값 출력
}
