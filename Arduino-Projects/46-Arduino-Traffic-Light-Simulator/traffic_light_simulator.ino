const int RED_LED=8,YELLOW_LED=9,GREEN_LED=10;
void setLights(bool r,bool y,bool g){digitalWrite(RED_LED,r);digitalWrite(YELLOW_LED,y);digitalWrite(GREEN_LED,g);}
void setup(){pinMode(RED_LED,OUTPUT);pinMode(YELLOW_LED,OUTPUT);pinMode(GREEN_LED,OUTPUT);}
void loop(){setLights(LOW,LOW,HIGH);delay(5000);setLights(LOW,HIGH,LOW);delay(2000);setLights(HIGH,LOW,LOW);delay(5000);}
