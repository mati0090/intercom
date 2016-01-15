
#include "esp8266.h"

// These are the SSID and PASSWORD to connect to your Wifi Network
#define SSID  ""
#define PASS  ""

ESP8266 wifi;

void setup() { 
  Serial.begin(115200);
  Serial1.begin(115200);

  while(!Serial);

  wifi.prepareModule();
  wifi.connectToAP(SSID, PASS);
  wifi.startTCPServer(666);
}

void loop() {
  

}

