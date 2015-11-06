#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information, as described below

int numRuns = 1;   // Execution count, so this doesn't run forever
int maxRuns = 1;   // Maximum number of times the Choreo should be executed
String D;
float T;
String data;
String nombre;

void setup() {
  Serial.begin(9600);
  
  // For debugging, wait until the serial console is connected
  delay(4000);
  while(!Serial);
  Bridge.begin();
}

void loop() {
  if (numRuns <= maxRuns) {
 Serial.println("Running GetWeatherByAddress - Run #" + String(numRuns++));

    TembooChoreo GetWeatherByAddressChoreo;
   

    // Invoke the Temboo client
    GetWeatherByAddressChoreo.begin();

    // Set Temboo account credentials
    GetWeatherByAddressChoreo.setAccountName(TEMBOO_ACCOUNT);
    GetWeatherByAddressChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    GetWeatherByAddressChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // Set Choreo inputs
    GetWeatherByAddressChoreo.addInput("Units", "c");
    GetWeatherByAddressChoreo.addInput("Address", "medellin");
    GetWeatherByAddressChoreo.addInput("Day", "1");
    
    // Identify the Choreo to run
   GetWeatherByAddressChoreo.setChoreo("/Library/Yahoo/Weather/GetWeatherByAddress");
    
    // Run the Choreo; when results are available, print them to serial
      GetWeatherByAddressChoreo.run();
    
    while(GetWeatherByAddressChoreo.available()) {
      String nombre = GetWeatherByAddressChoreo.readStringUntil('\x1F');
      nombre.trim();
       String data = GetWeatherByAddressChoreo.readStringUntil('\x1E');
      data.trim();
if(nombre=="date"){
  D=data;
}
else if(nombre=="temperature"){

  T=data.toFloat();
}
 }
   Serial.println(D+"," +T);

    Serial.println("Running AppendRow - Run #" + String(numRuns++));
    
    TembooChoreo AppendRowChoreo;

    // Invoke the Temboo client
    AppendRowChoreo.begin();

    // Set Temboo account credentials
    AppendRowChoreo.setAccountName(TEMBOO_ACCOUNT);
    AppendRowChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    AppendRowChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // Set Choreo inputs
    AppendRowChoreo.addInput("ClientSecret", "6NCel47dV_IUIZPX4op1ETVm");
    AppendRowChoreo.addInput("RefreshToken", "1/gL7zhis_r_UOMq-QyUiZwq419NFEvswa3oArPDEyST8");
     Serial.println(D+"," +T);

    
    AppendRowChoreo.addInput("RowData", D+"," +T);
    AppendRowChoreo.addInput("SpreadsheetTitle", "Sensor IoT");
    AppendRowChoreo.addInput("ClientID", "741260996893-15e16ueq8i58le4k9o95adn4e4ivmoq8.apps.googleusercontent.com");
    
    // Identify the Choreo to run
    AppendRowChoreo.setChoreo("/Library/Google/Spreadsheets/AppendRow");
    
    // Run the Choreo; when results are available, print them to serial
    //AppendRowChoreo.run();
    
    while(AppendRowChoreo.available()) {
      char c = AppendRowChoreo.read();
      Serial.print(c);
      
    Serial.println("Running SendEmail - Run #" + String(numRuns++));
    
    TembooChoreo SendEmailChoreo;

    // Invoke the Temboo client
    SendEmailChoreo.begin();

    // Set Temboo account credentials
    SendEmailChoreo.setAccountName(TEMBOO_ACCOUNT);
    SendEmailChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendEmailChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // Identify the Choreo to run
    SendEmailChoreo.setChoreo("/Library/Google/Gmail/SendEmail");
    
    // Run the Choreo; when results are available, print them to serial
    SendEmailChoreo.run();
    
    while(SendEmailChoreo.available()) {
      char c = SendEmailChoreo.read();
      Serial.print(c);

    Serial.println("Running SendEmail - Run #" + String(numRuns++));
    
    TembooChoreo SendEmailChoreo;

    // Invoke the Temboo client
    SendEmailChoreo.begin();

    // Set Temboo account credentials
    SendEmailChoreo.setAccountName(TEMBOO_ACCOUNT);
    SendEmailChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendEmailChoreo.setAppKey(TEMBOO_APP_KEY);
    
    // Identify the Choreo to run
    SendEmailChoreo.setChoreo("/Library/Google/Gmail/SendEmail");
    
    // Run the Choreo; when results are available, print them to serial
    SendEmailChoreo.run();
    
    while(SendEmailChoreo.available()) {
      char c = SendEmailChoreo.read();
      Serial.print(c);
    }
    SendEmailChoreo.close();
      
    }
    AppendRowChoreo.close();
  }

  Serial.println("Waiting...");
  delay(30000); // wait 30 seconds between AppendRow calls
}
}
