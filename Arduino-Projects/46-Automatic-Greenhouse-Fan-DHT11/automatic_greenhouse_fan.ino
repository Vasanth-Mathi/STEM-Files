#include <DHT.h>

DHT dht(2, DHT11);

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  dht.begin();

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  } else {
    if (temperature >= 30 || humidity >= 75) {
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
    }

    if (temperature <= 28 && humidity <= 70) {
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
    }
  }

  delay(2000);
}
