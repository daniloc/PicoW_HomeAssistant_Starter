#include <WiFi.h>
#include "Network.h"
#include "Credentials.h"

int status;

void Network::connect() {
    while (status != WL_CONNECTED) {

    Serial.print("Attempting to connect to WPA SSID: ");

    Serial.println(WIFI_SSID);

    // Connect to WPA/WPA2 network:

    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //Set these credentials

    // wait to connect:

    delay(5000);

  }

  if (status == WL_CONNECTED) {
    Serial.println("Connected to");
    Serial.println(WIFI_SSID);
  }
}