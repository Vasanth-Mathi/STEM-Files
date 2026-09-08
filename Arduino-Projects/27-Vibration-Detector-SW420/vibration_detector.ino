const int VIBRATION_PIN=2,LED_PIN=8,BUZZER_PIN=9,VIBRATION_STATE=HIGH;
void setup(){pinMode(VIBRATION_PIN,INPUT);pinMode(LED_PIN,OUTPUT);pinMode(BUZZER_PIN,OUTPUT);}
void loop(){bool v=digitalRead(VIBRATION_PIN)==VIBRATION_STATE;digitalWrite(LED_PIN,v?HIGH:LOW);digitalWrite(BUZZER_PIN,v?HIGH:LOW);delay(20);}
