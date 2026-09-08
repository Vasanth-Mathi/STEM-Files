const int SMOKE_PIN=A0,LED_PIN=8,BUZZER_PIN=9,SMOKE_THRESHOLD=450;
void setup(){pinMode(LED_PIN,OUTPUT);pinMode(BUZZER_PIN,OUTPUT);Serial.begin(9600);}
void loop(){int v=analogRead(SMOKE_PIN);Serial.println(v);bool smoke=v>=SMOKE_THRESHOLD;digitalWrite(LED_PIN,smoke?HIGH:LOW);digitalWrite(BUZZER_PIN,smoke?HIGH:LOW);delay(200);}
