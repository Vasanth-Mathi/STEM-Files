#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);const int FAN_IN1=8,FAN_IN2=9;const float TEMP_ON=30.0,TEMP_OFF=28.0,HUMIDITY_ON=75.0,HUMIDITY_OFF=70.0;bool fanOn=false;
void startFan();void stopFan();
void setup(){pinMode(FAN_IN1,OUTPUT);pinMode(FAN_IN2,OUTPUT);dht.begin();stopFan();}
void loop(){float h=dht.readHumidity(),t=dht.readTemperature();if(isnan(h)||isnan(t)){stopFan();fanOn=false;delay(2000);return;}if(!fanOn&&(t>=TEMP_ON||h>=HUMIDITY_ON))fanOn=true;else if(fanOn&&t<=TEMP_OFF&&h<=HUMIDITY_OFF)fanOn=false;if(fanOn)startFan();else stopFan();delay(2000);}
void startFan(){digitalWrite(FAN_IN1,HIGH);digitalWrite(FAN_IN2,LOW);}void stopFan(){digitalWrite(FAN_IN1,LOW);digitalWrite(FAN_IN2,LOW);}
