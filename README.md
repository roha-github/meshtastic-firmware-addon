# Meshtastic Firmware - Addon (Fork)

This is a fork of the Meshtastic firmware to provide additional features

* "Zero Hop Repeater" ~ unlimited repeater chain
* "Power Timer Switch" ~ predefined shutdown and resume

These features will not be included in the official Meshtastic firmware.

## Configuration hooks

We use "special" values to configure the add-ons and reuse default App and CLI.

### Zero Hop Repeater

```
config.device.node_info_broadcast_secs      = 3601    # 1 enabled | 0 disable zero hops
config.device.role                          = REPEATER | ROUTER | ROUTER_CLIENT
```

### Power Timer Switch

```
config.power.on_battery_shutdown_after_secs = 1783    # timer switch enabled    (cfg % 10 == 1..3 enabled >= 80% on)
config.power.sds_secs                       = 86405   # 5min per hour           (cfg % 100 == 5)
config.power.ls_secs                        = 86328   # 15min=5+2x5 every 8hour (cfg % 100 - % 10)

additional settings:
device.role = ROUTER_CLIENT
device.serial_output = enabled
device.rebroadcast = LOCAL_ONLY
device.nodeinfo = 10800
position.smart_position = disabled
position.gps_mode = NOT_PRESENT
display.screen_timeout = 1
lora.region = EU_868
lora.hop_limit = 7
lora.mqtt = ignore
bluetooth = enabled (!!!)
bluetooth.pairing = FIXED_PIN
telemetry.device_metrics = 900

Without BLE restart sometimes not work.
```

## Installation firmware

The installation requires the esptool, the installer of the original firmware and the binary of the modified firmware.

* Install esptool to upload new firmware
* Download the original Meshtastic firmware installer
* Download extended Meshtastic firmware binary 

The newest binary you can download from [meshtastic-firmware-addon/tree/master/.pio/build](https://github.com/roha-github/meshtastic-firmware-addon/tree/master/.pio/build) or compile to your target hardware.



## Zero Hop Repeater

**Extend range:**

* towards: sender(3) > repeater_a(3) > repeater_b(3) > hop_a(3) > hop_b(2) > hop_c(1) > receiver(0)
* backwards: sender(0) < repeater_a(1) < repeater_b(1) < hop_a(1) < hop_b(2) < hop_c(3) < receiver(3)
* useful for repeater chain in remote locations or caves - 3 hops are not enough to reach the mesh

The number of hops is limited to 3 by default. If a remote location already requires 3 hops to reach the first foreign node, then there are no hops left for responses from foreign nodes, unless everyone in the mesh would increase the hop limit.

Meshtastic only forwards messages from nodes if the message ID for this node has not been forwarded within the last 10 minutes.

## Power Timer Switch

**Reduce current consumption:**

* always switched on when battery fully charged (solar panel in sunny weather)
* power-on few minutes every hour (e.g. 5 minutes per hour)
* power-on more minutes at longer intervals (e.g. 15 minutes every 6 hours)

The objective is to be able to operate a router for several days even with very small solar panels and batteries.

![Monitoring-Power-Timer-Switch](/.pio/build/thingspeak-monitoring-power-timer-switch.png)

### Configuration

This feature uses the power configuration:

* shutdown on battery low ~ xxxxPx (percent) / xxxxM (saving prefs 1..3)
* shutdown deep sleep ~ xxxxUP (minutes) uptime every hour
* shutdown light sleep ~ xxxLx (long) / xxxxI (interval)

| device | consumtion | current | hourly | interval hour | always-on | bat shutdown | deep sleep | light sleep |
|---|---|---|---|---|---|---|---|---|
| TLORA_2_1_1P6 | 11.1% | 72mAh/d | 5min | 15min (6hours) | >90% | 1793s | 86405s | 86326s |
| TLORA_2_1_1P6 | 16.6% | 108mAh/d | 8min | 16min (4hours) | >80% | 1783s | 86408s | 86314s |
| HELTEC_V2_1 | 11.1% | 83mAh/d | 5min | 15min (6hours) | >90% | 1793s | 86405s | 86326s |
| HELTEC_V2_1 | 16.6% | 124mAh/d | 8min | 16min (4hours) | >80% | 1783s | 86408s | 86314s |

*) current as ROUTER with 10% TX at 20dBm

