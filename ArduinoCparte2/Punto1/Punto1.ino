void setup() {
  Serial.begin(9600); //Inicializo el Arduino
}

void loop() {
  int finalValue; //Declaro una variable
  finalValue=addValue(1);
  if(finalValue>=100){
    Serial.println("The end!");
  }
  delay(100);
}
int addValue(int increment){
  int value=0;
  value=value + increment;
  return value;
}

