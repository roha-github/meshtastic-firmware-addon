# Meshtastic Firmware - Addons (Fork)

This is a fork of the Meshtastic firmware to provide a new feature called "Power Timer Switch".

**Reduce current consumption:**

* always switched on when battery fully charged (solar panel in sunny weather)
* power-on few minutes every hour (e.g. 5 minutes per hour)
* power-on more minutes at longer intervals (e.g. 15 minutes every 6 hours)

The objective is to be able to operate a router for several days even with very small solar panels and batteries.

## Configuration

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

### Alway-on (percentage)

The node stays switched on when the battery is charged to over X0 percent. This option is intended for the node to be operated with a solar panel. The node remains permanently active on sunny days and the power-saving mode is activated on shady days.

### Saving Mode (last digit)

This option can be used to prevent the configuration from being saved to the flash every time the device is shut down. 

* 0 ~ Power Timer Switch disabled
* 1 ~ Power Timer Switch enabled / save prefs disabled
* 2 ~ Power Timer Switch enabled / save prefs enabled - every hour
* 3 ~ Power Timer Switch enabled / save prefs enabled - every long interval

### Uptime per hour (last two digits)

This option controls how many minutes the node is switched on per hour. It is always switched on on the hour if the node has received the time from another node or via GPS. Several time-controlled nodes synchronize via the time and expand the mesh network. Over time, human observers will notice that certain routers are online for a few minutes every hour. They can then adjust their communication accordingly.

### Longer uptime (second last digit)

It is recommended to switch on the node for 15 minutes every few hours. The regular interval for position with time is 15 minutes. Even without GPS, the node receives the time from other nodes and can therefore regularly align itself with the time. 

The number is a multiplier for a supplement to the regular uptime. If the uptime is 5 minutes and the multiplier is 2, this results in a longer uptime of 15 minutes.

### Longer uptime interval (last digit)

An interval can be defined in which the node remains switched on for a longer uptime. 

* 0 = interval deactivated
* 2..8 = interval of 2 .. 8 hours (12x ... 3x a day)
