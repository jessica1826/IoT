void setup(){
  int k;
  Serial.begin(9600);//Inicialización puerto serial.
  
  for (k=0,Serial.print("Expl1 k= "),Serial.println(k);//Expresion 1
      Serial.print("Exp2 k = "), Serial.println(k),k<10;//Expresion 2
      k++, Serial.print("Exp3 k = "), Serial.println(k)){//Expresion 3
        
        Serial.print("In loop body, k squared = ");
        Serial.println(k*k);
        delay(1000);
      }
}
void loop(){}
