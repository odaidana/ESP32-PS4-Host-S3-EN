# ESP32-PS4-Host-S3

A standalone, offline Web Server hosted entirely on the ESP32-S3 (N16R8) to deploy PS4 Jailbreak payloads (GoldHEN) locally without internet access.

## Why this project?
Using public DNS servers or online hosts to jailbreak the PS4 can sometimes be unstable or risky (accidental system updates). This project turns your ESP32-S3 into a dedicated local access point. Once configured, your PS4 connects directly to the ESP32 Wi-Fi, blocks Sony servers completely, and loads payloads instantly.

## Hardware Requirements
- ESP32-S3 Core Board (N16R8 variant utilized).
- USB-C Data Cable (for flashing and power).

## How it Works
1. **Wi-Fi Access Point:** The ESP32-S3 creates an internal Wi-Fi network (SSID: `PS4-Jailbreak-Host`).
2. **DNS redirection:** Any HTTP request from the PS4 User's Guide or Web Browser is captured and redirected to the internal server storage.
3. **Payload Delivery:** The 16MB Flash memory stores the HTML/JS exploit files and transmits the GoldHEN payload directly to the console memory.

## Setup & Installation
1. Open the source code in **Arduino IDE**.
2. Install the ESP32 board manager (`v3.x` or later).
3. Select your partition scheme to accommodate the exploit files (e.g., `16MB Flash with SPIFFS/LittleFS`).
4. Flash the code to your ESP32-S3.
5. Upload the exploit files to the internal file system using the Arduino ESP32 Sketch Data Upload tool.
6. Connect your PS4 to the new Wi-Fi network and open the User's Guide.
