void setup()
{
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
}

void loop()
{
  int readValue = analogRead(A0); // A0 핀에서 읽은 값을 readValue에 저장
  Serial.println(readValue);
  
  digitalWrite(13, LOW);
  delay(readValue);               // readValue값만큼 코드 실행을 기다립니다.
  digitalWrite(13, HIGH);
  delay(readValue);               // readValue값만큼 코드 실행을 기다립니다.
}
