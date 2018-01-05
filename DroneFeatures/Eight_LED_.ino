//www.elegoo.com
//2016.12.9 
//modified code from elegoo arduino kit, 1/4/2018
//Author: Esther
//LEDs on even positions turn on first, then LEDs on odd positions turn on next
//materials used: arduino uno, 8 LEDs, 8 resistors, 74HC595 chip, breadboard

int tDelay = 100;
int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595

byte leds = 0;

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  leds = 0;
  updateShiftRegister();
  delay(tDelay);
  for (int i = 0; i < 8; i++)   //turns on LEDS at even positions, 0,2,4,6
  {
    if(i % 2 == 0)
    {
    bitSet(leds, i);
    updateShiftRegister();
    delay(tDelay);
    }
  }

   delay(10);       //wait 10ms
  
  for(int j = 0; j < 8; j++)    //turns on LEDS at odd positions, 1,3,5,7
  {
    if(j % 2 != 0)
    {
      bitSet(leds, j);
      updateShiftRegister();
      delay(tDelay);
    }
  }
}

