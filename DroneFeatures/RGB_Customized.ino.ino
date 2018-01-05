//www.elegoo.com
//2016.12.8

//Customized by: Mara Perez

//Purpose of this customized program is to allow the user to shut off the LED after the 3 color loop is done.
//This uses LESSONS 4 and 5
//BUTTONA starts the lghtshow
//BUTTONB ends it.

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 7

int BUTTONA = 11;
int BUTTONB = 13;
byte leds = 0;

void setup()
{
pinMode(BUTTONA, INPUT_PULLUP);
pinMode(BUTTONB, INPUT_PULLUP);
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED, LOW);
digitalWrite(GREEN, LOW); //Make these lights high and see what happens!                       ...it should be on right when you press play. no buttons necessary.
digitalWrite(BLUE, LOW);
}

// define variables
int redValue;
int greenValue;
int blueValue;

// main loop
void loop()
{
  if(digitalRead(BUTTONA) == LOW){
    
    
    #define delayTime 10 // fading time between colors
    
    
    for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
    {
    redValue -= 1;
    greenValue += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(RED, 255 - redValue);
    // analogWrite(GREEN, 255 - greenValue);
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(delayTime);
    }
    
    redValue = 0;
    greenValue = 255;
    blueValue = 0;
    
    for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
    {
    greenValue -= 1;
    blueValue += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(GREEN, 255 - greenValue);
    // analogWrite(BLUE, 255 - blueValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
    }
    
    redValue = 0;
    greenValue = 0;
    blueValue = 255;
    
    for(int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
    {
    // The following code has been rearranged to match the other two similar sections
    blueValue -= 1;
    redValue += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(BLUE, 255 - blueValue);
    // analogWrite(RED, 255 - redValue);
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(delayTime);
  }
 
    }

    if (digitalRead(BUTTONB) == LOW){
      
     // delay(100); NEVER HAVE IT DELAY CONSTANTLY. Reason: The colors will run after 100 ticks. If you spam the button, there will be a possibility that the bulb will blow. or something else will
        digitalWrite(BLUE, LOW); //having the powers on low will turn off the lights.
        digitalWrite(GREEN, LOW);
        digitalWrite(RED, LOW);
        }
}

