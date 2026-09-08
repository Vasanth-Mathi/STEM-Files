const int RAIN_PIN=2,LED_PIN=8,BUZZER_PIN=9,RAIN_DETECTED_STATE=LOW;
void setup(){pinMode(RAIN_PIN,INPUT);pinMode(LED_PIN,OUTPUT);pinMode(BUZZER_PIN,OUTPUT);}
void loop(){bool r=digitalRead(RAIN_PIN)==RAIN_DETECTED_STATE;digitalWrite(LED_PIN,r?HIGH:LOW);digitalWrite(BUZZER_PIN,r?HIGH:LOW);delay(100);}
