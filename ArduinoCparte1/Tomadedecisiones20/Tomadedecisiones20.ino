int searchList[200];

void setup(){
  int index; // se declara una variable
  int target = 5343;// se declara una variable y se le da un valor 
  Serial.begin(115200); // Se inicializa el Arduino
  memset(searchList, 0, sizeof(searchList)); //Rellena el bloque de memoria
  searchList[160] = target; 
  
  index=0; //Inicialización del contador
  while(true){ //Iniciación del ciclo while
    if(searchList[index] == target){ //Condicion que el valor de index se igual a target
      break;
    }
    index++; //Contador 
  }
  
  Serial.print("Found target at index= "); //Imprime en pantalla
  Serial.println(index);//Imprime en pantalla el valor de index
}

void loop(){}
