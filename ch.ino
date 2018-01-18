int ch1;
int ch2;
int ch3;
int ch4;

int turn;

void setup() 
{
  pinMode(5, INPUT); // Set input pin 5 as an input
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  Serial.begin(9600); // Pour a bowl of Serial
}

void loop() 
{
  ch1 = pulseIn(5, HIGH); // Read the pulse 
  ch2 = pulseIn(6, HIGH); 
  ch3 = pulseIn(7, HIGH); 
  ch4 = pulseIn(8, HIGH);
  
  if(ch1>1000)
  {
    Serial.println("Left Switch: Channel 1: Engaged");
    Serial.print("Channel 1 Value ");
    Serial.println(ch1);
  }
   
  if(ch1<1000)
  {
    Serial.println("Left Switch: Channel 1: Disengaged");
  }
  if(ch2>1000)
  {
    Serial.println("Left Switch: Channel 2: Engaged");
    Serial.print("Channel 2 Value ");
    Serial.println(ch2);
  }
  if(ch2<1000)
  {
    Serial.println("Left Switch: Channel 2: Disengaged");
  }
  if(ch3>1000)
  {
    Serial.println("Left Switch: Channel 3: Engaged");
    Serial.print("Channel 3 Value ");
    Serial.println(ch3);
  }
  if(ch3<1000)
  {
    Serial.println("Left Switch Channel 3: Disengaged");
  }
  if(ch4>1000)
  {
    Serial.println("Left Switch Channel 4: Engaged");
    Serial.print("Channel 4 Value ");
    Serial.println(ch4);
  }
  if(ch4<1000)
  {
    Serial.println("Left Switch Channel 4: Disengaged");
  }

  //Serial.println("Turn");
  

//Serial.print("Right Stick X:"); // Ch3 was x-axis 
//Serial.println(map(ch1, 1000,2000,-500,500)); // center at 0   ch 3

//Serial.print("Right Stick Y:"); // Ch2 was y-axis
//Serial.println(map(ch1, 1000,2000,-500,500)); // center at 0    ch 2

Serial.println(); //make some room

delay(1000);// I put this here just to make the terminal 
           // window happier
}
