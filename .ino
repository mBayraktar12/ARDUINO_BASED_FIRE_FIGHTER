//FINAL
#define RM1 6
#define RM2 7
#define RME 9
#define Left_S 11
#define Forward_S 10
#define Right_S 12
#define LM1 5
#define LM2 4
#define LME 3
boolean fire =false;

void setup() 
{ 
pinMode(Left_S, INPUT);
pinMode(Forward_S, INPUT);
pinMode(Right_S, INPUT);
pinMode(RM1,OUTPUT); 
pinMode(RM2,OUTPUT); 
pinMode(LM1,OUTPUT); 
pinMode(LM2,OUTPUT); 
}
void put_off_fire()
{
    delay (500);
 
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(LME, 0);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RME, 0);
    
  fire=false;
}
 
void loop()
{
 
  if (digitalRead(Left_S) ==1 && digitalRead(Right_S)==1 && digitalRead(Forward_S) ==1) //If Fire not detected all sensors are zero
    {
    //Do not move the robot
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(LME, 0);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RME, 0);
    }
    
    else if (digitalRead(Forward_S) ==0) //If Fire is straight ahead
    {
    //Move the robot forward
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(LME, 150);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RME ,150);
    fire = true;
 
    }
    
    else if (digitalRead(Left_S) ==0) //If Fire is to the left
    {
    //Move the robot left
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(LME, 0);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RME, 150);
    fire==true;

    }
    
    else if (digitalRead(Right_S) ==0) //If Fire is to the right
    {
    //Move the robot right
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(LME, 150);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RME, 0);
   fire==true;
    }
    
delay(700); //change this to set the distance 
 
     while (fire == true)
     {
      put_off_fire();
     }
}
