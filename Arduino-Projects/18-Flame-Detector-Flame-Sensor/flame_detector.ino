const int FLAME_PIN=2,LED_PIN=8,BUZZER_PIN=9,FLAME_DETECTED_STATE=LOW;
void setup(){pinMode(FLAME_PIN,INPUT);pinMode(LED_PIN,OUTPUT);pinMode(BUZZER_PIN,OUTPUT);}
void loop(){bool f=digitalRead(FLAME_PIN)==FLAME_DETECTED_STATE;digitalWrite(LED_PIN,f?HIGH:LOW);digitalWrite(BUZZER_PIN,f?HIGH:LOW);delay(50);}
