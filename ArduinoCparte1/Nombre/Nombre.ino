// Declaración del arreglo
//char Nombre[8]= "Jessica";
int Nombre[8]= {'J','e','s','s','i','c','a'};
int c=0;
void setup(){
  Serial.begin(9600); //Inicializo el puerto Serial.
}
void loop(){
  for (c=0;c<7;c++){
    Serial.println(Nombre[c]);//Imprimo la información
    delay(500);
  }
}
