const int MQ2_PIN=A0,FAN_IN1=8,FAN_IN2=9,FAN_THRESHOLD=450;
void stopFan();void startFan();
void setup(){pinMode(FAN_IN1,OUTPUT);pinMode(FAN_IN2,OUTPUT);stopFan();Serial.begin(9600);}
void loop(){int v=analogRead(MQ2_PIN);Serial.println(v);if(v>=FAN_THRESHOLD)startFan();else stopFan();delay(200);}
void startFan(){digitalWrite(FAN_IN1,HIGH);digitalWrite(FAN_IN2,LOW);}void stopFan(){digitalWrite(FAN_IN1,LOW);digitalWrite(FAN_IN2,LOW);}
