# Raspberry Pi Pico W Home Assistant Starter Project

This is a [PlatformIO](https://platformio.org) project that instantly integrates a Raspberry Pi Pico W into Home Assistant via MQTT.

Fill out `src/Credentials.h`, upload to your Pico W, then you'll have a working integration that allows you to toggle the Pico W's board LED from the Home Assistant dashboard. From this starter you'll have a solid foundation to build a custom device in a private, local Intranet of Things.

This readme will provide pointers to everything needed to get started.

## Dependencies

- [Raspberry Pi Pico W](https://www.raspberrypi.com/products/raspberry-pi-pico/?variant=raspberry-pi-pico-w), a $6 microcontroller board with WiFi
- [PlatformIO](https://platformio.org/platformio-ide), an extension for [VSCode](https://code.visualstudio.com) with the most robust and reliable Arduino developer experience
- [`arduino-pico`](https://github.com/earlephilhower/arduino-pico): a community-developed Arduino core for Pico/Pico W with constant updates and excellent support for existing Arduino code
- [`arduino-home-assistant`](https://github.com/dawidchyrzynski/arduino-home-assistant): a thorough Arduino/Home Assistant integration using MQTT

## Getting started

---
Prerequisites:
- PlatformIO set up in VSCode
- Home Assistant and MQTT broker accessible on the WiFi network your Pico W is joining (see appendix below for guidance on setup)
- HA MQTT integration with discovery enabled (this is the default/recommended behavior, so unless you turned it off, you're probably good to go).
---

1. Hold the `BOOTSEL` button on your Pico W while connecting it via USB
2. Open this project in VSCode
3. Edit `src/Credentials.h` with:
```
  - WiFi SSID
  - WiFi Password
  - MQTT Username
  - MQTT Password
  - MQTT Broker IP
```
4. Select the PlatformIO sidebar tab and choose Project Tasks > Upload and Monitor
5. Once the project logs a connection to the MQTT broker, open your Home Assistant instance
6. From Settings > Devices and Services, find the MQTT card and click the link that says `X devices`
7. From the resulting list, select `Pico W HA Starter`
8. Under the **Controls** heading you should see `Board LED`. Toggle the switch to turn your green board LED on and off

That's it. Now you've got a working example integration of all the pieces needed to communicate between an inexpensive, high-quality microcontroller and Home Assistant, all happening on your local network.

See the [examples in `arduino-home-assistant`](https://github.com/dawidchyrzynski/arduino-home-assistant/tree/main/examples) for additional components you can easily integrate, including sensors, buttons, even HVAC controls.

# Appendix: Setting up a local Home Assistant installation with Mosquitto

