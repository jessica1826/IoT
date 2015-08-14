int searchList[200];

void setup(){
  int index;
  int target = 5343;
  Serial.begin(115200);
  memset(searchList, 0, sizeof(searchList));
  searchList[160] = target;
  
  index=0;
  while(true){
    if(searchList[index] == target){
      break;
    }
    index++;
  }
  
  Serial.print("Found target at index= ");
  Serial.println(index);
}

void loop(){}
