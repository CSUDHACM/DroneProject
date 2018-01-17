//Created by Maria Perez — 2018.1.4
/*
 * Purpose of this is to have the lights go with the sounds.
 * Video: https://youtu.be/yYdAFnE6wA0
 */
 #include "pitches.h"

 #define RED 13
 #define GREEN 12
 #define BLUE 11
 
 
void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW); //Make these lights high and see what happens!                       ...it should be on right when you press play. no buttons necessary.
    digitalWrite(BLUE, LOW);
}

int twinkle_twinkle_little_star[] = {
  NOTE_G3, NOTE_G3, NOTE_D4, NOTE_D4, NOTE_E4,NOTE_E4, NOTE_D4
  };
int how_i_wonder_what_you[] = {
  NOTE_C4, NOTE_C4, NOTE_B3, NOTE_B3, NOTE_A3,NOTE_A3
};


  int duration = 400; //200 miliseconds 

void loop() {
  for(int note = 0; note <= 6 ; note++){
    tone(7, twinkle_twinkle_little_star[note], duration); //7 IS THE PIN LOCATION
    delay(500);
  }
  delay(300);
  for(int note = 0; note < 6; note++){
    tone(7, how_i_wonder_what_you[note], duration); //7 IS THE PIN LOCATION
    delay(500);
  }

  tone(7, NOTE_G3, 600);
  delay(2000);
}
