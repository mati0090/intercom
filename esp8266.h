#include <Arduino.h>

class ESP8266 {
public:
  boolean prepareModule();
  boolean connectToAP(String, String);
//  boolean startTCPServer(int);
//  boolean hasNewTCPConnection();

private:
//  boolean sendCommand(String, const int);
  boolean sendCommand(String, char*);
  void logUnexpectedResponse(String, char*, String);
};

