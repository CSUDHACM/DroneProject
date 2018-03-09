#include <Servo.h>
int ch1;
int ch2;
int ch3;
int ch4;

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
int turn;

void setup() 
{
//  pinMode(7, INPUT); // Set input pin 5 as an input
//  pinMode(6, INPUT);
  pinMode(5, INPUT);
  //pinMode(4, INPUT);
  Serial.begin(9600); // Pour a bowl of Serial

  motor1.attach(7);
  motor2.attach(6);
  motor3.attach(5);
  motor4.attach(4);

  motor1.writeMicroseconds(1000); // code, so the motors dont spin when the lipo battery is connected
  motor2.writeMicroseconds(1000); 
  motor3.writeMicroseconds(1000);
  motor4.writeMicroseconds(1000);
  
}

void loop() 
{
  //ch1 = pulseIn(8, HIGH); // Read the pulse 
  //ch2 = pulseIn(9, HIGH); 
  ch3 = pulseIn(10, HIGH); 
  //ch4 = pulseIn(11, HIGH);
  
  Serial.print("Ch3: ");
  Serial.print(ch3);
  Serial.print("  |  ");
  motor1.writeMicroseconds(ch3);
  motor2.writeMicroseconds(ch3);
  motor3.writeMicroseconds(ch3);
  motor4.writeMicroseconds(ch3);
  Serial.print("\n");

  
}
