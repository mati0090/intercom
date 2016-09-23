#include <Arduino.h>
#include "config.h"

class Beeper {
public:
  Beeper();
  void on();
  void off();
private:
  void setState(int type);
};
  
