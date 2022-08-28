# Raspberry Pi Pico W/Arduino/Home Assistant Starter Project

I'm pretty excited about Pico W: it's such a reliable, high-quality board and each one costs just $6 (if you can find one).

I'm building an IoT project with Pico W and Home Assistant, and it took weeks of research and experimentation to figure out the basics of integration of all the necessary components. This starter pulls together everything I've learned so you can get to building quickly.

Fill out `src/Credentials.h`, upload to your Pico W, then you'll have a working integration that allows you to toggle the Pico W's board LED from the Home Assistant dashboard. From this starter you'll have a solid foundation to build your own custom device in a private, local Intranet of Things.

This readme will provide pointers to everything you'll need. Let me know if it's missing anything!

## Dependencies

- [Raspberry Pi Pico W](https://www.raspberrypi.com/products/raspberry-pi-pico/?variant=raspberry-pi-pico-w), a $6 microcontroller board with WiFi
- [PlatformIO](https://platformio.org/platformio-ide), an extension for [VSCode](https://code.visualstudio.com) with the most robust and reliable Arduino developer experience
- [`arduino-pico`](https://github.com/earlephilhower/arduino-pico): a community-developed Arduino core for Pico/Pico W with constant updates and excellent support for existing Arduino code
- [`arduino-home-assistant`](https://github.com/dawidchyrzynski/arduino-home-assistant): a thorough Arduino/Home Assistant integration using MQTT

## Getting started

---
### Prerequisites
- PlatformIO set up in VSCode
- Home Assistant and MQTT broker accessible on the WiFi network your Pico W is joining (see appendix below for guidance on setup)
- HA MQTT integration with discovery enabled (this is the default/recommended behavior, so unless you turned it off, you're probably good to go)
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

<img width="686" alt="Screen Shot 2022-08-27 at 11 53 32 PM" src="https://user-images.githubusercontent.com/213358/187056599-dadeb7d2-89e4-49dd-98a9-9dda8815b6a9.png">

That's it. Now you've got a working example integration of all the pieces needed to communicate between an inexpensive, high-quality microcontroller and Home Assistant, all happening on your local network.

See the [examples in `arduino-home-assistant`](https://github.com/dawidchyrzynski/arduino-home-assistant/tree/main/examples) for additional components you can easily integrate, including sensors, buttons, even HVAC controls.

# Troubleshooting

- To come

# Appendix: Setting up a local Home Assistant installation with Mosquitto

## Home Assistant install

Home Assistant can be [installed](https://www.home-assistant.io/installation/) several ways on all kinds of hardware. Raspberry Pi is a popular choice, but you can also use your existing computer for initial explorations. *Home Assistant Container* is probably the quickest and most portable way to get started, whichever hardware you're using, though this does mean you'll have to manage some add-ons yourself, including MQTT.

## MQTT and Mosquitto

MQTT provides realtime messaging between devices in a network. The [Eclipse Mosquitto](https://github.com/eclipse/mosquitto) project offers a server that can act as an _MQTT broker_, a central hub for MQTT devices to send and receive data.

If you're using **Home Assistant Operating System**, check these instructions to [install the Mosquitto MQTT broker add-on](https://github.com/home-assistant/addons/blob/master/mosquitto/DOCS.md).

If you're using **Home Assistant Container**, [this tutorial](https://hometechhacker.com/mqtt-home-assistant-using-docker-eclipse-mosquitto/) provides a great overview on how to set up and secure Mosquitto in a seperate container.

Once your MQTT broker is enabled, [add the MQTT integration to your Home Assistant instance](https://www.home-assistant.io/integrations/mqtt/).

# Pull requests

PRs are welcome on these points:

- Enhance documentation (especially any troubleshooting steps you found helpful)
- Refine project structure
- Additional code paths to accommodate common variations (unsecured MQTT broker, different WiFi authentication, etc)
- Fix my bad C++

The goal of the project is to provide enough example structure to allow developers to add complexity without making a messy, crowded `main.cpp` file. PRs that simplify down to a single file probably won't be merged. If you have ideas on how to make this an even better foundation for building complex IoT projects, I'm all ears.

---

Questions? Comments? Gripes? Open an [issue](https://github.com/daniloc/PicoW_HomeAssistant_Starter/issues/new/choose) if you think there will be general interest or impact on the project. Otherwise hit me up: [mail@danilocampos.com](mailto:mail@danilocampos.com).
