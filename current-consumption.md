# Current Consumption

## Heltec Wireless Stick V3

| ID | Firmware | Power | Role | Serial | ReBro | GPS | PSave | SBat | ADC | WBlu | DeS | LiS | MiW | Dis | TX | MQTT | BLE | boot | time | down |
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
| 1 | 2.3.4.xxxd | bat | Client | dis | local | not | dis | 80 | 0 | 60 | 86405 | 328 | 10 | 1 | 19 | ign | fix | 99,5mA | 1:26 | 2,1mA |
| 1 | 2.3.4.xxxd | usb | Client | dis | local | not | dis | 80 | 0 | 60 | 86405 | 328 | 10 | 1 | 19 | ign | fix | 104mA | 1:26 | 12mA |
| 2 | 2.3.4.xxxd | usb | Client | log | local | not | dis | 80 | 0 | 60 | 86405 | 328 | 10 | 1 | 19 | ign | fix | 104mA | 1:26 | 12mA |

* PSave: power saving mode
* SBat: shutdown on battery
* WBlu: wait bluetooth
* DeS: super deep sleep (shutdown)
* LiS: light sleep
* MiW: minimum wakeup
* Dis: display
* TX: lora tx power

Log Setup 1 - Client: serial debug disabled
```
ESP-ROM:esp32s3-20210327
Build:Mar 27 2021
rst:0x1 (POWERON),boot:0x8 (SPI_FAST_FLASH_BOOT)
SPIWP:0xee
mode:DIO, clock div:1
load:0x3fce3808,len:0x44c
load:0x403c9700,len:0xbe4
load:0x403cc700,len:0x2a38
entry 0x403c98d4
E (340) esp_core_dump_flash: No core dump partition found!
E (340) esp_core_dump_flash: No core dump partition found!
▒▒@INFO  | ??:??:?? 0

//\ E S H T /\ S T / C

INFO  | ??:??:?? 0 Booted, wake cause 0 (boot count 1), reset_reason=reset
DEBUG | ??:??:?? 0 Filesystem files (495616/1048576 Bytes):
DEBUG | ??:??:?? 0  /prefs/channels.proto (100 Bytes)
DEBUG | ??:??:?? 0  /prefs/config.proto (89 Bytes)
DEBUG | ??:??:?? 0  /prefs/db.proto (782 Bytes)
DEBUG | ??:??:?? 0  /prefs/module.proto (103 Bytes)
DEBUG | ??:??:?? 0  /static/.gitkeep (0 Bytes)
DEBUG | ??:??:?? 0  /static/Logo_Black.svg.gz (602 Bytes)
DEBUG | ??:??:?? 0  /static/Logo_White.svg.gz (610 Bytes)
DEBUG | ??:??:?? 0  /static/apple-touch-icon.png.gz (3164 Bytes)
DEBUG | ??:??:?? 0  /static/favicon.ico.gz (2270 Bytes)
DEBUG | ??:??:?? 0  /static/icon.svg.gz (852 Bytes)
DEBUG | ??:??:?? 0  /static/index-BMhLjTmL.css.gz (16270 Bytes)
DEBUG | ??:??:?? 0  /static/index-Bt2MYVVB.js.gz (203021 Bytes)
DEBUG | ??:??:?? 0  /static/index-CGqDWSD_.js.gz (348 Bytes)
DEBUG | ??:??:?? 0  /static/index.html.gz (548 Bytes)
DEBUG | ??:??:?? 0  /static/maplibre-gl-BXZZhNda.js.gz (210451 Bytes)
DEBUG | ??:??:?? 0  /static/robots.txt.gz (42 Bytes)
DEBUG | ??:??:?? 0  /static/site.webmanifest.gz (197 Bytes)
[   694][I][esp32-hal-i2c.c:75] i2cInit(): Initialising I2C Master: sda=41 scl=42 freq=100000
DEBUG | ??:??:?? 0 Using analog input 1 for battery level
INFO  | ??:??:?? 0 ADCmod: ADC Characterization based on Two Point values and fitting curve coefficients stored in eFuse
INFO  | ??:??:?? 0 Scanning for i2c devices...
[   720][W][Wire.cpp:301] begin(): Bus already started in Master Mode.
DEBUG | ??:??:?? 0 Scanning for i2c devices on port 1
INFO  | ??:??:?? 0 No I2C devices found
DEBUG | ??:??:?? 0 acc_info = 0
INFO  | ??:??:?? 0 Meshtastic hwvendor=44, swver=2.3.4
DEBUG | ??:??:?? 0 Setting random seed 2164040025
DEBUG | ??:??:?? 0 Total heap: 295520
DEBUG | ??:??:?? 0 Free heap: 260348
DEBUG | ??:??:?? 0 Total PSRAM: 0
DEBUG | ??:??:?? 0 Free PSRAM: 0
DEBUG | ??:??:?? 0 NVS: UsedEntries 99, FreeEntries 531, AllEntries 630, NameSpaces 3
DEBUG | ??:??:?? 0 Setup Preferences in Flash Storage
DEBUG | ??:??:?? 0 Number of Device Reboots: 105
ESP_ERROR_CHECK_WITHOUT_ABORT failed: esp_err_t 0x105 (ESP_ERR_NOT_FOUND) at 0x40380cc3
file: "src/platform/esp32/BleOta.cpp" line 16
func: static const esp_partition_t* BleOta::findEspOtaAppPartition()
expression: esp_ota_get_partition_description(part, &app_desc)
ESP_ERROR_CHECK_WITHOUT_ABORT failed: esp_err_t 0x102 (ESP_ERR_INVALID_ARG) at 0x40380cc3
file: "src/platform/esp32/BleOta.cpp" line 30
func: static String BleOta::getOtaAppVersion()
expression: esp_ota_get_partition_description(part, &app_desc)
DEBUG | ??:??:?? 0 No OTA firmware available
INFO  | ??:??:?? 0 Initializing NodeDB
INFO  | ??:??:?? 0 Loading /prefs/db.proto
INFO  | ??:??:?? 0 Loaded saved devicestate version 22, with nodecount: 6
INFO  | ??:??:?? 0 Loading /prefs/config.proto
[   923][E][vfs_api.cpp:105] open(): /littlefs/oem/oem.proto does not exist, no permits for creation
[  1124][D][esp32-hal-cpu.c:244] setCpuFrequencyMhz(): PLL: 480 / 6 = 80 Mhz, APB: 80000000 Hz
... 3 Seconds ... 104 mA

... 120 Seconds ... 129 mA

... 125 Seconds ... 12 mA
E (81116) RTCIO: rtc_gpio_isolate(171): RTCIO number error
E (81116) RTCIO: rtc_gpio_isolate(171): RTCIO number error
E (81117) RTCIO: rtc_gpio_isolate(171): RTCIO number error
```