#### Alway-on (percentage)

The node stays switched on when the battery is charged to over X0 percent. This option is intended for the node to be operated with a solar panel. The node remains permanently active on sunny days and the power-saving mode is activated on shady days.

#### Saving Mode (last digit)

This option can be used to prevent the configuration from being saved to the flash every time the device is shut down. 

* 0 ~ Power Timer Switch disabled
* 1 ~ Power Timer Switch enabled / save prefs disabled
* 2 ~ Power Timer Switch enabled / save prefs enabled - every hour
* 3 ~ Power Timer Switch enabled / save prefs enabled - every long interval

#### Uptime per hour (last two digits)

This option controls how many minutes the node is switched on per hour. It is always switched on on the hour if the node has received the time from another node or via GPS. Several time-controlled nodes synchronize via the time and expand the mesh network. Over time, human observers will notice that certain routers are online for a few minutes every hour. They can then adjust their communication accordingly.

#### Longer uptime (second last digit)

It is recommended to switch on the node for 15 minutes every few hours. The regular interval for position with time is 15 minutes. Even without GPS, the node receives the time from other nodes and can therefore regularly align itself with the time. 

The number is a multiplier for a supplement to the regular uptime. If the uptime is 5 minutes and the multiplier is 2, this results in a longer uptime of 15 minutes.

#### Longer uptime interval (last digit)

An interval can be defined in which the node remains switched on for a longer uptime. 

* 0 = interval deactivated
* 2..8 = interval of 2 .. 8 hours (12x ... 3x a day)

### Timer variant

* 220mA × 15s boot
* 120mA × 5s TX nodeinfo to mesh
* 60mA × 40s RX read from mesh
* avg: 105mA for 60 seconds (boot)
* avg: 25mA standby ESP32 (10% TX, 20dBm)

| long | short | pause | mAh/d |
|---|---|---|---|
| 120m | 5m | 115m | 89mAh |
| 60m | 5m | 55m | 105mAh |
| 30m | 5m | 25m | 175mAh |
| 20m | 5m | 15m | 253mAh |

By default nodes send time inside position frame every 900 seconds. Once a day a timer switch node should listen for minimum 15 minutes to get time from other nodes.

## Released

