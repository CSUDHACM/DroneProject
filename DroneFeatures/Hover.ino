#include <Servo.h>
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long distance;
int ch1;
int ch2;
int ch3 = 1500;
int ch4;

Servo motor;
int turn;

void setup() 
{
  //pinMode(5, INPUT); // Set input pin 5 as an input
  //pinMode(6, INPUT);
  pinMode(8, INPUT);
  //pinMode(8, INPUT);
  Serial.begin(9600); // Pour a bowl of Serial

  motor.attach(8);
}

void loop() 
{
  distance = sr04.Distance();
  if(distance < 30) {
    Serial.println("Not high enough!");
    motor.writeMicroseconds(1900);
  }
  //ch1 = pulseIn(5, HIGH); // Read the pulse 
  //ch2 = pulseIn(6, HIGH); 
  //ch3 = pulseIn(7, HIGH); 
  //ch4 = pulseIn(8, HIGH);
  else {
  Serial.print("Ch3: ");
  Serial.print(ch3);
  Serial.print("  |  ");
  motor.writeMicroseconds(ch3);
  Serial.print("\n");
  }
  
}
