void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(1250);
  Serial.write(10);
  delay(500);
}
