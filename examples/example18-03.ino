void setup() {
  Serial.begin(9600);
}

void loop() {
  int moisture = analogRead(A0);
  Serial.println(moisture);
  delay(100);
}
