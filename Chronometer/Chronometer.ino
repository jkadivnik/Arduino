#include "TM1650.h"
#include <inttypes.h>

#define ALL_ON 0xFF
#define ALL_OFF 0x00

static uint8_t TubeTab[] = {
						   0x3F,0x06,0x5B,0x4F,
						   0x66,0x6D,0x7D,0x07,
						   0x7F,0x6F,0x77,0x7C,
						   0x39,0x5E,0x79,0x71,   
						   };//0~9,A,B,C,D,E,F  

uint8_t number[4];// store the numbers to be displayed on four 7-Segment LEDs

TM1650 DigitalLED(18,19);//(SDA,SCL)

boolean isTimerRunning = false;
int colonState = 0;

int seconds;
int secondsCounter = 0;

int timeKeeperCounter=0;
int timeKeeperViewerCounter = 0;
int timeKeeper[100];

// constants won't change. They're used here to 
// set pin numbers:
const int greenLedPin =  0;      // the number of the LED pin
const int redLedPin =  1;      // the number of the LED pin
const int blueButtonPin = 2;     // the number of the pushbutton pin
const int whiteButtonPin = 3;     // the number of the pushbutton pin
const int redButtonPin = 4;     // the number of the pushbutton pin

int blueButtonState = 0;         // variable for reading the pushbutton status
int whiteButtonState = 0;         // variable for reading the pushbutton status
int redButtonState = 0;         // variable for reading the pushbutton status

void setup() {
  pinMode(greenLedPin, OUTPUT);      
  pinMode(redLedPin, OUTPUT);      
  pinMode(blueButtonPin, INPUT);     
  pinMode(whiteButtonPin, INPUT);     
  pinMode(redButtonPin, INPUT);     
  DigitalLED.begin();
  for(int bitAddr = 0; bitAddr < 4; bitAddr++) {
    DigitalLED.display(bitAddr, TubeTab[0]);
    delay(100);
  }
  DigitalLED.setPoint(1,1);
  delay(100);
  digitalWrite(redLedPin, HIGH);
}

void loop(){
  if (isTimerRunning == true) {
    delay(200);
    secondsCounter += 200;
    
    if (secondsCounter == 1000) {
      DigitalLED.setPoint(1,colonState);
      colonState==1?colonState=0:colonState=1;
      secondsCounter = 0;
      seconds++;
      setTimer(seconds);
    }
  }
  
  if (getButtonState(blueButtonPin) == HIGH) {
    if (blueButtonState == 0) {
      if (isTimerRunning == false) {
        isTimerRunning = true;
        digitalWrite(redLedPin, LOW);
        digitalWrite(greenLedPin, HIGH);
        seconds = 0;
        timeKeeperCounter = 0;
      }
    }
    blueButtonState = 1;
  } else {
    blueButtonState = 0;
  }
  
  if (getButtonState(whiteButtonPin) == HIGH) {
    if (whiteButtonState == 0) {
      if (isTimerRunning == true) {
        addTimeToTimeKeeper();
      } else {
        if (timeKeeperCounter != 0) {
          setTimer(timeKeeper[timeKeeperViewerCounter]);
          timeKeeperViewerCounter<timeKeeperCounter-1?timeKeeperViewerCounter++:timeKeeperViewerCounter=0;
          delay(500);
        }
      }
    }
    whiteButtonState = 1;
  } else {
    whiteButtonState = 0;
  }

  if (getButtonState(redButtonPin) == HIGH) {
    if (redButtonState == 0) {
      if (isTimerRunning == true) {
        isTimerRunning = false;
        digitalWrite(greenLedPin, LOW);
        digitalWrite(redLedPin, HIGH);
        addTimeToTimeKeeper();
      }
    }
    redButtonState = 1;
  } else {
    redButtonState = 0;
  }
}

int getButtonState(int buttonPin) {
  return digitalRead(buttonPin);
}

void setTimer(int seconds) {
  int tempSeconds = digitCounter(seconds, 600, 0);
  tempSeconds = digitCounter(tempSeconds, 60, 1);
  tempSeconds = digitCounter(tempSeconds, 10, 2);
  tempSeconds = digitCounter(tempSeconds, 1, 3);
}

int digitCounter(int seconds, int divider, int address) {
  int digit = seconds / divider;
  setDigit(address, digit);
  return seconds - (digit * divider);
}

int setDigit(int address, int value) {
  DigitalLED.display(address, TubeTab[value]);
}

void addTimeToTimeKeeper() {
      timeKeeper[timeKeeperCounter]=seconds;
      timeKeeperCounter++;
}

