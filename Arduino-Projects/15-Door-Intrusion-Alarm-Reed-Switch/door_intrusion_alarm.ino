const int REED_PIN=2,LED_PIN=8,BUZZER_PIN=9;
void setup(){pinMode(REED_PIN,INPUT_PULLUP);pinMode(LED_PIN,OUTPUT);pinMode(BUZZER_PIN,OUTPUT);}
void loop(){bool open=digitalRead(REED_PIN)==HIGH;digitalWrite(LED_PIN,open?HIGH:LOW);digitalWrite(BUZZER_PIN,open?HIGH:LOW);delay(50);}
