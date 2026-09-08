const int PIR_PIN=2,LED_PIN=8,BUZZER_PIN=9;
void setup(){pinMode(PIR_PIN,INPUT);pinMode(LED_PIN,OUTPUT);pinMode(BUZZER_PIN,OUTPUT);}
void loop(){bool m=digitalRead(PIR_PIN)==HIGH;digitalWrite(LED_PIN,m?HIGH:LOW);digitalWrite(BUZZER_PIN,m?HIGH:LOW);delay(50);}
