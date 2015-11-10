#include<Bridge.h>
#include<Parse.h>
void setup() {
  Bridge.begin();
  Serial.begin(115200);
  pinMode(5, INPUT);
   
  
  while(!Serial);

  Serial.println("Parse Started Project");
  // Initialize Parse
  Parse.begin("3HTiQIaDzmjjV6pM0tH3q69YgQVbtahYSX6uGica", "ZIfe7r7Gb4g6uA9X7baIXGd7zwN4pBqyCWMdrnM0");

  Parse.startPushService();
  Serial.print("Push Installation ID:");
  Serial.println(Parse.getInstallationId());
}
int s=0;
void loop() {
  //Check if there is a new push
  //A push thith message {"alert": "A test push from Parse!"}
  int val;
    val=digitalRead(5); //turn on LED
     if(val!=s){
     ParseObjectUpdate update;
     update.setClassName("IoTvalue");
     update.setObjectId("zr0beAtHVp");
     update.add("Valor", val);
     update.send();
     s=val;
     delay(300);
     }
  if(Parse.pushAvailable()){
    ParsePush push = Parse.nextPush();

    String message = push.getJSONBody();
    Serial.print("New push message size: ");
    Serial.println(message.length());
    Serial.print("New push message content: ");
    Serial.println(message);

    String command = push.getString("alert");
    if(command == "A test push from Parse!"){
      digitalWrite(13,HIGH);
      delay(3000);
      digitalWrite(13,LOW); //turn off LED
    }

   
    //NOTE: ensure to close current push message
    //Otherwise next push won't be available
    push.close();
  }
}
