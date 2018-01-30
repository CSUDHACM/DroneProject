#include <CoDrone.h>

void setup() {
 CoDrone.begin(115200);
 CoDrone.AutoConnect(NearbyDrone);

}

void loop() {
  // put your main code here, to run repeatedly:
    if(digitalRead(18)){
      CoDrone.FlightEvent(TakeOff);
      delay(250);
      CoDrone.Control();
    }
    if(digitalRead(11)&&digitalRead(18)){
      CoDrone.FlightEvent(Landing);
    }
    if(digitalRead(11)&&digitalRead(14)&&digitalRead(18)){
      CoDrone.FlightEvent(Stop);
    }
}
