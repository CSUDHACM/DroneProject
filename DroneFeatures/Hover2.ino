#include <Servo.h>
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long distance;
int ch1;
int ch2;
int ch3 = 1100;
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
  motor.writeMicroseconds(ch3);
  distance = sr04.Distance();

  if (distance < 15) {
    Serial.println("Not high enough!");
    //    ch3+=50;
    ch3 = 1900;
    //motor.writeMicroseconds(1900);
    //delay(500);

    //   distance = sr04.Distance();
    //   int current = 2000;
    //   for(int i = current; i > 1500; i--){
    //      motor.writeMicroseconds(i);
    //
    //   }



  }
  if (distance > 15) {
    Serial.print("Ch3: ");
    Serial.print(ch3);
    Serial.print("  |  "); Serial.print(" Distance: "); Serial.print(distance); Serial.print("\n");
    //    ch3-=10;
    ch3 = 1800;
    //motor.writeMicroseconds(1900);
    //delay(500);
  }
  delay(1000);


}
