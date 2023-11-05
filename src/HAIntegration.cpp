#include "HAIntegration.h"
#include "Credentials.h"

#include <ArduinoHA.h>
#include <WiFi.h>

//Adapted via:
//  https://github.com/dawidchyrzynski/arduino-home-assistant/blob/main/examples/nano33iot/nano33iot.ino

#define LED_PIN     LED_BUILTIN

WiFiClient client;
HADevice device;
HAMqtt mqtt(client, device);
HASwitch led("led");

void HAIntegration::configure() {

    //Prepare LED:

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);    
    
    //Set device ID as MAC address

    byte mac[WL_MAC_ADDR_LENGTH];
    WiFi.macAddress(mac);
    device.setUniqueId(mac, sizeof(mac));

    //Device metadata:

    device.setName("Pico W HA Starter");
    device.setSoftwareVersion("0.1");
    device.enableSharedAvailability(); // [OPTIONAL] Enables the ability to set the on/off line status of the device
    device.setAvailability(true); // Set the device to on-line
    device.enableLastWill(); // [OPTIONAL] Allows HA to detect when the device losses power (and thus disable the controls in the HA UI)

    // handle switch state
    led.onCommand(switchHandler);
    led.setName("Board LED"); // optional

    Serial.print("Connecting to MQTT\n");
    
    if (mqtt.begin(MQTT_BROKER, MQTT_LOGIN, MQTT_PASSWORD) == true) {
        Serial.print("Connected to MQTT broker");
    } else {
        Serial.print("Could not connect to MQTT broker");
    }
}

void HAIntegration::switchHandler(bool state, HASwitch* sender) {
    digitalWrite(LED_PIN, (state ? HIGH : LOW));
    sender->setState(state);  // report state back to Home Assistant
}


void HAIntegration::loop() {
    mqtt.loop();
}
