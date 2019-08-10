
//      ******************************************************************
//      *                                                                *
//      *      Arduino program light display for the LED sculpture       *
//      *                                                                *
//      *          Jose Peralta          4/11/13                         *
//      *                                                                *
//      ******************************************************************

#include "Fade.h"
Fade fade;


//
// top level setup function
//
void setup()
{  
  int pinNum;

  //
  // configure the LED pins as outputs
  //
  for(pinNum = 2; pinNum <= 15; pinNum++)
  {
    pinMode(pinNum, OUTPUT); 
  } 
}



//
// select the displays using the position of the knob
//
void loop()
{ 
  int knobZoneNumber;

  //
  // get the zone number that the knob is in:
  //  0 = off, 1 = light show, 2 = background, 3 = nightlight
  //
  knobZoneNumber = fade.getKnobPosition();

  //
  // run the light show if knob in zone 1
  //
  if (knobZoneNumber == 1)
  {
    runLightShow();
  }

  //
  // run the background show if knob in zone 2
  //
  if (knobZoneNumber == 2)
  {
    runBackgroundDisplays();
  }

  //
  // run the nightlight if knob in zone 3
  //
  if (knobZoneNumber == 3)
  {
    fade.nightLightModeWhileInZoneThree();
  }
}


//
// run the "Light Show" while the knob is in zone 1
//
void runLightShow()
{
  ShowAllTheColors();
  delay(800);  
  if (fade.getKnobPosition() != 1) return;    // return if not in lightshow mode

  SlowlyBlinkEachLedOneAtATime();
  delay(800);  
  if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode

  //
  //my programs
  //

  Propellor();
  delay(800);
  if (fade.getKnobPosition() != 1) return;

  BlinkInACircleForwardsAndBackwards();
  delay(800);
  if (fade.getKnobPosition() != 1) return;

  BlinkTwoSidesThenTheOtherTwoSides();
  delay(800);
  if (fade.getKnobPosition() != 1) return;

  SmallMediumBigCircles();
  delay(800);
  if (fade.getKnobPosition() != 1) return;

  AllSidesOutThenIn();
  delay(800);
  if (fade.getKnobPosition() != 1) return;

  BackwarsdsPropellor();
  delay(800);
  if (fade.getKnobPosition() != 1) return;

  //
  //fading
  //
  FunWIthFading();
  delay(800);
  if (fade.getKnobPosition() != 1) return;

  delay(2000);  
}



//
// run the "Background Show" while the knob is in zone 2
//
void runBackgroundDisplays()
{
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode
  fadeUpAndDownOneLEDAtATime();
  delay(800);  
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode

  fadeUpAndDownRightAndLeft();
  delay(800);  
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode

  FunWIthFading2();
  delay(800);
  if (fade.getKnobPosition() != 2) return;

  AllSidesOutThenIn2();
  delay(800);
  if (fade.getKnobPosition() != 2) return;

  delay(2000);  

}


//------------------------------------------------------------------------
//                        Light show displays
//------------------------------------------------------------------------

