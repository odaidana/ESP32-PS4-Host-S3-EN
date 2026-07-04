#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>

// Access Point Configuration
const char* ssid = "PS4-Secure-Wall";
const char* password = "PS4-PASSOWRD-09089"; // PASSWORD

// Network Ports & DNS Setup
const byte DNS_PORT = 53;
DNSServer dnsServer;
WebServer server(80);

// Captive Portal HTML Response
String responseHTML = ""
"<!DOCTYPE html>"
"<html>"
"<head>"
"    <meta charset='UTF-8'>"
"    <title>Network Firewall Active</title>"
"    <style>"
"        body { background-color: #0d1117; color: #58a6ff; font-family: sans-serif; text-align: center; padding-top: 100px; }"
"        .container { border: 2px solid #238636; display: inline-block; padding: 30px; border-radius: 10px; background-color: #161b22; }"
"        h1 { color: #f0f6fc; font-size: 24px; }"
"        p { font-size: 18px; font-weight: bold; color: #da3633; }"
"    </style>"
"</head>"
"<body>"
"    <div class='container'>"
"        <h1>REDIRECT WEB PS4</h1>"
"        <p>External Internet Traffic is Strictly Blocked. Sony Servers Unreachable.</p>"
"    </div>"
"</body>"
"</html>";

void setup() {
  Serial.begin(115200);

  // Initialize ESP32-S3 as an Access Point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.println("");
  Serial.print("Access Point Started. SSID: ");
  Serial.println(ssid);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  // Start DNS Server to intercept all traffic and redirect to local IP
  dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());

  // Handle all HTTP requests by serving the local captive portal page
  server.onNotFound([]() {
    server.send(200, "text/html", responseHTML);
  });

  server.begin();
  Serial.println("HTTP Server Started.");
}

void loop() {
  // Keep the DNS routing and HTTP server processes active
  dnsServer.processNextRequest();
  server.handleClient();
}
