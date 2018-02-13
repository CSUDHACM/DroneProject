
#include <CoDrone.h>
/*
 * Created by Maria Perez [2017 - 2018]
 * Modified By:
 * 
 * Uses COM 7 & Rokit-SmartInventor-mega32_v2
 */

void setup() {
  CoDrone.begin(115200);
  CoDrone.AutoConnect(NearbyDrone); //connects the drone
}

void loop() {
startUP();
irSensors();
analogStick(); 
//ledFun();
}
void irSensors(){
  ///////////////IR SENSORS ON BACK/////////////// 
  if(digitalRead(11)){ //Left Sensor turns on device
    CoDrone.FlightEvent(Landing);
  }

  if(digitalRead(12)){//spins if you hold the 12 sensor
   for(int i = 0; i < 4; i++){
      YAW = 90;//with the speed of 90
      delay(250);// 1/4       OF A SECOND
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
}
 

void analogStick(){
  
 ///////////////Analog Stick Part///////////////  
  if(PAIRING == true){//checks if drone is connected to the controller
  YAW = -1 * CoDrone.AnalogScaleChange(analogRead(25)); //normally analog read returns a number from 0 ~ 1023
  THROTTLE = CoDrone.AnalogScaleChange(analogRead(24)); //scale change scales the number down to -100 ~ 100
  ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(22)); //thevariables YAW,THROTTLE, ETC
  PITCH = CoDrone.AnalogScaleChange(analogRead(23));    //only accepts numbers from -100~100
  CoDrone.Control();
  }
  
}
void startUP(){

  ///////////////The Start Up///////////////
 if(digitalRead(18)){  //Turns on Drone
    CoDrone.FlightEvent(TakeOff);
    delay(250);
    CoDrone.Control(); //stabilizes 
 }
}
void ledFun(){
   
  /*
 ///////////////LED Fun/////////////// [[ in progress ]]
 
 for(int i: 255)
  CoDrone.LedColor(mode, i, 1, 1, 5);
 for(int i: 255)
  CoDrone.LedColor(mode, 1, i, 1, 5);
 for(int i: 255)
  CoDrone.LedColor(mode, 1, 1, i, 5); 
 for(int i: 255)
  CoDrone.LedColor(mode, i, 1, 1, 5);
if(millis() - setTime){
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