Log 2 - Client: serial debug enabled
```
ESP-ROM:esp32s3-20210327
Build:Mar 27 2021
rst:0x1 (POWERON),boot:0x8 (SPI_FAST_FLASH_BOOT)
SPIWP:0xee
mode:DIO, clock div:1
load:0x3fce3808,len:0x44c
load:0x403c9700,len:0xbe4
load:0x403cc700,len:0x2a38
entry 0x403c98d4
E (340) esp_core_dump_flash: No core dump partition found!
E (340) esp_core_dump_flash: No core dump partition found!
▒▒@INFO  | ??:??:?? 0

//\ E S H T /\ S T / C

INFO  | ??:??:?? 0 Booted, wake cause 0 (boot count 1), reset_reason=reset
DEBUG | ??:??:?? 0 Filesystem files (495616/1048576 Bytes):
DEBUG | ??:??:?? 0  /prefs/channels.proto (100 Bytes)
DEBUG | ??:??:?? 0  /prefs/config.proto (91 Bytes)
DEBUG | ??:??:?? 0  /prefs/db.proto (777 Bytes)
DEBUG | ??:??:?? 0  /prefs/module.proto (103 Bytes)
DEBUG | ??:??:?? 0  /static/.gitkeep (0 Bytes)
DEBUG | ??:??:?? 0  /static/Logo_Black.svg.gz (602 Bytes)
DEBUG | ??:??:?? 0  /static/Logo_White.svg.gz (610 Bytes)
DEBUG | ??:??:?? 0  /static/apple-touch-icon.png.gz (3164 Bytes)
DEBUG | ??:??:?? 0  /static/favicon.ico.gz (2270 Bytes)
DEBUG | ??:??:?? 0  /static/icon.svg.gz (852 Bytes)
DEBUG | ??:??:?? 0  /static/index-BMhLjTmL.css.gz (16270 Bytes)
DEBUG | ??:??:?? 0  /static/index-Bt2MYVVB.js.gz (203021 Bytes)
DEBUG | ??:??:?? 0  /static/index-CGqDWSD_.js.gz (348 Bytes)
DEBUG | ??:??:?? 0  /static/index.html.gz (548 Bytes)
DEBUG | ??:??:?? 0  /static/maplibre-gl-BXZZhNda.js.gz (210451 Bytes)
DEBUG | ??:??:?? 0  /static/robots.txt.gz (42 Bytes)
DEBUG | ??:??:?? 0  /static/site.webmanifest.gz (197 Bytes)
[   744][I][esp32-hal-i2c.c:75] i2cInit(): Initialising I2C Master: sda=41 scl=42 freq=100000
DEBUG | ??:??:?? 0 Using analog input 1 for battery level
INFO  | ??:??:?? 0 ADCmod: ADC Characterization based on Two Point values and fitting curve coefficients stored in eFuse
INFO  | ??:??:?? 0 Scanning for i2c devices...
[   770][W][Wire.cpp:301] begin(): Bus already started in Master Mode.
DEBUG | ??:??:?? 0 Scanning for i2c devices on port 1
INFO  | ??:??:?? 0 No I2C devices found
DEBUG | ??:??:?? 0 acc_info = 0
INFO  | ??:??:?? 0 Meshtastic hwvendor=44, swver=2.3.4
DEBUG | ??:??:?? 0 Setting random seed 1057800193
DEBUG | ??:??:?? 0 Total heap: 295520
DEBUG | ??:??:?? 0 Free heap: 260348
DEBUG | ??:??:?? 0 Total PSRAM: 0
DEBUG | ??:??:?? 0 Free PSRAM: 0
DEBUG | ??:??:?? 0 NVS: UsedEntries 99, FreeEntries 531, AllEntries 630, NameSpaces 3
DEBUG | ??:??:?? 0 Setup Preferences in Flash Storage
DEBUG | ??:??:?? 0 Number of Device Reboots: 110
ESP_ERROR_CHECK_WITHOUT_ABORT failed: esp_err_t 0x105 (ESP_ERR_NOT_FOUND) at 0x40380cc3
file: "src/platform/esp32/BleOta.cpp" line 16
func: static const esp_partition_t* BleOta::findEspOtaAppPartition()
expression: esp_ota_get_partition_description(part, &app_desc)
ESP_ERROR_CHECK_WITHOUT_ABORT failed: esp_err_t 0x102 (ESP_ERR_INVALID_ARG) at 0x40380cc3
file: "src/platform/esp32/BleOta.cpp" line 30
func: static String BleOta::getOtaAppVersion()
expression: esp_ota_get_partition_description(part, &app_desc)
DEBUG | ??:??:?? 0 No OTA firmware available
INFO  | ??:??:?? 0 Initializing NodeDB
INFO  | ??:??:?? 0 Loading /prefs/db.proto
INFO  | ??:??:?? 0 Loaded saved devicestate version 22, with nodecount: 6
INFO  | ??:??:?? 0 Loading /prefs/config.proto
INFO  | ??:??:?? 0 Loaded saved config version 22
INFO  | ??:??:?? 0 Loading /prefs/module.proto
INFO  | ??:??:?? 0 Loaded saved moduleConfig version 22
INFO  | ??:??:?? 1 Loading /prefs/channels.proto
INFO  | ??:??:?? 1 Loaded saved channelFile version 22
[  1035][E][vfs_api.cpp:105] open(): /littlefs/oem/oem.proto does not exist, no permits for creation
INFO  | ??:??:?? 1 No /oem/oem.proto preferences found
DEBUG | ??:??:?? 1 cleanupMeshDB purged 0 entries
DEBUG | ??:??:?? 1 Using nodenum 0x336654bc
DEBUG | ??:??:?? 1 Number of Device Reboots: 110
DEBUG | ??:??:?? 1 Expanding short PSK #1
INFO  | ??:??:?? 1 Wanted region 3, using EU_868
INFO  | ??:??:?? 1 Saving /prefs/db.proto
DEBUG | ??:??:?? 1 Using GPIO00 for button
DEBUG | ??:??:?? 1 SPI.begin(SCK=9, MISO=11, MOSI=10, NSS=8)
DEBUG | ??:??:?? 1 Set Timezone to GMT0
DEBUG | ??:??:?? 1 Read RTC time as 0
DEBUG | ??:??:?? 1 NeighborInfoModule is disabled
INFO  | ??:??:?? 1 External Notification Module Disabled
DEBUG | ??:??:?? 1 SX126xInterface(cs=8, irq=14, rst=12, busy=13)
DEBUG | ??:??:?? 1 SX126X_DIO3_TCXO_VOLTAGE defined, using DIO3 as TCXO reference voltage at 1.800000 V
INFO  | ??:??:?? 1 Starting meshradio init...
DEBUG | ??:??:?? 1 (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=0, time 231 ms
DEBUG | ??:??:?? 1 (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=253, time 2115 ms
INFO  | ??:??:?? 1 Radio freq=869.525, config.lora.frequency_offset=0.000
INFO  | ??:??:?? 1 Set radio: region=EU_868, name=LongFast, config=0, ch=0, power=19
INFO  | ??:??:?? 1 Radio myRegion->freqStart -> myRegion->freqEnd: 869.400024 -> 869.650024 (0.250000 mhz)
INFO  | ??:??:?? 1 Radio myRegion->numChannels: 1 x 250.000kHz
INFO  | ??:??:?? 1 Radio channel_num: 1
INFO  | ??:??:?? 1 Radio frequency: 869.525024
INFO  | ??:??:?? 1 Slot time: 42 msec
INFO  | ??:??:?? 1 Set radio: final power level=19
INFO  | ??:??:?? 1 SX126x init result 0
INFO  | ??:??:?? 1 Frequency set to 869.525024
INFO  | ??:??:?? 1 Bandwidth set to 250.000000
INFO  | ??:??:?? 1 Power output set to 19
DEBUG | ??:??:?? 1 Current limit set to 140.000000
DEBUG | ??:??:?? 1 Current limit set result 0
DEBUG | ??:??:?? 1 Setting DIO2 as RF switch
DEBUG | ??:??:?? 1 SX126X_RXEN not defined, defaulting to RADIOLIB_NC
DEBUG | ??:??:?? 1 SX126X_TXEN not defined, defaulting to RADIOLIB_NC
DEBUG | ??:??:?? 1 Using MCU pin -1 as RXEN and pin -1 as TXEN to control RF switching
INFO  | ??:??:?? 1 Set RX gain to boosted mode; result: 0
INFO  | ??:??:?? 1 SX1262 Radio init succeeded, using SX1262 radio
INFO  | ??:??:?? 1 Not using WIFI
DEBUG | ??:??:?? 1 (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=237, time 2000 ms
DEBUG | ??:??:?? 1 LoRA bitrate = 118.500000 bytes / sec
INFO  | ??:??:?? 1 PowerFSM init, USB power=1
DEBUG | ??:??:?? 1 Enter state: BOOT
[  1543][D][esp32-hal-cpu.c:244] setCpuFrequencyMhz(): PLL: 480 / 6 = 80 Mhz, APB: 80000000 Hz
DEBUG | ??:??:?? 1 [Power] Battery{PTS}: usbPower=0, isCharging=0, batMv=3100, batPct=0, cfgOBS=80, cfgSDS=86405, cfgLS=328, uptS=1, rtcHS=0, sdtS=0, utc=0
INFO  | ??:??:?? 1 [RangeTestModule] Range Test Module - Disabled
INFO  | ??:??:?? 4 [PowerFSM] Loss of power in Powered
INFO  | ??:??:?? 4 [PowerFSM] Loss of power in Powered
INFO  | ??:??:?? 4 [PowerFSM] Initialise the NimBLE bluetooth module
DEBUG | ??:??:?? 4 [PowerFSM] Enter state: ON
DEBUG | ??:??:?? 17 [RadioIf] (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=38, time 518 ms
DEBUG | ??:??:?? 17 [RadioIf] Lora RX (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=5 Ch=0x8 encrypted rxSNR=6 rxRSSI=-85)
DEBUG | ??:??:?? 17 [RadioIf] AirTime - Packet received : 518ms
DEBUG | ??:??:?? 17 [Router] Add packet record (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=5 Ch=0x8 encrypted rxSNR=6 rxRSSI=-85)
DEBUG | ??:??:?? 17 [Router] Using channel 0 (hash 0x8)
DEBUG | ??:??:?? 17 [Router] Expanding short PSK #1
DEBUG | ??:??:?? 17 [Router] Using AES128 key!
DEBUG | ??:??:?? 17 [Router] ESP32 crypt fr=e0d392b0, num=2f67f17b, numBytes=22!
DEBUG | ??:??:?? 17 [Router] decoded message (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=5 Ch=0x0 Portnum=3 rxSNR=6 rxRSSI=-85)
DEBUG | ??:??:?? 17 [Router] handleReceived(REMOTE) (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=5 Ch=0x0 Portnum=3 rxSNR=6 rxRSSI=-85)
DEBUG | ??:??:?? 17 [Router] Module 'position' wantsPacket=1
INFO  | ??:??:?? 17 [Router] Received position from=0xe0d392b0, id=0x2f67f17b, portnum=3, payloadlen=18
INFO  | ??:??:?? 17 [Router] POSITION node=e0d392b0 l=18 latI=480780550 lonI=116579950 msl=598 hae=0 geo=0 pdop=0 hdop=0 vdop=0 siv=0 fxq=0 fxt=0 pts=0 time=1717505834
DEBUG | ??:??:?? 17 [Router] Upgrading time to quality 2
DEBUG | 12:57:14 17 [Router] Read RTC time as 1717505834
INFO  | 12:57:14 17 [Router] updatePosition REMOTE node=0xe0d392b0 time=1717505834, latI=480780550, lonI=116579950
DEBUG | 12:57:14 17 [Router] Node status update: 4 online, 6 total
DEBUG | 12:57:14 17 [Router] Module 'position' considered
DEBUG | 12:57:14 17 [Router] Module 'routing' wantsPacket=1
INFO  | 12:57:14 17 [Router] Received routing from=0xe0d392b0, id=0x2f67f17b, portnum=3, payloadlen=18
DEBUG | 12:57:14 17 [Router] Routing sniffing (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=5 Ch=0x0 Portnum=3 rxSNR=6 rxRSSI=-85)
INFO  | 12:57:14 17 [Router] Rebroadcasting received floodmsg to neighbors
DEBUG | 12:57:14 17 [Router] Expanding short PSK #1
DEBUG | 12:57:14 17 [Router] Using AES128 key!
DEBUG | 12:57:14 17 [Router] ESP32 crypt fr=e0d392b0, num=2f67f17b, numBytes=22!
DEBUG | 12:57:14 17 [Router] enqueuing for send (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=4 Ch=0x8 encrypted rxSNR=6 rxRSSI=-85)
DEBUG | 12:57:14 17 [Router] txGood=0,rxGood=1,rxBad=0
DEBUG | 12:57:14 17 [Router] rx_snr found. hop_limit:4 rx_snr:6.000000
DEBUG | 12:57:14 17 [Router] rx_snr found in packet. Setting tx delay:2604
DEBUG | 12:57:14 17 [Router] Delivering rx packet (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=5 Ch=0x0 Portnum=3 rxSNR=6 rxRSSI=-85)
DEBUG | 12:57:14 17 [Router] Update DB node 0xe0d392b0, rx_time=0
DEBUG | 12:57:14 17 [Router] Forwarding to phone (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=5 Ch=0x0 Portnum=3 rxSNR=6 rxRSSI=-85)
DEBUG | 12:57:14 17 [Router] Module 'routing' considered
DEBUG | 12:57:14 18 [RadioIf] (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=38, time 518 ms
DEBUG | 12:57:14 18 [RadioIf] Lora RX (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=4 Ch=0x8 encrypted rxSNR=6.5 rxRSSI=-21)
DEBUG | 12:57:14 18 [RadioIf] AirTime - Packet received : 518ms
DEBUG | 12:57:14 18 [Router] Found existing packet record for fr=0xe0d392b0,to=0xffffffff,id=0x2f67f17b
DEBUG | 12:57:14 18 [Router] Found existing packet record for fr=0xe0d392b0,to=0xffffffff,id=0x2f67f17b
DEBUG | 12:57:14 18 [Router] Add packet record (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=4 Ch=0x8 encrypted rxSNR=6.5 rxRSSI=-21)
DEBUG | 12:57:14 18 [Router] Ignoring incoming msg, because we've already seen it (id=0x2f67f17b fr=0xb0 to=0xff, WantAck=0, HopLim=4 Ch=0x8 encrypted rxSNR=6.5 rxRSSI=-21)
DEBUG | 12:57:14 18 [Router] cancelSending id=0x2f67f17b, removed=1
DEBUG | 12:57:14 18 [Router] Incoming message was filtered 0xe0d392b0
DEBUG | 12:57:18 21 [Power] Battery{PTS}: usbPower=0, isCharging=0, batMv=3585, batPct=35, cfgOBS=80, cfgSDS=86405, cfgLS=328, uptS=21, rtcHS=3438, sdtS=0, utc=1717505838
INFO  | 12:57:28 31 [NodeInfoModule] Sending our nodeinfo to mesh (wantReplies=1)
INFO  | 12:57:28 31 [NodeInfoModule] sending owner !336654bc/PV_PowerBank/PVPB
DEBUG | 12:57:28 31 [NodeInfoModule] Initial packet id 1475256026, numPacketId 4294967295
DEBUG | 12:57:28 31 [NodeInfoModule] Update DB node 0x336654bc, rx_time=1717505848
DEBUG | 12:57:28 31 [NodeInfoModule] handleReceived(LOCAL) (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x0 Portnum=4 WANTRESP rxtime=1717505848 priority=10)
DEBUG | 12:57:28 31 [NodeInfoModule] No modules interested in portnum=4, src=LOCAL
DEBUG | 12:57:28 31 [NodeInfoModule] localSend to channel 0
DEBUG | 12:57:28 31 [NodeInfoModule] Add packet record (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x0 Portnum=4 WANTRESP rxtime=1717505848 priority=10)
DEBUG | 12:57:28 31 [NodeInfoModule] Expanding short PSK #1
DEBUG | 12:57:28 31 [NodeInfoModule] Using AES128 key!
DEBUG | 12:57:28 31 [NodeInfoModule] ESP32 crypt fr=336654bc, num=57ee9edc, numBytes=47!
DEBUG | 12:57:28 31 [NodeInfoModule] enqueuing for send (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x8 encrypted rxtime=1717505848 hopStart=7 priority=10)
DEBUG | 12:57:28 31 [NodeInfoModule] txGood=0,rxGood=2,rxBad=0
WARN  | 12:57:28 31 [RadioIf] Can not send yet, busyRx
WARN  | 12:57:28 31 [RadioIf] Can not send yet, busyRx
WARN  | 12:57:28 31 [RadioIf] Can not send yet, busyRx
WARN  | 12:57:28 31 [RadioIf] Can not send yet, busyRx
WARN  | 12:57:28 31 [RadioIf] Can not send yet, busyRx
WARN  | 12:57:28 31 [RadioIf] Can not send yet, busyRx
DEBUG | 12:57:28 31 [RadioIf] Ignore false preamble detection.
DEBUG | 12:57:28 32 [RadioIf] Starting low level send (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x8 encrypted rxtime=1717505848 hopStart=7 priority=10)
DEBUG | 12:57:28 32 [RadioIf] (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=63, time 706 ms
DEBUG | 12:57:28 32 [RadioIf] AirTime - Packet transmitted : 706ms
DEBUG | 12:57:29 32 [RadioIf] Completed sending (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x8 encrypted rxtime=1717505848 hopStart=7 priority=10)
DEBUG | 12:57:30 33 [RadioIf] (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=63, time 706 ms
DEBUG | 12:57:30 33 [RadioIf] Lora RX (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=6 rxRSSI=-22 hopStart=7)
DEBUG | 12:57:30 33 [RadioIf] AirTime - Packet received : 706ms
DEBUG | 12:57:30 33 [Router] Rx someone rebroadcasting for us (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=6 rxRSSI=-22 hopStart=7)
DEBUG | 12:57:30 33 [Router] didn't find pending packet
DEBUG | 12:57:30 33 [Router] Found existing packet record for fr=0x336654bc,to=0xffffffff,id=0x57ee9edc
DEBUG | 12:57:30 33 [Router] Found existing packet record for fr=0x336654bc,to=0xffffffff,id=0x57ee9edc
DEBUG | 12:57:30 33 [Router] Add packet record (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=6 rxRSSI=-22 hopStart=7)
DEBUG | 12:57:30 33 [Router] Ignoring incoming msg, because we've already seen it (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=6 rxRSSI=-22 hopStart=7)
DEBUG | 12:57:30 33 [Router] cancelSending id=0x57ee9edc, removed=0
DEBUG | 12:57:30 33 [Router] Incoming message was filtered 0x336654bc
DEBUG | 12:57:31 34 [RadioIf] (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=63, time 706 ms
DEBUG | 12:57:31 34 [RadioIf] Lora RX (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=4 rxRSSI=-87)
DEBUG | 12:57:31 34 [RadioIf] AirTime - Packet received : 706ms
DEBUG | 12:57:31 34 [Router] Rx someone rebroadcasting for us (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=4 rxRSSI=-87)
DEBUG | 12:57:31 34 [Router] didn't find pending packet
DEBUG | 12:57:31 34 [Router] Found existing packet record for fr=0x336654bc,to=0xffffffff,id=0x57ee9edc
DEBUG | 12:57:31 34 [Router] Found existing packet record for fr=0x336654bc,to=0xffffffff,id=0x57ee9edc
DEBUG | 12:57:31 34 [Router] Add packet record (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=4 rxRSSI=-87)
DEBUG | 12:57:31 34 [Router] Ignoring incoming msg, because we've already seen it (id=0x57ee9edc fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=4 rxRSSI=-87)
DEBUG | 12:57:31 34 [Router] cancelSending id=0x57ee9edc, removed=0
DEBUG | 12:57:31 34 [Router] Incoming message was filtered 0x336654bc
DEBUG | 12:57:38 41 [Power] Battery{PTS}: usbPower=0, isCharging=0, batMv=3838, batPct=64, cfgOBS=80, cfgSDS=86405, cfgLS=328, uptS=41, rtcHS=3458, sdtS=0, utc=1717505858
INFO  | 12:57:43 46 [DeviceTelemetryModule] (Sending): air_util_tx=0.019611, channel_utilization=5.256667, battery_level=64, voltage=3.838000
DEBUG | 12:57:43 46 [DeviceTelemetryModule] updateTelemetry LOCAL
DEBUG | 12:57:43 46 [DeviceTelemetryModule] Node status update: 4 online, 6 total
INFO  | 12:57:43 46 [DeviceTelemetryModule] Sending packet to mesh
DEBUG | 12:57:43 46 [DeviceTelemetryModule] Update DB node 0x336654bc, rx_time=1717505863
DEBUG | 12:57:43 46 [DeviceTelemetryModule] handleReceived(LOCAL) (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x0 Portnum=67 rxtime=1717505863 priority=10)
DEBUG | 12:57:43 46 [DeviceTelemetryModule] No modules interested in portnum=67, src=LOCAL
DEBUG | 12:57:43 46 [DeviceTelemetryModule] localSend to channel 0
DEBUG | 12:57:43 46 [DeviceTelemetryModule] Add packet record (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x0 Portnum=67 rxtime=1717505863 priority=10)
DEBUG | 12:57:43 46 [DeviceTelemetryModule] Expanding short PSK #1
DEBUG | 12:57:43 46 [DeviceTelemetryModule] Using AES128 key!
DEBUG | 12:57:43 46 [DeviceTelemetryModule] ESP32 crypt fr=336654bc, num=57ee9edd, numBytes=28!
DEBUG | 12:57:43 46 [DeviceTelemetryModule] enqueuing for send (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x8 encrypted rxtime=1717505863 hopStart=7 priority=10)
DEBUG | 12:57:43 46 [DeviceTelemetryModule] txGood=1,rxGood=4,rxBad=0
DEBUG | 12:57:43 46 [DeviceTelemetryModule] Using channel 0 (hash 0x8)
DEBUG | 12:57:43 46 [DeviceTelemetryModule] Expanding short PSK #1
DEBUG | 12:57:43 46 [DeviceTelemetryModule] Using AES128 key!
DEBUG | 12:57:43 46 [DeviceTelemetryModule] ESP32 crypt fr=336654bc, num=57ee9edd, numBytes=28!
DEBUG | 12:57:43 46 [DeviceTelemetryModule] decoded message (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x0 Portnum=67 rxtime=1717505863 hopStart=7 priority=10)
DEBUG | 12:57:43 46 [RadioIf] Starting low level send (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x8 encrypted rxtime=1717505863 hopStart=7 priority=10)
DEBUG | 12:57:43 46 [RadioIf] (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=44, time 559 ms
DEBUG | 12:57:43 46 [RadioIf] AirTime - Packet transmitted : 559ms
DEBUG | 12:57:44 47 [RadioIf] Completed sending (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=7 Ch=0x8 encrypted rxtime=1717505863 hopStart=7 priority=10)
DEBUG | 12:57:44 48 [RadioIf] (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=44, time 559 ms
DEBUG | 12:57:44 48 [RadioIf] Lora RX (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=6.5 rxRSSI=-21 hopStart=7)
DEBUG | 12:57:44 48 [RadioIf] AirTime - Packet received : 559ms
DEBUG | 12:57:44 48 [Router] Rx someone rebroadcasting for us (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=6.5 rxRSSI=-21 hopStart=7)
DEBUG | 12:57:44 48 [Router] didn't find pending packet
DEBUG | 12:57:44 48 [Router] Found existing packet record for fr=0x336654bc,to=0xffffffff,id=0x57ee9edd
DEBUG | 12:57:44 48 [Router] Found existing packet record for fr=0x336654bc,to=0xffffffff,id=0x57ee9edd
DEBUG | 12:57:44 48 [Router] Add packet record (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=6.5 rxRSSI=-21 hopStart=7)
DEBUG | 12:57:44 48 [Router] Ignoring incoming msg, because we've already seen it (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=6.5 rxRSSI=-21 hopStart=7)
DEBUG | 12:57:44 48 [Router] cancelSending id=0x57ee9edd, removed=0
DEBUG | 12:57:44 48 [Router] Incoming message was filtered 0x336654bc
DEBUG | 12:57:45 48 [RadioIf] (bw=250, sf=11, cr=4/5) packet symLen=8 ms, payloadSize=44, time 559 ms
DEBUG | 12:57:45 48 [RadioIf] Lora RX (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=5.75 rxRSSI=-85)
DEBUG | 12:57:45 48 [RadioIf] AirTime - Packet received : 559ms
DEBUG | 12:57:45 48 [Router] Rx someone rebroadcasting for us (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=5.75 rxRSSI=-85)
DEBUG | 12:57:45 48 [Router] didn't find pending packet
DEBUG | 12:57:45 48 [Router] Found existing packet record for fr=0x336654bc,to=0xffffffff,id=0x57ee9edd
DEBUG | 12:57:45 48 [Router] Found existing packet record for fr=0x336654bc,to=0xffffffff,id=0x57ee9edd
DEBUG | 12:57:45 48 [Router] Add packet record (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=5.75 rxRSSI=-85)
DEBUG | 12:57:45 48 [Router] Ignoring incoming msg, because we've already seen it (id=0x57ee9edd fr=0xbc to=0xff, WantAck=0, HopLim=6 Ch=0x8 encrypted rxSNR=5.75 rxRSSI=-85)
DEBUG | 12:57:45 48 [Router] cancelSending id=0x57ee9edd, removed=0
DEBUG | 12:57:45 48 [Router] Incoming message was filtered 0x336654bc
DEBUG | 12:57:58 61 [Power] Battery{PTS}: usbPower=0, isCharging=0, batMv=3957, batPct=76, cfgOBS=80, cfgSDS=86405, cfgLS=328, uptS=61, rtcHS=3478, sdtS=0, utc=1717505878

... 120 Seconds ... 104 mA -> 129 mA

DEBUG | 12:58:17 80 [PowerFSM] Enter state: SHUTDOWN
INFO  | 12:58:17 80 [PowerFSM] Shutting down
INFO  | 12:58:17 80 [PowerFSM] Entering deep sleep forever
INFO  | 12:58:17 80 [PowerFSM] Disable bluetooth
DEBUG | 12:58:17 80 [PowerFSM] SX126x entering sleep mode (FIXME, don't keep config)
INFO  | 12:58:17 80 [PowerFSM] Saving /prefs/db.proto
INFO  | 12:58:17 80 [PowerFSM] Saving /prefs/config.proto
INFO  | 12:58:17 80 [PowerFSM] Saving /prefs/module.proto
INFO  | 12:58:17 80 [PowerFSM] Saving /prefs/channels.proto

... 125 Seconds ... 12 mA

E (80947) RTCIO: rtc_gpio_isolate(171): RTCIO number error
E (80947) RTCIO: rtc_gpio_isolate(171): RTCIO number error
E (80948) RTCIO: rtc_gpio_isolate(171): RTCIO number error
```
