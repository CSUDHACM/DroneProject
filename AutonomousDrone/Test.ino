#include <CoDrone.h>



void setup(){
  
  CoDrone.begin(115200);
  CoDrone.AutoConnect(NearbyDrone);
  
  
  CoDrone.FlightEvent(TakeOff);
  delay(9000);
  CoDrone.FlightEvent(Landing);
  
}
6
void loop(){
  //CoDrone.FlightEvent(Landing);
}
