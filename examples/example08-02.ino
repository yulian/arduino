void setup()
{
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);            // 디지털 13번 핀을 출력모드로 변경
}

void loop()
{
  int readValue = analogRead(A0); // A0 핀에서 읽은 값을 readValue에 저장
  Serial.println(readValue);
  
  if(readValue < 500)             // readValue값이 500 미만이라면 14행 코드를 실행
    digitalWrite(13, LOW);
  else                            // readValue값이 500 이상이라면 16행 코드를 실행
    digitalWrite(13, HIGH);
}
