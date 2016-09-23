#include <Arduino.h>
#include "config.h"

class Relay {
public:
  Relay();
  void on();
  void off();
};
