int status = 0; // LED의 상태를 나타내는 변수, 0이면 꺼짐 1이면 켜짐

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char inputValue = Serial.read();            // 시리얼 모니터에서 사용자 입력을 받음
  if (status == 0 && inputValue == '1')       // 사용자 입력을 비교해 LED를 켬
  {
    digitalWrite(13, HIGH);
    status = 1;                               // LED의 상태를 켜진 상태로 변경
  }
  else if (status == 1 && inputValue == '0')  // 사용자 입력을 비교해 LED를 끔
  {
    digitalWrite(13, LOW);
    status = 0;                               // LED의 상태를 꺼진 상태로 변경
  }
}
