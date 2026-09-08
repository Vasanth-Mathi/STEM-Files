#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Greenhouse Automation"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define DHT_TYPE DHT11

const int DHT_PIN = 4;
const int FAN_IN1 = 26;
const int FAN_IN2 = 27;

const float FAN_ON_TEMP = 30.0;
const float FAN_OFF_TEMP = 28.0;

DHT dht(DHT_PIN, DHT_TYPE);
BlynkTimer timer;

bool autoMode = true;
bool fanOn = false;
bool manualFan = false;

void setFan(bool on) {
  digitalWrite(FAN_IN1, on ? HIGH : LOW);
  digitalWrite(FAN_IN2, LOW);
}

BLYNK_WRITE(V2) {
  autoMode = param.asInt();
}

BLYNK_WRITE(V3) {
  manualFan = param.asInt();

  if (!autoMode) {
    setFan(manualFan);
  }
}

void updateGreenhouse() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    return;
  }

  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);

  if (autoMode) {
    if (!fanOn && temperature >= FAN_ON_TEMP) {
      fanOn = true;
    } else if (fanOn && temperature <= FAN_OFF_TEMP) {
      fanOn = false;
    }

    setFan(fanOn);
  } else {
    setFan(manualFan);
  }
}

void setup() {
  pinMode(FAN_IN1, OUTPUT);
  pinMode(FAN_IN2, OUTPUT);

  dht.begin();
  setFan(false);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, updateGreenhouse);
}

void loop() {
  Blynk.run();
  timer.run();
}
