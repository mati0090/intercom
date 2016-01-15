#include "esp8266.h"

#define DEFAULT_TIMEOUT 1000

boolean ESP8266::sendCommand(String command, char *requiredResponse) {
  String response;
  Serial1.println(command);

  if(response = Serial1.readString()){
    if(response.indexOf(requiredResponse) >= 0){
      return true;
    } else {
      logUnexpectedResponse(command, requiredResponse, response);
      return false;
    }
  }
  
  return false;
}

boolean ESP8266::prepareModule(){
  sendCommand("AT+RST", "ready");
}

boolean ESP8266::connectToAP(String essid, String password){
  sendCommand("AT+CWMODE=3", "OK");
}

void ESP8266::logUnexpectedResponse(String command, char *requiredResponse, String response){
  Serial.println("==== UNEXPECTED RESPONSE =====");
  Serial.println("Expected:");
  Serial.println(requiredResponse);
  Serial.println("Received:");
  if(Serial1.available()){
    Serial.println("empty response");
  }else{
    Serial.println(response);
  }
}


