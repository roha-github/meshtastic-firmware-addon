# SendFile over Lora

To transfer files between Meshtastic nodes, the web server is used for uploading and downloading.

* sender uploads the file to its node via the web server
* sender starts and receiver authorizes file transfer
* file is sent in small chunks and sender/receiver see progress
* receiver downloads file from his node's web server

## Install webinterface

The sender and receiver nodes install "sendfile.html" on their web server.

## Connect to wifi

The transmitter and receiver connect to the wifi hotspot.

## Upload file

The sender uploads the file to its node via webinterface.

## Transfer file

The sender sends the file to the recipient via Lora.

## Download file

The recipient downloads the file from his node.
