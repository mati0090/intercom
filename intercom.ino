
#include "esp8266.h"

// These are the SSID and PASSWORD to connect to your Wifi Network
#define SSID  "ASUS-6E80"
#define PASS  "dudekppg"

ESP8266 wifi;

void setup() { 
  Serial.begin(115200);
  Serial1.begin(115200);

  while(!Serial);

  Serial.println("Hello!");

  wifi.prepareModule();
  wifi.connectToAP(SSID, PASS);  
}

void loop() {
  

}

