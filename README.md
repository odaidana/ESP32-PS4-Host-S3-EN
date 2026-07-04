# ESP32S3-PS4-Wall

A standalone network-blocking and DNS redirection tool hosted on the ESP32-S3 (N16R8). It acts as a local firewall for the PS4 to prevent accidental system updates by completely cutting off external internet access and forcing a local redirect page.

## Why this project?
Connecting a jailbroken or lower-firmware PS4 to the internet carries a high risk of automatic system updates from Sony. This project creates a fully isolated Wi-Fi Access Point. It drops all external web traffic to keep the console safe from updates, while redirecting any browser or User's Guide request to a local dashboard confirming the secure block.

## Hardware Requirements
- ESP32-S3 Core Board (N16R8).
- USB-C Data Cable.

## How it Works
1. **Isolated Access Point:** The ESP32-S3 broadcasts a secure Wi-Fi network.
2. **Total Internet Block:** The board does not route traffic to the wide internet, keeping the PS4 100% offline.
3. **DNS Captive Portal:** Any HTTP request from the PS4 is intercepted and redirected locally to display: `REDIRECT WEB FOR ADVANCED NETNAME(NETNAME)`.

## Setup & Installation
1. Open the source code in **Arduino IDE**.
2. Select your ESP32-S3 board from the boards manager.
3. Upload the C++ sketch provided in the repository.
4. On your PS4, search for Wi-Fi networks and connect to `PS4-Secure-Wall`.
