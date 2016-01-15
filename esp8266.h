#include <Arduino.h>
#include "config.h"

typedef void (*DataCallback)(char *);

class ESP8266 {
public:
  boolean prepareModule();
  boolean connectToAP(String, String);
  boolean startTCPServer(int);
  void handleIncomingData(DataCallback);

private:
  boolean sendCommand(String, char*);
  void logUnexpectedResponse(String, char*, String);
};

