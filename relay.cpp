#include "relay.h"

Relay::Relay(){
  pinMode(RELAY_PIN, OUTPUT);
}

void Relay::on(){
  digitalWrite(RELAY_PIN, HIGH);
}

void Relay::off(){
  digitalWrite(RELAY_PIN, LOW);  
}

