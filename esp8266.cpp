#include "esp8266.h"

boolean ESP8266::sendCommand(String command, char *requiredResponse) {
  String response;
  
  #ifdef DEBUG
  Serial.print(command);
  #endif
  
  Serial1.println(command);

  //sometimes we need to wait few seconds for response
  long int time = millis();
  while ( (time + DEFAULT_TIMEOUT) > millis()) {
    if(Serial1.available()) {
      response+=(char)Serial1.read();

      if(response.indexOf(requiredResponse) >= 0){
        #ifdef DEBUG
        Serial.println(" [OK]");
        #endif
        return true;
      }
    }
  }
  
  #ifdef DEBUG
  logUnexpectedResponse(command, requiredResponse, response);
  #endif
  
  return false;
}

boolean ESP8266::prepareModule(){
  sendCommand("AT+RST", "ready");
}

boolean ESP8266::connectToAP(String ssid, String password){
  sendCommand("AT+CWMODE=1", "OK");
  sendCommand("AT+CWQAP", "OK");
  
  char command[BUFF_SIZE];

  sprintf(command, "AT+CWJAP=\"%s\",\"%s\"", ssid.c_str(), password.c_str());

  sendCommand(command, "OK");
}

boolean ESP8266::startTCPServer(int port){
  sendCommand("AT+CIPMUX=1", "OK"); // configure for multiple connections
  
  char command[BUFF_SIZE];

  sprintf(command, "AT+CIPSERVER=1,%d", port);

  sendCommand(command, "OK");
  sendCommand("AT+CIPSTO=10", "OK");
}

void ESP8266::handleIncomingData(DataCallback dataCallback){
  char buff[BUFF_SIZE] = "\0";
  int index=0;

  while (Serial1.available()) {
    buff[index] = (char)Serial1.read();  
    index++;
    delay(5);
  }

  if(index != 0){
    dataCallback(buff);
  }
}

void ESP8266::logUnexpectedResponse(String command, char *requiredResponse, String response){
  Serial.println();
  Serial.println("==== UNEXPECTED RESPONSE =====");
  Serial.println("Expected:");
  Serial.println(requiredResponse);
  Serial.println("Received:");
  if(Serial1.available()){
    Serial.println("empty response");
  }else{
    Serial.println(response);
  }
  Serial.println("==============================");
}


