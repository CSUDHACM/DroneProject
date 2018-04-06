#include <CoDrone.h>

void setup() {
  CoDrone.begin(115200);
  CoDrone.AutoConnect(NearbyDrone); //Creates connection to Nearby Drone
  CoDrone.DroneModeChange(Flight);  //Sets control to Drone mode
  CoDrone.FlightEvent(TakeOff);     //Drone takes off for 2 seconds
  delay(2000);
  CoDrone.FlightEvent(Landing);     //Drone lands
  //delay(500);
  //CoDrone.LedColor(EyeHold, Gold); //Changes color of the eye to Gold
}

void loop() {
  byte Sen11 = digitalRead(11);   //Checks the sensors for input (Covering said sensors gives input)
  byte Sen14 = digitalRead(14);
  byte Sen18 = digitalRead(18);

  if(Sen11 && Sen18) { //Emergency stop 
    CoDrone.FlightEvent(Stop);
    CoDrone.Buzz(8000,2);
  }
  else if(Sen11) {
    CoDrone.FlightEvent(Landing); //Lands Drone if Sensor 11 has an input.
  }
  else if(Sen18) { 
    rotate();
  }    

  if (PAIRING == true) //Takes input from left and right analog sticks for flight control.
  {
    YAW = -1 * CoDrone.AnalogScaleChange(analogRead(A3)); 
    THROTTLE  = CoDrone.AnalogScaleChange(analogRead(A4)); 
    ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(A5)); 
    PITCH = CoDrone.AnalogScaleChange(analogRead(A6)); 
    CoDrone.Control(SEND_INTERVAL); //Sends analog input to the drone for execution.
  }
}

void rotate() { //Maria Perez Method
  for(int i = 0; i < 4; i++) {
    YAW = 90;
    delay(250);
  }
  CoDrone.Control();
}