void ShowAllTheColors()
{ 
  int pinNumber;

  //
  // turn on all the yellows
  //
for(pinNumber=2; pinNumber <=15; pinNumber++)
{
  digitalWrite(pinNumber, LOW); 
  
  }
  digitalWrite(5, HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(8, HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(11, HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(14,HIGH);
  if (fade.getKnobPosition() != 1) return;
  delay(1000);
  if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode

  //
  // turn on all the reds
  //
  digitalWrite(4, HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(7, HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(10, HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(13, HIGH);
  if (fade.getKnobPosition() != 1) return;
  delay(1000);
  if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode

  //
  // turn on all the oranges
  //
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(3, HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(6, HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(9, HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(12, HIGH);
  if (fade.getKnobPosition() != 1) return;
  delay(1000);
  if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode

  //
  //turn on the last yellow 
  //
  digitalWrite(2,HIGH);
  if (fade.getKnobPosition() != 1) return;
  delay(1000);
  if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode

  //
  // now turn all the LEDs off
  //
  for(pinNumber = 2; pinNumber <= 15; pinNumber++)
  { 
    digitalWrite(pinNumber, LOW);
    if (fade.getKnobPosition() != 1) return;
  }
}



void   SlowlyBlinkEachLedOneAtATime()
{
  int count;
  int pinNumber;


  //
  // turn on the LEDs, one at a time, in an order that looks good for your sculpture
  //


  for(count = 1; count <= 2; count++)
  {
    for(pinNumber = 2; pinNumber <= 15; pinNumber++)
    { 
      digitalWrite(pinNumber, HIGH);
      delay(250);
      if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode
    }
  }
  for(pinNumber = 2; pinNumber <= 15; pinNumber++)
  { 
    digitalWrite(pinNumber, LOW);
    if (fade.getKnobPosition() != 1) return;   // return if not in lightshow mode
  }
}

//
//my programs
//

void Propellor()
{

  int count;

  //
  //propellor clockwise 
  //
  digitalWrite(2,HIGH);
  if (fade.getKnobPosition() != 1) return;
  delay(500);
  for(count =1; count <= 10; count ++)
  {
    BlinkThree(3);
    BlinkThree(6);
    BlinkThree(9);
    BlinkThree(12);
    if (fade.getKnobPosition() != 1) return;
  }
}

void BlinkThree(int L1)
//
//sets of three
//
{
  digitalWrite(L1,HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(L1+1,HIGH);
  digitalWrite(L1+2,HIGH);
  delay(100);
  digitalWrite(L1,LOW);
  digitalWrite(L1+1,LOW);
  digitalWrite(L1+2,LOW);
  if (fade.getKnobPosition() != 1) return;
}

void BlinkInACircleForwardsAndBackwards()
{
  //
  //LEDS turn on in a circle clockwise, then off counterclockwise
  //
  int t=500; //delay time for LED 2 is different
  int y=50; 
  int count;
  for(count=1;count<=10;count++)
  {
    digitalWrite(2,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(t);
    digitalWrite(3,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(6,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(9,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(12,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(4,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(7,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(10,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(13,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(5,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(8,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(11,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(14,HIGH);
    if (fade.getKnobPosition() != 1) return;


    delay(t);
    digitalWrite(14,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(11,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(8,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(5,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(13,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(10,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(7,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(4,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(12,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(9,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(6,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(3,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(2,LOW);
    if (fade.getKnobPosition() != 1) return;
  }

  digitalWrite(2,LOW);

}

void BlinkTwoSidesThenTheOtherTwoSides()
{ 
  //
  //2 sets of three LEDs turn on, then turn off and the other 2 sets turn on 
  //
  int count;
  for(count=1; count <=5; count++)
  {
    int t=500;
    int y=100;

    digitalWrite(2,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(t);
    digitalWrite(3,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(9,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(4,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(10,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(5,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(11,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(750);
    digitalWrite(11,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(5,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(10,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(4,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(9,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(3,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(2,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(t);
    digitalWrite(6,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(12,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(7,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(13,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(8,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(14,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(750);
    digitalWrite(14,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(8,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(13,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(7,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(12,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(6,LOW);
    if (fade.getKnobPosition() != 1) return;

  }
}

void SmallMediumBigCircles()
{
  //
  //start with orange circle, then red circle then yellow circle
  //
  int t=50;
  int count;

  digitalWrite(2,HIGH);
  if (fade.getKnobPosition() != 1) return;
  delay(500);

  for(count=1; count <=5;count ++)
  {
    //
    //orange circle
    //
    for(count=1;count<=10;count++)
    {
      digitalWrite(3,HIGH);
      if (fade.getKnobPosition() != 1) return;
      delay(t);
      digitalWrite(3,LOW);
      if (fade.getKnobPosition() != 1) return;
      digitalWrite(6,HIGH);
      if (fade.getKnobPosition() != 1) return;
      delay(t);
      digitalWrite(6,LOW);
      if (fade.getKnobPosition() != 1) return;
      digitalWrite(9,HIGH);
      if (fade.getKnobPosition() != 1) return;
      delay(t);
      digitalWrite(9,LOW);
      if (fade.getKnobPosition() != 1) return;
      digitalWrite(12,HIGH);
      if (fade.getKnobPosition() != 1) return;
      delay(t);
      digitalWrite(12,LOW);
      if (fade.getKnobPosition() != 1) return;
      digitalWrite(3,HIGH);
      if (fade.getKnobPosition() != 1) return;
      delay(t);
      digitalWrite(3,LOW);
      if (fade.getKnobPosition() != 1) return;

    }


    //
    //red circle
    //
    for(count=1;count<=10;count++)
    {
      digitalWrite(4,HIGH);
      if (fade.getKnobPosition() != 1) return;
      delay(t);
      if (fade.getKnobPosition() != 1) return;
      digitalWrite(4,LOW);
      if (fade.getKnobPosition() != 1) return;
      digitalWrite(13,HIGH);
      if (fade.getKnobPosition() != 1) return;
      delay(t);
      digitalWrite(13,LOW);
      if (fade.getKnobPosition() != 1) return;
      digitalWrite(10,HIGH);
      if (fade.getKnobPosition() != 1) return;
      delay(t);
      digitalWrite(10,LOW);
      if (fade.getKnobPosition() != 1) return;
      digitalWrite(7,HIGH);
      if (fade.getKnobPosition() != 1) return;
      delay(t);
      digitalWrite(7,LOW);
      if (fade.getKnobPosition() != 1) return;
    }
  }
  //
  //yellow circle
  //
  for(count=1;count<=10;count++)
  {
    digitalWrite(5,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(70);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(5,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(8,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(70);
    digitalWrite(8,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(11,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(70);
    digitalWrite(11,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(14,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(70);
    digitalWrite(14,LOW);
    if (fade.getKnobPosition() != 1) return;
  }
  digitalWrite(2,LOW);
  if (fade.getKnobPosition() != 1) return;
}


void AllSidesOutThenIn()
{
  int count;
  int t=500;
  int y=50;
  for(count=1;count<=10;count++)
  {
    digitalWrite(2,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(3,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(6,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(9,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(12,HIGH);
    delay(y);
    digitalWrite(4,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(7,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(10,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(13,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(5,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(8,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(11,HIGH);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(14,HIGH);
    if (fade.getKnobPosition() != 1) return;
    delay(t);
    digitalWrite(14,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(11,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(8,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(5,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(13,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(10,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(7,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(4,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(y);
    digitalWrite(12,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(9,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(6,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(3,LOW);
    if (fade.getKnobPosition() != 1) return;
    digitalWrite(2,LOW);
    if (fade.getKnobPosition() != 1) return;
    delay(300);   
  }
}

void BackwarsdsPropellor()
{

  int count;

  //
  //propellor counterclockwise 
  //
  digitalWrite(2,HIGH);
  if (fade.getKnobPosition() != 1) return;
  delay(500);
  for(count =1; count <= 10; count ++)
  {
    BlinkThree2(3);
    if (fade.getKnobPosition() != 1) return;
    BlinkThree2(12);
    if (fade.getKnobPosition() != 1) return;
    BlinkThree2(9);
    if (fade.getKnobPosition() != 1) return;
    BlinkThree2(6);
    if (fade.getKnobPosition() != 1) return;
  }
  digitalWrite(2,LOW);
  if (fade.getKnobPosition() != 1) return;
}

void BlinkThree2(int L1)
//
//sets of three
//
{ 
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(L1,HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(L1+1,HIGH);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(L1+2,HIGH);
  if (fade.getKnobPosition() != 1) return;
  delay(100);
  digitalWrite(L1,LOW);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(L1+1,LOW);
  if (fade.getKnobPosition() != 1) return;
  digitalWrite(L1+2,LOW);
  if (fade.getKnobPosition() != 1) return;
}

void FunWIthFading()
{ 
  int count; 
  if (fade.getKnobPosition() != 1) return;
  int fadeSpeed =10;
  if (fade.getKnobPosition() != 1) return;
  for(count=1;count<=5;count++)
  {
    fade.up(fadeSpeed,5);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,8);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,4);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,7);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,3);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,6);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,2);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,9);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,12);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,10);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,13);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,11);
    if (fade.getKnobPosition() != 1) return;
    fade.up(fadeSpeed,14);
    if (fade.getKnobPosition() != 1) return;
    delay(100);
    fade.down(fadeSpeed,5);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,8);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,4);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,7);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,3);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,6);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,2);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,9);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,12);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,10);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,13);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,11);
    if (fade.getKnobPosition() != 1) return;
    fade.down(fadeSpeed,14);
    if (fade.getKnobPosition() != 1) return;

  }
}


//------------------------------------------------------------------------
//                        Background displays
//------------------------------------------------------------------------

//
// fade an LED up and down, then move to the next LED in a clockwise direction
//
void fadeUpAndDownOneLEDAtATime()
{
  int ledNumber;
  int count;
  int fadeSpeed = 4;
  int repeatCount = 1;
  if(fade.getKnobPosition() != 2) return;

  for(count = 1; count <= repeatCount; count++)
    if(fade.getKnobPosition() != 2) return;
  {
    for(ledNumber = 2; ledNumber <= 8; ledNumber++)
    { 
      fade.up(fadeSpeed, ledNumber);
      if(fade.getKnobPosition() != 2) return;
      fade.down(fadeSpeed, ledNumber);
      if(fade.getKnobPosition() != 2) return;   // return if not in background mode
    }
    if(fade.getKnobPosition() != 2) return;
    for(ledNumber = 9; ledNumber <= 15; ledNumber++)
    { 
      fade.up(fadeSpeed, ledNumber);
      if(fade.getKnobPosition() != 2) return;
      fade.down(fadeSpeed, ledNumber);
      if(fade.getKnobPosition() != 2) return;   // return if not in background mode
    }
  }
}



//
// alternate all the LEDs on the right and left
//
void fadeUpAndDownRightAndLeft()
{
  int count;
  int fadeSpeed = 3;
  int repeatCount = 5;
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode
  digitalWrite(2,HIGH);
  fade.up(fadeSpeed, 9, 10, 11, 12, 13, 14, 15);

  for(count = 1; count <= repeatCount; count++)
  {
    if (fade.getKnobPosition() != 2) return;   // return if not in background mode
    fade.crossFade(fadeSpeed, 9, 3, 10, 4, 11, 5, 12, 6, 13, 7, 14, 8);
    if (fade.getKnobPosition() != 2) return;   // return if not in background mode
    fade.crossFade(fadeSpeed, 3, 9, 4, 10, 5, 11, 6, 12, 7, 13, 8, 14);
    if (fade.getKnobPosition() != 2) return;   // return if not in background mode
  }
  digitalWrite(2,LOW);
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode

  fade.down(fadeSpeed, 3,4,5,6,7,8);
  if (fade.getKnobPosition() != 2) return;   // return if not in background mode 
}

void FunWIthFading2()
{ 
  int count; 
  if (fade.getKnobPosition() != 2) return;
  int fadeSpeed =4;
  if (fade.getKnobPosition() != 2) return;
  for(count=1;count<=3;count++)
  {
    fade.up(fadeSpeed,5);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,8);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,4);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,7);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,3);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,6);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,2);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,9);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,12);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,10);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,13);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,11);
    if (fade.getKnobPosition() != 2) return;
    fade.up(fadeSpeed,14);
    if (fade.getKnobPosition() != 2) return;
    delay(100);
    fade.down(fadeSpeed,5);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,8);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,4);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,7);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,3);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,6);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,2);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,9);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,12);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,10);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,13);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,11);
    if (fade.getKnobPosition() != 2) return;
    fade.down(fadeSpeed,14);
    if (fade.getKnobPosition() != 2) return;

  }
}

void AllSidesOutThenIn2()
{
  int count;
  int t=500;
  int y=500;
  for(count=1;count<=5;count++)
  {
    digitalWrite(2,HIGH);
    if (fade.getKnobPosition() != 2) return;
    delay(y);
    digitalWrite(3,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(6,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(9,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(12,HIGH);
    delay(y);
    digitalWrite(4,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(7,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(10,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(13,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    delay(y);
    digitalWrite(5,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(8,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(11,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(14,HIGH);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    delay(t);
    digitalWrite(14,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(11,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(8,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(5,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    delay(y);
    digitalWrite(13,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(10,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(7,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(4,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    delay(y);
    digitalWrite(12,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(9,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(6,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(3,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    digitalWrite(2,LOW);
    delay(y);
    if (fade.getKnobPosition() != 2) return;
    delay(300);   
  }
}



