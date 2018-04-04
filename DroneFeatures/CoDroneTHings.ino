#include <CoDrone.h>
/*
 * Created by Maria Perez [2017 - 2018]
 * Edited by:
 *
 */

void setup() {
  CoDrone.begin(115200);
  CoDrone.AutoConnect(NearbyDrone); //connects the drone
}

void loop() {
  ///////////////The Start Up///////////////
 if(digitalRead(18)){  //Turns on Drone
    CoDrone.FlightEvent(TakeOff);
    delay(250);
    CoDrone.Control(); //stabilizes 
 }

 ///////////////Analog Stick Part///////////////  
  if(PAIRING == true){//checks if drone is connected to the controller
  
  YAW = -1 * CoDrone.AnalogScaleChange(analogRead(22)); //normally analog read returns a number from 0 ~ 1023
  ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(24)); //thevariables YAW,THROTTLE, ETC
  PITCH = CoDrone.AnalogScaleChange(analogRead(25));    //only accepts numbers from -100~100
  THROTTLE = CoDrone.AnalogScaleChange(analogRead(23)); //scale change scales the number down to -100 ~ 100
  CoDrone.Control(SEND_INTERVAL);
  }
 ///////////////IS SENSORS ON BACK/////////////// 
  if(digitalRead(11)){ //Left Sensor turns on device
    CoDrone.FlightEvent(Landing);
  }

  if(digitalRead(12)){//spins if you hold the 12 sensor
   for(int i = 0; i < 4; i++){
      YAW = 90;//with the speed of 90
      delay(250);// 1/4 OF A SECOND
    }
    CoDrone.Control();
  }

  if(digitalRead(11) && digitalRead(14) && digitalRead(18)){//emergency off switch
    CoDrone.FlightEvent(Stop); 
  }
  
 /* if(digitalRead(17)){//goes down [[ IN CONSTRUCTION ]]
      THROTTLE = -90;
      delay(250);
      CoDrone.Control();
    }
  */
 ///////////////LED Fun/////////////// [[ in progress ]]
/*if(millis() - setTime){
  Serial.print(millis());
  Serial.print(":  ");
  if(colorFlag == 0){
    Serial.println("Color to Blue");
    //coDrone.LedColor(ArmDimming, White, 10);
    //CoDrone.LedColor(mode, color, time interval);
    //CoDrone.LedColor(mode, R,G,B, time interval);
    colorFlag = 1;
  }
  else if(colorFlag == 1){
    Serial.println("Color to Red");
    colorFlag = 0;
  }
  setTime = millis();
}
*/

}


