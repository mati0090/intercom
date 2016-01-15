#include <Arduino.h>

class ESP8266 {
public:
  boolean prepareModule();
  boolean connectToAP(String, String);
  boolean startTCPServer(int);

private:
  boolean sendCommand(String, char*);
  void logUnexpectedResponse(String, char*, String);
};

