/*
  Blink

  Turns an LED on and off based on a given pattern.
  
  Blinking is done without using delay function,
  which means it can be used in a loop with minimal
  impact on performance.

  This example is based on te official Arduino Blink example

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman
  modified 8 Sep 2016
  by Nikola Derezic

  This example code is in the public domain.
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

unsigned int blinkPattern1[] = { 1000,10,200,10,1000,10 };
unsigned int blinkPattern2[] = { 1000,10 };
byte blinkPattern1Len = sizeof blinkPattern1 / sizeof blinkPattern1[0]-1;
byte blinkPattern2Len = sizeof blinkPattern2 / sizeof blinkPattern2[0]-1;

// the loop function runs over and over again forever
void loop() {
  blinkLed(LED_BUILTIN, blinkPattern1, blinkPattern1Len);
}

byte blinkPos = 0;
unsigned int blinkTtl;

void blinkLed(byte LED_PIN, unsigned int blinkPattern[], byte patternLen) {
  unsigned int now = millis();
  
  if(now > blinkTtl) {

    if(++blinkPos>patternLen) {
      blinkPos=0;
    }

    blinkTtl = now + (unsigned int)blinkPattern[blinkPos];

    if(blinkPos%2==0) {
      digitalWrite(LED_PIN, LOW);
    }
    else
    {
      digitalWrite(LED_PIN, HIGH);
    }
  }
}
