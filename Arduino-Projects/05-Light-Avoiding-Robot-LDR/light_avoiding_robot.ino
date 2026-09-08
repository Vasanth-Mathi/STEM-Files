/* Light Avoiding Robot Using LDR Sensors */
const int LEFT_LDR=A0, RIGHT_LDR=A1;
const int LEFT_IN1=8, LEFT_IN2=9, RIGHT_IN1=10, RIGHT_IN2=11;
const int BRIGHT_THRESHOLD=600, DIFFERENCE=60;
void stopRobot(); void moveForward(); void moveBackward(); void turnLeft(); void turnRight();
void setup(){pinMode(LEFT_IN1,OUTPUT);pinMode(LEFT_IN2,OUTPUT);pinMode(RIGHT_IN1,OUTPUT);pinMode(RIGHT_IN2,OUTPUT);stopRobot();}
void loop(){int l=analogRead(LEFT_LDR),r=analogRead(RIGHT_LDR);if(l>BRIGHT_THRESHOLD&&r>BRIGHT_THRESHOLD)moveBackward();else if(l>r+DIFFERENCE)turnRight();else if(r>l+DIFFERENCE)turnLeft();else moveForward();delay(50);}
void moveForward(){digitalWrite(LEFT_IN1,HIGH);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,HIGH);digitalWrite(RIGHT_IN2,LOW);}
void moveBackward(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,HIGH);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,HIGH);}
void turnLeft(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,HIGH);digitalWrite(RIGHT_IN2,LOW);}
void turnRight(){digitalWrite(LEFT_IN1,HIGH);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,LOW);}
void stopRobot(){digitalWrite(LEFT_IN1,LOW);digitalWrite(LEFT_IN2,LOW);digitalWrite(RIGHT_IN1,LOW);digitalWrite(RIGHT_IN2,LOW);}
