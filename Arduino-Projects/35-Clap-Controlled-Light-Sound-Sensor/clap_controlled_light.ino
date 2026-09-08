const int SOUND_PIN=2,LIGHT_PIN=9;bool lightOn=false;int lastSoundState=LOW;unsigned long lastClapTime=0;const unsigned long DEBOUNCE_MS=300;
void setup(){pinMode(SOUND_PIN,INPUT);pinMode(LIGHT_PIN,OUTPUT);}
void loop(){int s=digitalRead(SOUND_PIN);if(s==HIGH&&lastSoundState==LOW&&millis()-lastClapTime>DEBOUNCE_MS){lightOn=!lightOn;digitalWrite(LIGHT_PIN,lightOn?HIGH:LOW);lastClapTime=millis();}lastSoundState=s;}
