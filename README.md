<!---[![License: MIT](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/justcallmekoko/ESP32Marauder/blob/master/LICENSE)--->
<!---[![Gitter](https://badges.gitter.im/justcallmekoko/ESP32Marauder.png)](https://gitter.im/justcallmekoko/ESP32Marauder)--->
<!---[![Build Status](https://travis-ci.com/justcallmekoko/ESP32Marauder.svg?branch=master)](https://travis-ci.com/justcallmekoko/ESP32Marauder)--->
<!---Shields/Badges https://shields.io/--->

# Marauder Centauri v0.1
<p align="center"><img alt="Marauder logo" src="https://github.com/justcallmekoko/ESP32Marauder/blob/master/pictures/marauder3L.jpg?raw=true" width="300"></p>
<p align="center">
  <b>A suite of WiFi/Bluetooth offensive and defensive tools for the ESP32</b>
  <br><br>
  <a href="https://github.com/justcallmekoko/MarauderCentauri/blob/master/LICENSE"><img alt="License" src="https://img.shields.io/github/license/mashape/apistatus.svg"></a>
  <a href="https://gitter.im/justcallmekoko/ESP32Marauder"><img alt="Gitter" src="https://badges.gitter.im/justcallmekoko/ESP32Marauder.png"/></a>
  <a href="https://github.com/justcallmekoko/MarauderCentauri/releases/latest"><img src="https://img.shields.io/github/downloads/justcallmekoko/MarauderCentauri/total" alt="Downloads"/></a>
  <br>
  <a href="https://twitter.com/intent/follow?screen_name=jcmkyoutube"><img src="https://img.shields.io/twitter/follow/jcmkyoutube?style=social&logo=twitter" alt="Twitter"></a>
  <a href="https://www.instagram.com/just.call.me.koko"><img src="https://img.shields.io/badge/Follow%20Me-Instagram-orange" alt="Instagram"/></a>
  <br><br>
  <a href="https://www.tindie.com/products/justcallmekoko/esp32-marauder/"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-larges.png" alt="I sell on Tindie" width="200" height="104"></a>
</p>

[![HitCount](http://hits.dwyl.io/justcallmekoko/badges.svg)](http://hits.dwyl.io/justcallmekoko/badges)
[![Build Status](https://travis-ci.com/justcallmekoko/ESP32Marauder.svg?branch=master)](https://travis-ci.com/justcallmekoko/ESP32Marauder)

# Table Of Condensation
- [About](#about)
  - [YouTube](#youtube)
  - [Hackster Article](#hackster-article)
  - [Capabilities](#capabilities)
- [Flashing Firmware](#flashing-firmware)
  - [Using Arduino IDE](#using-arduino-ide)
- [Updating Firmware](#updating-firmware)
  - [Web Update](#web-update)
  - [SD Update](#sd-update)
- [Under Development](#under-development)
- [Special Thanks](#special-thanks)
- [For Sale Now](#for-sale-now)

# About
Sometimes you just gotta do what you gotta do. Am I right, ladies?
The ESP32 Marauder is a suite of WiFi/Bluetooth offensive and defensive tools created for the ESP32 and was originally inspired by [Spacehuhn's](https://github.com/Spacehuhn) [esp8266_deauther](https://github.com/Spacehuhn/esp8366_deauther) project. The tool itself serves as a portable device used to test and analyze WiFi and Bluetooth devices. Use this tool and its firmware with caution as the use of some of its capabilities without explicit consent from the target owner is unlawful in most countries. For more information about this project and how it's assembled, follow the video link below. Track features and issues [here](https://github.com/justcallmekoko/MarauderCentauri/issues). Check out [#esp32marauder](https://www.instagram.com/explore/tags/esp32marauder/) on Instagram.  
**Note:** Because of espressif's ESP32-IDF, the ESP32 included with Marauder is incapable of transmitting deauthentication frames.

### YouTube
<p align="left"><a href="https://www.youtube.com/watch?v=BGFO1wA29o8"><img alt="Marauder logo" src="https://github.com/justcallmekoko/MarauderCentauri/blob/master/pictures/esp32marauder_thumbnail.jpg" width="500"></a></p>

### Hackster Article
You can check out the marauder article written [here](https://www.hackster.io/news/esp32-marauder-puts-a-bluetooth-wi-fi-pen-testing-toolkit-in-your-pocket-32d389f6e66f) as well as other interesting engineering projects.

## Capabilities
### Current
- Join WiFi: Just join a WiFi network
- Shutdown WiFi: Shutdown the Marauder WiFi interface to save some RAM
- Generate SSIDs: Add 20 random SSIDs to your list of SSIDs
- Add SSID: Use an on-screen keyboard to add your own SSIDs to the SSID list
- Clear SSIDs: Clear the list of SSIDs
- Probe Request Sniff: Sniff for WiFi [probe request frames](https://mrncciew.com/2014/10/27/cwap-802-11-probe-requestresponse/) sent by wireless devices
- Beacon Sniff: Sniff [beacon frames](https://en.wikipedia.org/wiki/Beacon_frame) sent by wireless acccess points
- Beacon Spam List: Spam a list of SSIDs and monitoring connection attempts to those networks
- Beacon Spam Random: Spam hundreds of random beacon frames to wireless devices within range
- Rick Roll Beacon: Broadcast the rick roll lyrics as WiFi access points
- Bluetooth Sniffer: Sniff bluetooth devices within range
- Shutdown BLE: Shutdown the Marauder BLE interface to save RAM
- Detect Card Skimmers: Detect bluetooth enabled credit card skimmers
- Packet Monitor: Show WiFi packet density on a given channel using a time bar graph
- EAPOL/PMKID Scan: Capture EAPOL/PMKID frames
- Detect Pwnagotchi: Detect any pwnagotchis in range
- Detect Espressif: Detect any espressif devices in range
- Deauth Sniff: Detect deauthentication packets sent on all channels
- Draw: Just doodle on the screen or whatever
- Update Firmware: Update Marauder firmware over the air via web interface or with SD card
- Save PCAP files to SD card

# Flashing Firmware
## Using Arduino IDE
1. Install the [Arduino IDE](https://www.arduino.cc/en/main/software)
2. In the Arduino IDE, go to `File`>`Preferences`
3. Add the following URL to `Additional Boards Manager URLs:`
    - https://dl.espressif.com/dl/package_esp32_index.json
4. Go to `Tools`>`Board`>`Boards Manager`, search for `esp32` and install `esp32 by Espressif Systems`
5. Install Spacehuhn's [SimpleList](https://github.com/spacehuhn/SimpleList) library in your Arduino IDE
    - Download the SimpleList repo
    - In the Arduino IDE, go to `Sketch`>`Include Library`>`Add .ZIP Library...` and add the SimpleList-master.zip you just downloaded
<!---6. Install Bodmer's [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI) library in your Arduino IDE--->
6. Install my fork of Bodmer's [TFT_eSPI](https://github.com/justcallmekoko/TFT_eSPI) library in your Arduino IDE
    - Download the TFT_eSPI repo
    - In the Arduino IDE, go to `Sketch`>`Include Library`>`Add .ZIP Library...` and add the TFT-eSPI-master.zip you just downloaded
    - Make the following modifications shown in [this issue](https://github.com/justcallmekoko/MarauderCentauri/issues/2#issuecomment-555695918) to the TFT_eSPI library you just installed
7. Follow [these instructions](https://github.com/me-no-dev/arduino-esp32fs-plugin) for installing ESP32 Spiffs Tool
8. Install the [CH340 Drivers](https://github.com/justcallmekoko/MarauderCentauri/blob/master/Drivers/CH34x_Install_Windows_v3_4.EXE)
9. Download or clone this repository
10. Open `esp32_marauder.ino`
10.5. If you're using the analog battery measuring circuit, go to the MenuFunctions.h and change "#define BATTERY_ANALOG_ON" to 1
11. Plug your ESP32 into a USB port and select the COM port under `Tools`>`Port`
12. Select `LOLIN D32` under `Tools`>`Boards`
12.5 If you want an upscaled version of the logo, go to the data folder and rename "marauder3L1.jpg" to "marauder3L.jpg"
13. Click `ESP32 Sketch Data Upload` and wait for the SPIFFS upload to finish
14. Click the upload button

<p align="center">
  <img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/m5stack.jpg?raw=true" height="300">
  <img alt="Marauder logo" src="https://github.com/justcallmekoko/ESP32Marauder/blob/master/pictures/odroid_marauder.jpg?raw=true" height="300">
</p>

# Updating Firmware
There are multiple options available to update the Marauder firmware. If you have already built the project from this repo, you can just pull the latest commit and flash the firmware using the Arduino IDE (see [here](#using-arduino-ide)).  
If you own an ESP32 Marauder (v0.4.0 or later) and have not build the project, you can follow [these instructions](#web-update) for installing the latest update over the air via Marauder's web interface or [these instructions](#sd-update) for installing the latest update using an SD Card.  

## Web Update
1. Download the [latest release](https://github.com/justcallmekoko/MarauderCentauri/releases/latest) of the Marauder firmware
2. With Marauder powered on, navigate to `Device`>`Update Firmware`>`Web Update`
    - Marauder will display details on screen about the status of the update
3. Connect to the MarauderOTA WiFi network from your computer
    - password: justcallmekoko
4. On your web browser, navigate to `http://192.168.4.1`
5. Enter the username and password
    - Username: admin
    - Password: admin
6. Click the `Browse` button and select the .bin file you downloaded from the releases
7. Click `Update`
    - Marauder will automatically reboot once the update has been applied
    
## SD Update
*Using a Samsung MicroSD card will cause Marauder not to boot*
1. Download the [latest release](https://github.com/justcallmekoko/MarauderCentauri/releases/latest) of the Marauder firmware
2. Copy the bin file you downloaded to the root of an SD card
3. Rename the bin file on the SD card to `update.bin`
4. With Marauder powered off, insert the SD card into Marauder
5. Power Marauder on and navigate to `Device`>`Update Firmware`>`SD Update`
6. Click `Yes` to confirm the update
    - Marauder will automatically reboot once the update has been applied
    
# Icons
I put these here just because  
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/attack_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/beacon_sniff_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/beacon_spam_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/bluetooth_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/bluetooth_sniff_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/deauth_sniff_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/device_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/device_info_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/draw_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/eapol_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/espressif_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/general_apps_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/monitor_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/probe_sniff_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/pwnagotchi_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/reboot_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/rick_roll_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/scan_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/sd_update_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/skimmer_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/sniff_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/update_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/web_update_22.bmp">
<img alt="Marauder logo" src="https://raw.githubusercontent.com/justcallmekoko/ESP32Marauder/master/pictures/icons/wifi_22.bmp">
  
# Under Development
Currently the ESP32 Marauder has limited firmware capabilities. Most of the work so far has been put into designing the hardware. New firmware features will be added over time and will eventually reach a point where this project will be a fully capable hacking machine.

# Special Thanks
- [Spacehuhn](https://github.com/spacehuhn) for an easy to use linked list library [SimpleList](https://github.com/spacehuhn/SimpleList)
  - Also a well designed menu structure. I adapted it to the TFT GUI because it worked perfectly
  - Also...providing the buffer class used to save pcap files to an SD card
- [Ivanseidel](https://github.com/ivanseidel) for providing a thread safe [LinkedList](https://github.com/ivanseidel/LinkedList) library
- [Bodmer](https://github.com/Bodmer) for a comprehensive TFT touch screen library [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)
- [HyderHasnain](https://github.com/hyderhasnain) for an adaptable [line graph](https://github.com/hyderhasnain/arduino_touchscreen_controller/blob/master/Code/AccelGraph_Original.ino) to be used as the packet monitor

# For Sale Now
You can buy the ESP32 Marauder using [this link](https://www.tindie.com/products/justcallmekoko/esp32-marauder/)
