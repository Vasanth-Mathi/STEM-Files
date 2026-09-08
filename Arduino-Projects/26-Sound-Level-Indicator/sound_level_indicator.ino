const int SOUND_PIN=A0,GREEN_LED=8,YELLOW_LED=9,RED_LED=10;const int MEDIUM_LEVEL=80,HIGH_LEVEL=180;
void setup(){pinMode(GREEN_LED,OUTPUT);pinMode(YELLOW_LED,OUTPUT);pinMode(RED_LED,OUTPUT);}
void loop(){int reading=analogRead(SOUND_PIN);int level=abs(reading-512);digitalWrite(GREEN_LED,LOW);digitalWrite(YELLOW_LED,LOW);digitalWrite(RED_LED,LOW);if(level>=HIGH_LEVEL)digitalWrite(RED_LED,HIGH);else if(level>=MEDIUM_LEVEL)digitalWrite(YELLOW_LED,HIGH);else digitalWrite(GREEN_LED,HIGH);delay(20);}
