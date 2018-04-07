#include <CoDrone.h>

void setup() {
  CoDrone.begin(115200);
  CoDrone.AutoConnect(NearbyDrone); //Creates connection to Nearby Drone
  CoDrone.Buzz(4000,1);
  CoDrone.DroneModeChange(Flight);  //Sets control to Drone mode
//  CoDrone.FlightEvent(TakeOff);     //Drone takes off for 2 seconds
//  CoDrone.FlightEvent(Landing);     //Drone lands
}

void loop() {
//  byte Sen11 = digitalRead(11);   //Checks the sensors for input (Covering said sensors gives input)
//  byte Sen14 = digitalRead(14);
//  byte Sen18 = digitalRead(18);

  irSensors();

  if(digitalRead(11)) { //Emergency stop 
    CoDrone.FlightEvent(Stop);
    CoDrone.Buzz(8000,1);
    CoDrone.Control(SEND_INTERVAL); //Sends analog input to the drone for execution.
  }
//  else if(digitalRead(18)) {  //Maria Perez Segment of code.
//    for(int i = 0; i < 4; i++) {  
//      YAW = 90;
//      delay(250);
//    }
//    CoDrone.Control();
//  }                 //End of Maria Perez Segment.

  else if (PAIRING == true) //Takes input from left and right analog sticks for flight control.
  {
    YAW = -1 * CoDrone.AnalogScaleChange(analogRead(A3)); 
    THROTTLE  = CoDrone.AnalogScaleChange(analogRead(A4)); 
    ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(A5)); 
    PITCH = CoDrone.AnalogScaleChange(analogRead(A6)); 
    CoDrone.Control(SEND_INTERVAL); //Sends analog input to the drone for execution.
    
    
  }
}
void irSensors(){
  ///////////////IR SENSORS ON BACK/////////////// 

  if(digitalRead(12)){//spins if you hold the 12 sensor
   for(int i = 0; i < 4; i++){
      YAW = 90;//with the speed of 90
      delay(250);// 1/4       OF A SECOND
    }
    
  }
CoDrone.Control(SEND_INTERVAL); //Sends analog input to the drone for execution.
  
}
