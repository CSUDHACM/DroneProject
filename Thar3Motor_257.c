// Author: Thar 
// Program: Calibrates 3 motors at that same time.


#include <Servo.h>

#define MAX_SIGNAL 2000
#define MIN_SIGNAL 1000
#define MY_Min 1063
#define MOTOR_PIN2 2
#define MOTOR_PIN5 5
#define MOTOR_PIN7 7
int DELAY = 1000;

Servo motor2; // motor with motor pin 2
Servo motor5; // motor with motor pin 5
Servo motor7; // motor with motor pin 7

void setup() {
  Serial.begin(9600);
  Serial.println("ELECTRONOOBS ESC calibration...");
  Serial.println(" ");
  delay(1500);
  Serial.println("Program begin...");
  delay(1000);
  Serial.println("This program will start the ESC.");

  motor2.attach(MOTOR_PIN2);
  motor5.attach(MOTOR_PIN5);
  motor7.attach(MOTOR_PIN7); 

  Serial.print("Now writing maximum output: (");
  Serial.print(MAX_SIGNAL);Serial.print(" us in this case)");
  Serial.print("\n");
  Serial.println("Turn on power source, then wait 2 seconds and press any key.");
  motor2.writeMicroseconds(MY_Min);
  motor5.writeMicroseconds(MY_Min);
  motor7.writeMicroseconds(MY_Min);


  // Wait for input
  while (!Serial.available());
  
  Serial.read();

  // Send min output
  Serial.println("\n");
  Serial.println("\n");
  Serial.print("Sending minimum output: (");
  Serial.print(MIN_SIGNAL);
  Serial.print(" us in this case)");
  Serial.print("\n");
  motor2.writeMicroseconds(MIN_SIGNAL);
  motor5.writeMicroseconds(MIN_SIGNAL);
  motor7.writeMicroseconds(MIN_SIGNAL);

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
      
      motor2.writeMicroseconds(DELAY);
      motor5.writeMicroseconds(DELAY);
      motor7.writeMicroseconds(DELAY);

      float SPEED = (DELAY-1000)/10;
      Serial.print("\n");
      Serial.println("Motor speed:"); Serial.print("  "); Serial.print(SPEED); Serial.print("%"); 
    }     
  }
}
