const int playerButtons[4]={2,3,4,5};const int playerLEDs[4]={6,7,8,9};const int BUZZER_PIN=10,RESET_PIN=11;int winner=-1;
void clearRound(){winner=-1;for(int i=0;i<4;i++)digitalWrite(playerLEDs[i],LOW);digitalWrite(BUZZER_PIN,LOW);}
void setup(){for(int i=0;i<4;i++){pinMode(playerButtons[i],INPUT_PULLUP);pinMode(playerLEDs[i],OUTPUT);}pinMode(BUZZER_PIN,OUTPUT);pinMode(RESET_PIN,INPUT_PULLUP);clearRound();}
void loop(){if(digitalRead(RESET_PIN)==LOW){clearRound();while(digitalRead(RESET_PIN)==LOW)delay(10);delay(100);}if(winner==-1){for(int i=0;i<4;i++){if(digitalRead(playerButtons[i])==LOW){winner=i;digitalWrite(playerLEDs[i],HIGH);digitalWrite(BUZZER_PIN,HIGH);delay(300);digitalWrite(BUZZER_PIN,LOW);break;}}}}
