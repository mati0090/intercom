
#include "config.h"
#include "esp8266.h"
#include "beeper.h"
#include "relay.h"

ESP8266 wifi;
Beeper beeper;
Relay relay;

void dataReceiveCallback(char *data){
  if(strstr(data,"open!") != NULL){
    beeper.on();
    relay.on();
    delay(1000);
    beeper.off();
    delay(4000);
    relay.off();
  }
}

void setup() { 
  Serial1.begin(115200);

  #ifdef DEBUG
  Serial.begin(115200);
  while(!Serial);
  #endif

  wifi.prepareModule();
  wifi.connectToAP(SSID, PASS);
  wifi.startTCPServer(666);
}

void loop() {
  wifi.handleIncomingData(&dataReceiveCallback);
}


