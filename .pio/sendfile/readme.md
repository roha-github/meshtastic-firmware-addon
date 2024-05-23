# SendFile over Lora

To transfer files between Meshtastic nodes, the web server is used for uploading and downloading.

* sender uploads the file to its node via the web server
* sender starts and receiver authorizes file transfer
* file is sent in small chunks and sender/receiver see progress
* receiver downloads file from his node's web server

## Install webinterface

The sender and receiver nodes install "sendfile.html" on their web server.

* download sendfile.html and sendfile-install.html
* connect node serial to computer or smartphone via USB data cable
* configure your node and disable Bluetooth
* configure your node and enable wifi for your hotspot (e.g. FRITZ!Box-123)
* open sendfile-install.html and upload sendfile.html to your node
* configure your node and enable wifi for your mobile hotspot (e.g. Samsung-123)
* configure your smartphone and enable mobile hotspot (e.g. Samsung-123)

## Connect to wifi

The transmitter and receiver connect to the wifi hotspot.

* configure your node and enable wifi for your mobile hotspot (e.g. Samsung-123)
* connect Meshtastic app via IP-Address
* or use Chrome browser and open http://meshtastic.local

You may have to determine the IP address on the smartphone or via the logs with a serial USB terminal.

## Upload file

The sender uploads the file to its node via webinterface.

* configure your node and enable wifi for your mobile hotspot (e.g. Samsung-123)
* resize your Image and rename it as sendfile.jpg
* or create ZIP-File and rename it as sendfile.zip
* use Chrome browser and open http://meshtastic.local/sendfile.html
* select sendfile.jpg or sendfile.zip and upload

## Transfer file

The sender sends the file to the recipient via Lora.

* configure your node and enable wifi for your mobile hotspot (e.g. Samsung-123)
* connect Meshtastic app via IP-Address
* or use Chrome browser and open http://meshtastic.local
* send message "sendfile:sendfile.jpg" to receiver
* get message "ok" from receiver
* get message "finished sendfile.jpg" from receiver

## Download file

The recipient downloads the file from his node.

* configure your node and enable wifi for your mobile hotspot (e.g. Samsung-123)
* connect Meshtastic app via IP-Address
* or use Chrome browser and open http://meshtastic.local
* get message "sendfile:sendfile.jpg" from sender
* send message "ok" to sender
* get message "download http://meshtastic.local/sendfile.jpg" from sender
* use Chrome browser and open http://meshtastic.local/sendfile.jpg