* gateway / zero hop repeater [#3437](https://github.com/meshtastic/firmware/issues/3437)

## Todos

* ~~re-init RTC after resume~~
* long uptime without RTC every 24h
* buffer sensor data at RTC
* buffer chat data at RTC
* upload telemetry to thinkspeak
* upload sensor to thinkspeak
* interactive chatbot

## Ideas

* select battery type [#3910](https://github.com/meshtastic/firmware/issues/3910)
* custom wifi power [#2267](https://github.com/meshtastic/firmware/issues/2267)
* turn off wifi by voltage level [#2259](https://github.com/meshtastic/firmware/issues/2259)
* customize boot screen [#3362](https://github.com/meshtastic/firmware/issues/3362)
* customize message screen [#2427](https://github.com/meshtastic/firmware/issues/2427)
* upload to Thingspeak [#3626](https://github.com/meshtastic/firmware/issues/3626)
* changeable MAC address (node id)
* use internal RTC temperature sensor [#3883](https://github.com/meshtastic/firmware/issues/3883)
* ~~virtual waypoint (fake position), existing feature~~
* message store to flash [#3664](https://github.com/meshtastic/firmware/issues/3664), [#3637](https://github.com/meshtastic/firmware/issues/3637)
* lorawan gateway for sensors [#3838](https://github.com/meshtastic/firmware/issues/3838)
* variables for canned message (e.g. $rssi, $snr, $lat, $lon)
* custom duty cycle [#2288](https://github.com/meshtastic/firmware/issues/2288)
* use public wifi and auto join
* auto confirm public wifi conditions
* inverval pax counter with deep sleep [#d12648](https://meshtastic.discourse.group/t/paxcounter-high-potential-modul-android/12648/4)
* pax counter radius (rssi minimum) [#3885](https://github.com/meshtastic/firmware/issues/3885)
* one button control e.g. for canned messages
* Heltec Wireless Stick OLED-display [#3714](https://github.com/meshtastic/firmware/discussions/3714)
* adjust hops to own limit [#3833](https://github.com/meshtastic/firmware/discussions/3833)
* remove old nodes from nodedb
* determine and mark direct neighbors by retransmit own messages
* binary (image) file transfer
* act ESP32 as wifi access point [#1308](https://github.com/meshtastic/firmware/issues/1308)
* bboard [#](https://discord.com/channels/867578229534359593/1202799870415605790)
* lora update over the air
* automatic reboot [#3982](https://github.com/meshtastic/firmware/issues/3982)
* remote messaging via lora (like remote admin)
* different hop limit for low prio portnum (e.g. telemetry)

### binary transfer

* limit filesize = limit part id 6bit
* 253 byte × 64 parts ~ 16 kb
* max 8 parts / minute ~ 8 min / 16 kb

### magic values

* network
  * [ntp server](https://github.com/meshtastic/firmware/blob/34aec70998382a66ea0d61bb9b5b585885aad32d/src/mesh/wifi/WiFiAPClient.cpp#L37) [32] = server#{string}
  * [rsyslog server](https://github.com/meshtastic/firmware/blob/34aec70998382a66ea0d61bb9b5b585885aad32d/src/mesh/wifi/WiFiAPClient.cpp#L83) [32] = server#{string}
* range test
  * [message interval](https://github.com/meshtastic/firmware/blob/34aec70998382a66ea0d61bb9b5b585885aad32d/src/modules/RangeTestModule.cpp#L59) = sec{number}
* canned
  * [messages](https://github.com/meshtastic/firmware/blob/34aec70998382a66ea0d61bb9b5b585885aad32d/src/mesh/generated/meshtastic/cannedmessages.pb.h#L16) [200] = {string}

### Remote OTA update over Lora (draft)

The OTA update via Lora is only intended for nodes that are extremely difficult to access, where a wireless update via Bluetooth is not possible.

An update via Lora is only possible if the old firmware release already contains the extension for the update via Lora.

To update a Node-A, a second Node-B is required as a source. It is recommended to connect both nodes directly and without hops. In addition, the Short/Fast configuration with 10.94 kbps should be used for the update.

The OTA update via Lora extends the update via BLE. The chunks are received via Lora instead of Bluetooth. The new firmware release is retrieved by Node-A from Node-B.

The Admin Channel is used to initiate the retrieval of the new firmware. The address of Node-B is configured as a message for Node-A in the Canned module. Node-A then sends direct messages to Node-B to retrieve the chunks and Node-B responds with the parts of the new firmware binary.

[Partitioning](https://github.com/meshtastic/firmware/blob/2f9dc813d3c64b738777bfdba1efc9a4697f7ac2/bin/genpartitions.py#L4) / [doc](https://docs.espressif.com/projects/arduino-esp32/en/latest/tutorials/partition_table.html)

```
# This is a layout for 4MB of flash
# Name,   Type, SubType, Offset,  Size, Flags
# nvs,      data, nvs,         0x9000 (36kb),  0x6000, (24kb)
# otadata,  data, ota,     ,   0x2000 (8kb),
# app0,     app,  ota_0,   , 0x1c0000 (1792kb),
# app1,     app,  ota_1,   , 0x1c0000 (1792kb),
# spiffs,   data, spiffs,  , 0x06f000 (444kb),
```

1) update firmware
2) update files
3) update setup
