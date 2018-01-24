#include <Servo.h>
int ch1;
int ch2;
int ch3;
int ch4;

Servo motor;
Servo motorB;
Servo motorC;
Servo motorD;
int turn;

void setup() 
{
 pinMode(8, INPUT); // Set input pin 8 as an input
  pinMode(9, INPUT); //Attaching the pins
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  Serial.begin(9600); // Pour a bowl of Serial

  motor.attach(9);
   motorB.attach(9); // attaching pins
  motorC.attach(10);
  motorD.attach(11);
}

void loop() 
{
  //ch1 = pulseIn(5, HIGH); // Read the pulse 
  //ch2 = pulseIn(6, HIGH); 
  ch3 = pulseIn(7, HIGH); 
  //ch4 = pulseIn(8, HIGH);
  
  Serial.print("Ch3: ");
  Serial.print(ch3);
  Serial.print("  |  ");
  motor.writeMicroseconds(ch3);
  motorB.writeMicroseconds(ch3); // Attaching motors to the input
  motorC.writeMicroseconds(ch3);
  motorD.writeMicroseconds(ch3);
  Serial.print("\n");

  
}
