#include <Servo.h>
int ch1;
int ch2;
int ch3;
int ch4;

Servo motor;
int turn;

void setup() 
{
  //pinMode(5, INPUT); // Set input pin 5 as an input
  //pinMode(6, INPUT);
  pinMode(7, INPUT);
  //pinMode(8, INPUT);
  Serial.begin(9600); // Pour a bowl of Serial

  motor.attach(9);
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
  Serial.print("\n");

  
}
