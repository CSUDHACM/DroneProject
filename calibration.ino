// Author: Kevin R.
// Program: Calibrates 4 motor at once.

#include <Servo.h>

#define Max_Strength 2000
#define Min_Strength 1000
#define Min_Str 1050
#define MOTOR_PIN 9
#define MOTOR_PINB 7
#define MOTOR_PINC 5
#define MOTOR_PIND 3
int DELAY = 1000;

Servo motor;
Servo motorb;
Servo motorc;
Servo motord;

void setup() {
  Serial.begin(9600);
  Serial.println("Testing program script.");
  delay(1500);
  Serial.println("Program begin...");
  delay(1000);
  Serial.println("This program will start the ESC.");

  motor.attach(MOTOR_PIN);
  motorb.attach(MOTOR_PINB);
  motorc.attach(MOTOR_PINC);
  motord.attach(MOTOR_PIND);

  Serial.print("Now writing maximum output: (");
  Serial.print(Max_Strength);
  Serial.print(" us in this case)");
  Serial.print("\n");
  Serial.println("Turn on power source, then wait 2 seconds and press any key.");
  motor.writeMicroseconds(Min_Str);
  motorb.writeMicroseconds(Min_Str);
  motorc.writeMicroseconds(Min_Str);
  motord.writeMicroseconds(Min_Str);

  // Wait for input
  while (!Serial.available());
  
  Serial.read();

  // Send min output
  Serial.println("\n\n\n");
  Serial.print("Sending minimum output: (");
  Serial.print(Min_Strength);
  Serial.print(" us in this case)");
  Serial.print("\n");
  motor.writeMicroseconds(Min_Strength);
  motorb.writeMicroseconds(Min_Strength);
  motorc.writeMicroseconds(Min_Strength);
  motord.writeMicroseconds(Min_Strength);
  Serial.println("The ESC is calibrated");
  Serial.println("----");
  Serial.println("Now, type a values between 1000 and 2000 and press enter");
  Serial.println("and the motor will start rotating.");
  Serial.println("Send 1000 to stop the motor and 2000 for full throttle");

}

void loop() {
   
  if (Serial.available() > 0)
  {
    int DELAY = Serial.parseInt();
    if (DELAY > 999)
    {
      motor.writeMicroseconds(DELAY);
      motorb.writeMicroseconds(DELAY);
      motorc.writeMicroseconds(DELAY);
      motord.writeMicroseconds(DELAY);
      float SPEED = (DELAY-1000)/10;
      Serial.print("\n");
      Serial.println("Motor speed:"); 
      Serial.print("  "); 
      Serial.print(SPEED); 
      Serial.print("%"); 
    }     
  }
}
