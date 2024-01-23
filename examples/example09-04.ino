void setup()
{
  pinMode(11, OUTPUT);          // 빨강(Red) 단자의 출력모드
  pinMode(10, OUTPUT);          // 파랑(Blue) 단자의 출력모드
  pinMode(9 , OUTPUT);          // 녹색(Green) 단자의 출력모드
  
  Serial.begin(9600);
}

void loop()
{
  int red = random(256);        // 0~'매개변수 - 1' 사이의 수를 무작위로 반환
  int blue = random(0, 256);    // 첫 번째 매개변수~'두 번째 매개변수 - 1' 사이의 수를 무작위로 반환
  int green = random(0, 256);
  
  analogWrite(11, red);         // 임의의 값으로 색상 출력
  analogWrite(10, blue);
  analogWrite(9, green);
  
  Serial.print("R:");           // 시리얼 모니터에 값 출력
  Serial.print(red);
  Serial.print("\tB:");         // 탭 추가
  Serial.print(blue);
  Serial.print("\tG:");         // 탭 추가
  Serial.println(green);
  
  delay(100);
}
