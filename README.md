# Raspberry Pi Pico W Home Assistant Starter Project

This is a [PlatformIO](https://platformio.org) project that instantly integrates a Raspberry Pi Pico W into Home Assistant via MQTT.

Fill out `src/Credentials.h`, upload to your Pico W, then you've got a working integration allowing you to toggle the Pico W's board LED from the Home Assistant dashboard. From this starter you'll have a strong foundation to build a custom device for a private Intranet of Things.

This readme will provide pointers to everything needed to get started.

## Dependencies:

- [Raspberry Pi Pico W](https://www.raspberrypi.com/products/raspberry-pi-pico/?variant=raspberry-pi-pico-w), a $6 microcontroller board with WiFi
- [PlatformIO](https://platformio.org/platformio-ide), an extension for VSCode with the most robust and reliable Arduino developer experience
- [`arduino-pico`](https://github.com/earlephilhower/arduino-pico): a community-developed Arduino core for Pico/Pico W with constant updates and excellent support for existing Arduino code
- [`arduino-home-assistant`](https://github.com/dawidchyrzynski/arduino-home-assistant): a thorough Arduino/Home Assistant integration using MQTT

# Appendix A: Setting up a local Home Assistant installation with Mosquitto
