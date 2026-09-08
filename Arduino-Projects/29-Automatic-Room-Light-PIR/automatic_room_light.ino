const int PIR_PIN=2,LIGHT_PIN=9;const unsigned long OFF_DELAY_MS=10000;unsigned long lastMotionTime=0;bool lightOn=false;
void setup(){pinMode(PIR_PIN,INPUT);pinMode(LIGHT_PIN,OUTPUT);}
void loop(){if(digitalRead(PIR_PIN)==HIGH){lastMotionTime=millis();lightOn=true;}if(lightOn&&millis()-lastMotionTime>=OFF_DELAY_MS)lightOn=false;digitalWrite(LIGHT_PIN,lightOn?HIGH:LOW);delay(50);}
