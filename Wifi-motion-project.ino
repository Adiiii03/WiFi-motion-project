/*
Goal: capture RSSI data from a target WiFi network using ESP32
Input: nearby WiFi signal strength
Output: timestamped RSSI values in Serial Monitor
Format: time,rssi
Purpose: use signal fluctuations to help detect motion 
*/

#include "WiFi.h"

String targetSSID = "bigCOXonly";

// sets up WiFi scanning
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

// repeatedly scans nearby WiFi networks
void loop() {
  int n = WiFi.scanNetworks();
  unsigned long currentTime = millis();

  for (int i = 0; i < n; ++i) {
    if (WiFi.SSID(i) == targetSSID) {   // finds our specific WiFi by name
      Serial.print(currentTime);
      Serial.print(",");                // prints timestamp and RSSI signal strength
      Serial.println(WiFi.RSSI(i));
    }
  }

  delay(500);     // scans about every 0.5 seconds
}
