const int SOIL_PIN=A0,GREEN_LED=8,YELLOW_LED=9,RED_LED=10;const int WET_THRESHOLD=400,DRY_THRESHOLD=650;
void setup(){pinMode(GREEN_LED,OUTPUT);pinMode(YELLOW_LED,OUTPUT);pinMode(RED_LED,OUTPUT);Serial.begin(9600);}
void loop(){int m=analogRead(SOIL_PIN);Serial.println(m);digitalWrite(GREEN_LED,LOW);digitalWrite(YELLOW_LED,LOW);digitalWrite(RED_LED,LOW);if(m<=WET_THRESHOLD)digitalWrite(GREEN_LED,HIGH);else if(m>=DRY_THRESHOLD)digitalWrite(RED_LED,HIGH);else digitalWrite(YELLOW_LED,HIGH);delay(500);}
