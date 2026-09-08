#include <WiFi.h>
#include <WebServer.h>

const char* WIFI_NAME = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const int LED_PIN = 23;

WebServer server(80);

void showPage() {
  String page = "<h1>ESP32 LED Control</h1>";
  page += "<p><a href='/on'><button>LED ON</button></a></p>";
  page += "<p><a href='/off'><button>LED OFF</button></a></p>";
  server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Open: http://");
  Serial.println(WiFi.localIP());

  server.on("/", showPage);

  server.on("/on", []() {
    digitalWrite(LED_PIN, HIGH);
    showPage();
  });

  server.on("/off", []() {
    digitalWrite(LED_PIN, LOW);
    showPage();
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
