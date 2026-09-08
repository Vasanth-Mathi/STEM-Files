const int LEVEL_PIN=A0,GREEN_LED=8,YELLOW_LED=9,RED_LED=10;const int MEDIUM_LEVEL=350,HIGH_LEVEL=650;
void setup(){pinMode(GREEN_LED,OUTPUT);pinMode(YELLOW_LED,OUTPUT);pinMode(RED_LED,OUTPUT);Serial.begin(9600);}
void loop(){int level=analogRead(LEVEL_PIN);Serial.println(level);digitalWrite(GREEN_LED,LOW);digitalWrite(YELLOW_LED,LOW);digitalWrite(RED_LED,LOW);if(level>=HIGH_LEVEL)digitalWrite(RED_LED,HIGH);else if(level>=MEDIUM_LEVEL)digitalWrite(YELLOW_LED,HIGH);else digitalWrite(GREEN_LED,HIGH);delay(200);}
