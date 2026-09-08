const int LEVEL_PIN=A0,LED_PIN=8,BUZZER_PIN=9,OVERFLOW_THRESHOLD=650;
void setup(){pinMode(LED_PIN,OUTPUT);pinMode(BUZZER_PIN,OUTPUT);Serial.begin(9600);}
void loop(){int level=analogRead(LEVEL_PIN);Serial.println(level);bool overflow=level>=OVERFLOW_THRESHOLD;digitalWrite(LED_PIN,overflow?HIGH:LOW);digitalWrite(BUZZER_PIN,overflow?HIGH:LOW);delay(200);}
