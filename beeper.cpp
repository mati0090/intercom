#include "beeper.h"

Beeper::Beeper(){
  pinMode(BEEPER_PIN, OUTPUT);
}

void Beeper::on(){
  digitalWrite(BEEPER_PIN, HIGH);
}

void Beeper::off(){
  digitalWrite(BEEPER_PIN, LOW);
}

