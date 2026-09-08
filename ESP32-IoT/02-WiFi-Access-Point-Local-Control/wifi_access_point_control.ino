#include <WiFi.h>
#include <WebServer.h>

const char* AP_NAME = "ESP32-Control";
const char* AP_PASSWORD = "12345678";

const int LED_PIN = 23;

WebServer server(80);

void showPage() {
  String page = "<h1>ESP32 Local Control</h1>";
  page += "<p><a href='/on'><button>ON</button></a></p>";
  page += "<p><a href='/off'><button>OFF</button></a></p>";
  server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  WiFi.softAP(AP_NAME, AP_PASSWORD);

  Serial.print("Connect to ");
  Serial.println(AP_NAME);
  Serial.print("Open: http://");
  Serial.println(WiFi.softAPIP());

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
