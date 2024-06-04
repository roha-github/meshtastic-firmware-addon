# Current Consumption

## Heltec Wireless Stick V3

| ID | Role | Serial | ReBro | GPS | PSave | SBat | ADC | WBlu | DeS | LiS | MiW | Dis | TX | MQTT | BLE | boot | time | down |
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
| 1 | Client | dis | local | not | dis | 80 | 0 | 60 | 86405 | 328 | 10 | 1 | 19 | ign | fix | 99,5mA | 1:26 | 2,1mA |

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

E (81116) RTCIO: rtc_gpio_isolate(171): RTCIO number error
E (81116) RTCIO: rtc_gpio_isolate(171): RTCIO number error
E (81117) RTCIO: rtc_gpio_isolate(171): RTCIO number error

... 125 Seconds ... 12 mA
```
