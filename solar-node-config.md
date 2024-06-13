# Solar Node Config

My setting for minimum power consumption. What is not specified remains in the default settings.

| Device | Deep Sleep | Light Sleep | MCU on | use case |
|---|---|---|---|---|
| Heltec WSL V3 | 50 uA | 10,9 mA | 109 mA | solar gateway, disposable battery sensor |
| Heltec V2.1 | 3,9 mA | 18 mA | 60 mA | mobile gateway with solar to extend the runtime |
| T-LoRa V2.1-1.6 | 1,9 mA | 12,7 mA | 60 mA | mobile gateway with solar to extend the runtime |

Heltec Wireless Stick is suitable for solar nodes for sensors or for small mesh networks without much rebroadcast.

## Channels

* 0: LongFast
* 1: admin ~ configuring using the app and a second node

## Device

* Role: CLIENT ~ rebroadcast later or not
* Serial output enabled: FALSE ~ ESP32 may Light Sleep
* Rebroadcast: LOCAL_ONLY ~ forward less
* Disable LED ~ less power consumption

## Position

* Broadcast interval: 1200 ~ every 20 minutes
* Smart position enabled: FALSE

## Power

* Enable power saving: TRUE ~ use light sleep
* Shutdown on battery delay; 924 ~ >20% always on >10% interval
* Wait for Bluetooth: 25 ~ after 25 seconds in light sleep
* Super deep sleep: 43205 ~ 5 minutes interval on battery <20%, 12 hours deep sleep on battery <10%
* Light sleep: 228 ~ 15 minutes long interval and safe every 8 hours, 228 seconds light sleep

standard firmware (without fork):

* Enable power saving: TRUE ~ use light sleep
* Shutdown on battery delay; 0 ~ avoid deep sleep on battery charge detection issue
* Wait for Bluetooth: 25 ~ after 25 seconds in light sleep
* Super deep sleep: 43200 ~ 12 hours deep sleep on battery <10%
* Light sleep: 300 ~ 300 seconds light sleep


### Display

* Screen timeout: 1 ~ switch off directly

## LoRa

* Ignore MQTT: TRUE ~ forward less

## Bluetooth

* Bluetooth enabled: TRUE ~ optional use as client when switching on
* Pairing: FIXED_PIN ~ use Bluetooth when display is off
