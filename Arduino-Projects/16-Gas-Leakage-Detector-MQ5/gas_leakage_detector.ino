const int GAS_PIN=A0,LED_PIN=8,BUZZER_PIN=9,GAS_THRESHOLD=450;
void setup(){pinMode(LED_PIN,OUTPUT);pinMode(BUZZER_PIN,OUTPUT);Serial.begin(9600);}
void loop(){int v=analogRead(GAS_PIN);Serial.println(v);bool alarm=v>=GAS_THRESHOLD;digitalWrite(LED_PIN,alarm?HIGH:LOW);digitalWrite(BUZZER_PIN,alarm?HIGH:LOW);delay(200);}
