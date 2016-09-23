
#include "config.h"
#include "esp8266.h"
#include "beeper.h"

ESP8266 wifi;
Beeper beeper;

void dataReceiveCallback(char *data){
  Serial.println(data);
}

void setup() { 
  Serial.begin(115200);
  Serial1.begin(115200);

  while(!Serial);

  wifi.prepareModule();
  wifi.connectToAP(SSID, PASS);
  wifi.startTCPServer(666);
}

void loop() {
  wifi.handleIncomingData(&dataReceiveCallback);
}


