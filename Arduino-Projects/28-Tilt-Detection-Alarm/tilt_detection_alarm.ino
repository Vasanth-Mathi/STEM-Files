const int TILT_PIN=2,LED_PIN=8,BUZZER_PIN=9;
void setup(){pinMode(TILT_PIN,INPUT_PULLUP);pinMode(LED_PIN,OUTPUT);pinMode(BUZZER_PIN,OUTPUT);}
void loop(){bool tilted=digitalRead(TILT_PIN)==LOW;digitalWrite(LED_PIN,tilted?HIGH:LOW);digitalWrite(BUZZER_PIN,tilted?HIGH:LOW);delay(50);}
