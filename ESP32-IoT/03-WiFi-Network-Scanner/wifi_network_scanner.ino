#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
  Serial.println("Scanning Wi-Fi networks...");

  int count = WiFi.scanNetworks();

  if (count == 0) {
    Serial.println("No networks found.");
  } else {
    for (int i = 0; i < count; i++) {
      Serial.print(i + 1);
      Serial.print(". ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" | RSSI: ");
      Serial.print(WiFi.RSSI(i));
      Serial.print(" dBm | ");
      Serial.println(WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "Open" : "Secured");
    }
  }

  WiFi.scanDelete();
  Serial.println();
  delay(5000);
}
