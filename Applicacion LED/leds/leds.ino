int redPin= 11;
int greenPin= 10;
int bluePin= 9;
char dato;
void setup(){
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}
void loop(){
  while(Serial.available()>0){
    int red=Serial.parseInt();
    int green=Serial.parseInt();
    int blue=Serial.parseInt();
    Serial.read();
      analogWrite(redPin,red);
      analogWrite(greenPin,green);
      analogWrite(bluePin,blue);
      Serial.print(red,HEX);
      Serial.print(green,HEX);
      Serial.print(blue,HEX);
  }
}

