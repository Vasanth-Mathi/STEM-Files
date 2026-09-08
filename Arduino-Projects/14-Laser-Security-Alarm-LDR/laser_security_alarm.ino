const int LDR_PIN=A0,BUZZER_PIN=9,LASER_THRESHOLD=600;
void setup(){pinMode(BUZZER_PIN,OUTPUT);}
void loop(){int v=analogRead(LDR_PIN);digitalWrite(BUZZER_PIN,v<LASER_THRESHOLD?HIGH:LOW);delay(50);}
