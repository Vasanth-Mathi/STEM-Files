#include <DHT.h>

/*
  Automatic Greenhouse Fan Using DHT11 Sensor
  Board: Arduino Uno
*/

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int FAN_IN1 = 8;
const int FAN_IN2 = 9;

const float TEMP_ON = 30.0;
const float TEMP_OFF = 28.0;
const float HUMIDITY_ON = 75.0;
const float HUMIDITY_OFF = 70.0;

bool fanOn = false;

void startFan();
void stopFan();

void setup() {
  pinMode(FAN_IN1, OUTPUT);
  pinMode(FAN_IN2, OUTPUT);

  dht.begin();
  stopFan();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    stopFan();
    fanOn = false;
    delay(2000);
    return;
  }

  if (!fanOn && (temperature >= TEMP_ON || humidity >= HUMIDITY_ON)) {
    fanOn = true;
  } else if (fanOn &&
             temperature <= TEMP_OFF &&
             humidity <= HUMIDITY_OFF) {
    fanOn = false;
  }

  if (fanOn) {
    startFan();
  } else {
    stopFan();
  }

  delay(2000);
}

void startFan() {
  digitalWrite(FAN_IN1, HIGH);
  digitalWrite(FAN_IN2, LOW);
}

void stopFan() {
  digitalWrite(FAN_IN1, LOW);
  digitalWrite(FAN_IN2, LOW);
}
