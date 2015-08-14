void setup() {
  Serial.begin(9600);
  Serial.println("Enter a letter A - F:");
}

void loop() {
  char c;
  while(true){
    if(Serial.available()>0){ //Ciclo donde se valida que ese serial se mayor que cero
      c=Serial.read();//el char es leido
      c=toupper(c);//convierte el caracter a mayuscula.

      switch(c){ //Ciclo con una serie de posibilidades donde de acuerdo a la opcion nos dice algo
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
        default:
        Serial.println("You can't even follo instructions?");
        break;
      }
    }
  }

}
