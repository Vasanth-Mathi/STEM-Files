#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <time.h>

const char* WIFI_NAME = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const long GMT_OFFSET_SECONDS = 19800;  // IST = UTC + 5:30
const int DAYLIGHT_OFFSET_SECONDS = 0;

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true) {
      delay(1000);
    }
  }

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  configTime(
    GMT_OFFSET_SECONDS,
    DAYLIGHT_OFFSET_SECONDS,
    "pool.ntp.org",
    "time.nist.gov"
  );
}

void loop() {
  struct tm timeInfo;

  if (!getLocalTime(&timeInfo)) {
    delay(1000);
    return;
  }

  char timeText[20];
  char dateText[20];

  strftime(timeText, sizeof(timeText), "%I:%M:%S %p", &timeInfo);
  strftime(dateText, sizeof(dateText), "%d-%m-%Y", &timeInfo);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.println(timeText);

  display.setTextSize(1);
  display.setCursor(25, 42);
  display.println(dateText);
  display.display();

  delay(1000);
}
