void setup() {
  Serial.begin(9600);
  Serial.println("Enter a letter A - F:");
}

void loop() {
  char c;
  while(true){
    if(Serial.available()>0){
      c=Serial.read();
      c=toupper(c);

      switch(c){
        case 'A':
        Serial.println("Great job");
        break;
        case 'B':
        case 'C':
        Serial.println("You passed");
        break;
        case 'D':
        Serial.println("You're on the edge");
        break;
        case 'F':
        Serial.println("See you again next semester.");
        break;
        default;
        Serial.println("You can't even follo instructions?");
        break;
      }
    }
  }

}
