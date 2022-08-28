#include <Arduino.h>
#include "HAIntegration.h"
#include "Network.h"

HAIntegration integration;

void setup() {
  Serial.begin();

  delay(1000); //Give the serial terminal a chance to connect, if present

  Network::connect();
  integration.configure();
}

void loop() {
  integration.loop();
}