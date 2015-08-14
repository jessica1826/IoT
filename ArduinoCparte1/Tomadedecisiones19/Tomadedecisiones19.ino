void setup(){
  int k;
  Serial.begin(9600);
  
  for (k=0,Serial.print("Expl1 k= "),Serial.println(k);
      Serial.print("Exp2 k = "), Serial.println(k),k<10;
      k++, Serial.print("Exp3 k = "), Serial.println(k)){
        
        Serial.print("In loop body, k squared = ");
        Serial.println(k*k);
        delay(1000);
      }
}
void loop(){}
