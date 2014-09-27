/*
  Demo code of P22 - 8x8 Red LED Matrix Driver
  by maker studio
*/
#include "TM1638.h"

 uint8_t smileyLeft[] ={
                 	0b00111100,
			0b01000010,
			0b10000001,
			0b10101001,
			0b10000101,
			0b10111001,
			0b01000010,
			0b00111100};

 uint8_t smileyRight[] ={0b00111100,
			0b01000010,
			0b10000001,
			0b10010101,
			0b10100001,
			0b10011101,
			0b01000010,
			0b00111100};

 uint8_t smileyCenterEyesOpen[] ={0b00111100,
			0b01000010,
			0b10100101,
			0b10100101,
			0b10000001,
			0b10111101,
			0b01000010,
			0b00111100};

 uint8_t smileyCenterEyesClosed[] ={0b00111100,
			0b01000010,
			0b10000001,
			0b10100101,
			0b10000001,
			0b10111101,
			0b01000010,
			0b00111100};

 uint8_t empty[] ={    0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000};


 uint8_t euroSign[] ={  0b00011110,
			0b00100001,
			0b01000000,
			0b11111000,
			0b11111000,
			0b01000000,
			0b00100001,
			0b00011110};

 uint8_t euroSign1Left[] ={  
                        0b00001111,
			0b00010000,
			0b00100000,
			0b01111100,
			0b01111100,
			0b00100000,
			0b00010000,
			0b00001111};

 uint8_t pacGoingRight1[] ={    
                        0b00000111,
			0b10001000,
			0b00010000,
			0b00111110,
			0b00111110,
			0b00010000,
			0b10001000,
			0b00000111};

 uint8_t pacGoingRight2[] ={    
                        0b10000011,
			0b11000100,
			0b10001000,
			0b00011111,
			0b00011111,
			0b10001000,
			0b11000100,
			0b10000011};

 uint8_t pacGoingRight3[] ={    
                        0b11000001,
			0b11100010,
			0b11000100,
			0b10001111,
			0b10001111,
			0b11000100,
			0b11100010,
			0b11000001};

 uint8_t pacGoingRight4[] ={    
                        0b11100000,
			0b11110001,
			0b11100010,
			0b11000111,
			0b11000111,
			0b11100010,
			0b11110001,
			0b11100000};

 uint8_t pacGoingRight5[] ={    
                        0b11110000,
			0b11111000,
			0b01110001,
			0b11100011,
			0b11100011,
			0b11110001,
			0b11111000,
			0b11110000};

 uint8_t pacGoingRight6[] ={    
                        0b01111000,
			0b11111100,
			0b10111000,
			0b11110001,
			0b11110001,
			0b11111000,
			0b11111100,
			0b01111000};

 uint8_t pacGoingRight7[] ={    
                        0b00111100,
			0b01111110,
			0b11011100,
			0b11111000,
			0b11111000,
			0b11111100,
			0b01111110,
			0b00111100};

 uint8_t pacLookingRightClosed[] ={    
                        0b00111100,
			0b01111110,
			0b11011111,
			0b11111111,
			0b11110000,
			0b11111111,
			0b01111110,
			0b00111100};

 uint8_t pacLookingLeftClosed[] ={    
                        0b00111100,
			0b01111110,
			0b11111011,
			0b11111111,
			0b00001111,
			0b11111111,
			0b01111110,
			0b00111100};

 uint8_t pacGoingLeft1[] ={    
                        0b01111000,
			0b11111100,
			0b01110110,
			0b00111110,
			0b00111110,
			0b01111110,
			0b11111100,
			0b01111000};

 uint8_t pacGoingLeft2[] ={    
                        0b11110000,
			0b11111000,
			0b11101100,
			0b01111100,
			0b01111100,
			0b11111100,
			0b11111000,
			0b11110000};

 uint8_t pacGoingLeft3[] ={    
                        0b11100000,
			0b11110000,
			0b11011000,
			0b11111000,
			0b11111000,
			0b11111000,
			0b11110000,
			0b11100000};

 uint8_t pacGoingLeft4[] ={    
                        0b11000000,
			0b11100000,
			0b10110000,
			0b11110000,
			0b11110000,
			0b11110000,
			0b11100000,
			0b11000000};

 uint8_t pacGoingLeft5[] ={    
                        0b10000000,
			0b11000000,
			0b01100000,
			0b11100000,
			0b11100000,
			0b11100000,
			0b11000000,
			0b10000000};

 uint8_t pacGoingLeft6[] ={    
                        0b00000000,
			0b10000000,
			0b11000000,
			0b11000000,
			0b11000000,
			0b11000000,
			0b10000000,
			0b00000000};

 uint8_t pacGoingLeft7[] ={    
                        0b00000000,
			0b00000000,
			0b10000000,
			0b10000000,
			0b10000000,
			0b10000000,
			0b00000000,
			0b00000000};


 uint8_t heartBig[] ={    
			0b00000000,
                        0b01101100,
			0b10010010,
			0b10000010,
			0b01000100,
			0b00101000,
			0b00010000,
			0b00000000};

 uint8_t heartSmaller[] ={    
			0b00000000,
                        0b00000000,
			0b01101100,
			0b01010100,
			0b00101000,
			0b00010000,
			0b00000000,
			0b00000000};


 uint8_t heartSmallest[] ={    
			0b00000000,
                        0b00000000,
			0b00000000,
			0b00101000,
			0b00111000,
			0b00010000,
			0b00000000,
			0b00000000};


 uint8_t bedankt1[] ={0b00000001,
0b00000001,
0b00000001,
0b00000001,
0b00000001,
0b00000001,
0b00000001,
0b00000001};

 uint8_t bedankt2[] ={
 0b00000011,
0b00000010,
0b00000010,
0b00000010,
0b00000010,
0b00000010,
0b00000010,
0b00000011};

 uint8_t bedankt3[] ={
 0b00000111,
0b00000100,
0b00000100,
0b00000100,
0b00000100,
0b00000100,
0b00000100,
0b00000111};

 uint8_t bedankt4[] ={
0b00001111,
0b00001000,
0b00001000,
0b00001000,
0b00001000,
0b00001000,
0b00001000,
0b00001111};

 uint8_t bedankt5[] ={
0b00011110,
0b00010001,
0b00010000,
0b00010000,
0b00010000,
0b00010000,
0b00010001,
0b00011110};
        
 uint8_t bedankt6[] ={
0b00111100,
0b00100010,
0b00100001,
0b00100001,
0b00100001,
0b00100001,
0b00100010,
0b00111100};
        
 uint8_t bedankt7[] ={
0b01111000,
0b01000100,
0b01000010,
0b01000010,
0b01000010,
0b01000010,
0b01000100,
0b01111000};
        
 uint8_t bedankt8[] ={
0b11110000,
0b10001000,
0b10000100,
0b10000100,
0b10000101,
0b10000101,
0b10001001,
0b11110001};

 uint8_t bedankt9[] ={
0b11100000,
0b00010000,
0b00001001,
0b00001001,
0b00001011,
0b00001010,
0b00010010,
0b11100010};
        
 uint8_t bedankt10[] ={
0b11000000,
0b00100001,
0b00010010,
0b00010010,
0b00010111,
0b00010100,
0b00100100,
0b11000100};
        
 uint8_t bedankt11[] ={
0b10000001,
0b01000010,
0b00100100,
0b00100100,
0b00101111,
0b00101000,
0b01001000,
0b10001000};
        
 uint8_t bedankt12[] ={
0b00000010,
0b10000101,
0b01001000,
0b01001000,
0b01011111,
0b01010000,
0b10010000,
0b00010000};

 uint8_t bedankt13[] ={
0b00000100,
0b00001010,
0b10010001,
0b10010001,
0b10111111,
0b10100000,
0b00100000,
0b00100000};
        
 uint8_t bedankt14[] ={
0b00001000,
0b00010100,
0b00100010,
0b00100010,
0b01111111,
0b01000001,
0b01000001,
0b01000001};
        
 uint8_t bedankt15[] ={
0b00010000,
0b00101000,
0b01000100,
0b01000100,
0b11111110,
0b10000010,
0b10000010,
0b10000010};
        
 uint8_t bedankt16[] ={
0b00100001,
0b01010001,
0b10001001,
0b10001001,
0b11111101,
0b00000101,
0b00000101,
0b00000101};

 uint8_t bedankt17[] ={
0b01000011,
0b10100010,
0b00010010,
0b00010010,
0b11111010,
0b00001010,
0b00001010,
0b00001010};
        
 uint8_t bedankt18[] ={
0b10000110,
0b01000101,
0b00100100,
0b00100100,
0b11110100,
0b00010100,
0b00010100,
0b00010100};
        
 uint8_t bedankt19[] ={
0b00001100,
0b10001011,
0b01001001,
0b01001000,
0b11101000,
0b00101000,
0b00101000,
0b00101000};
        
 uint8_t bedankt20[] ={
0b00011000,
0b00010110,
0b10010011,
0b10010001,
0b11010000,
0b01010000,
0b01010000,
0b01010000};

 uint8_t bedankt21[] ={
0b00110000,
0b00101100,
0b00100110,
0b00100011,
0b10100001,
0b10100000,
0b10100000,
0b10100000};
        
 uint8_t bedankt22[] ={
0b01100000,
0b01011000,
0b01001100,
0b01000110,
0b01000011,
0b01000001,
0b01000000,
0b01000000};
        
 uint8_t bedankt23[] ={
0b11000000,
0b10110000,
0b10011000,
0b10001100,
0b10000110,
0b10000011,
0b10000001,
0b10000000};
        
 uint8_t bedankt24[] ={
0b10000000,
0b01100000,
0b00110000,
0b00011000,
0b00001100,
0b00000110,
0b00000011,
0b00000000};

 uint8_t bedankt25[] ={
0b00000000,
0b11000000,
0b01100000,
0b00110000,
0b00011000,
0b00001100,
0b00000110,
0b00000001};
        
 uint8_t bedankt26[] ={
0b00000001,
0b10000001,
0b11000001,
0b01100001,
0b00110001,
0b00011001,
0b00001101,
0b00000011};
        
 uint8_t bedankt27[] ={
0b00000010,
0b00000010,
0b10000010,
0b11000010,
0b01100010,
0b00110010,
0b00011010,
0b00000110};
        
 uint8_t bedankt28[] ={
0b00000101,
0b00000101,
0b00000101,
0b10000101,
0b11000101,
0b01100101,
0b00110101,
0b00001101};

 uint8_t bedankt29[] ={
0b00001010,
0b00001010,
0b00001010,
0b00001011,
0b10001011,
0b11001010,
0b01101010,
0b00011010};
        
 uint8_t bedankt30[] ={
0b00010100,
0b00010100,
0b00010101,
0b00010111,
0b00010111,
0b10010101,
0b11010100,
0b00110100};
        
 uint8_t bedankt31[] ={
0b00101000,
0b00101001,
0b00101011,
0b00101110,
0b00101110,
0b00101011,
0b10101001,
0b01101000};
        
 uint8_t bedankt32[] ={
0b01010001,
0b01010011,
0b01010110,
0b01011100,
0b01011100,
0b01010110,
0b01010011,
0b11010001};

 uint8_t bedankt33[] ={
0b10100011,
0b10100110,
0b10101100,
0b10111000,
0b10111000,
0b10101100,
0b10100110,
0b10100011};
        
 uint8_t bedankt34[] ={
0b01000110,
0b01001100,
0b01011000,
0b01110000,
0b01110000,
0b01011000,
0b01001100,
0b01000110};
        
 uint8_t bedankt35[] ={
0b00011010,
0b00110010,
0b01100010,
0b11000010,
0b11000001,
0b01100001,
0b00110001,
0b00011000};
        
 uint8_t bedankt36[] ={
0b00110100,
0b01100100,
0b11000100,
0b10000100,
0b10000010,
0b11000010,
0b01100010,
0b00110001};

 uint8_t bedankt37[] ={
0b01101000,
0b11001000,
0b10001000,
0b00001000,
0b00000100,
0b10000100,
0b11000100,
0b01100011};
        
 uint8_t bedankt38[] ={
0b11010000,
0b10010000,
0b00010000,
0b00010000,
0b00001000,
0b00001000,
0b10001000,
0b11000111};
        
 uint8_t bedankt39[] ={
0b10100000,
0b00100000,
0b00100000,
0b00100000,
0b00010000,
0b00010001,
0b00010001,
0b10001110};

 uint8_t bedankt40[] ={
0b01000001,
0b01000001,
0b01000001,
0b01000001,
0b00100001,
0b00100010,
0b00100010,
0b00011100};

 uint8_t bedankt41[] ={
0b10000010,
0b10000010,
0b10000010,
0b10000010,
0b01000010,
0b01000100,
0b01000100,
0b00111000};
        
 uint8_t bedankt42[] ={
0b00000100,
0b00000100,
0b00000100,
0b00000100,
0b10000100,
0b10001000,
0b10001000,
0b01110000};
        
 uint8_t bedankt43[] ={
0b00001000,
0b00001000,
0b00001000,
0b00001000,
0b00001000,
0b00010000,
0b00010000,
0b11100000};
        
 uint8_t bedankt44[] ={
0b00010000,
0b00010000,
0b00010000,
0b00010000,
0b00010000,
0b00100000,
0b00100000,
0b11000000};

 uint8_t bedankt45[] ={
0b00100000,
0b00100000,
0b00100000,
0b00100000,
0b00100000,
0b01000000,
0b01000000,
0b10000000};
        
 uint8_t bedankt46[] ={
0b01000000,
0b01000000,
0b01000000,
0b01000000,
0b01000000,
0b10000000,
0b10000000,
0b00000000};
        
 uint8_t bedankt47[] ={
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b10000000,
0b00000000,
0b00000000,
0b00000000};

TM1638 LED_Matrix(0,1,2);

const int trigPin = 3;
const int echoPin = 4;
const int PIRSensorPin = 13;

int sensorState = 0;

uint8_t* happy[] = { smileyLeft, smileyLeft, 
                     smileyRight, smileyRight, 
                     smileyCenterEyesClosed, smileyCenterEyesOpen,
                     smileyCenterEyesClosed, smileyCenterEyesOpen,
                     smileyCenterEyesClosed, smileyCenterEyesOpen
                   };
uint8_t* pacman[] = { euroSign, euroSign1Left, 
                      pacGoingRight1, pacGoingRight2, pacGoingRight3, pacGoingRight4, pacGoingRight5, pacGoingRight6, pacGoingRight7, 
                      pacLookingRightClosed, pacLookingLeftClosed, pacLookingRightClosed, pacLookingLeftClosed, 
                      pacGoingLeft1, pacGoingLeft2, pacGoingLeft3, pacGoingLeft4, pacGoingLeft5, pacGoingLeft6, pacGoingLeft7,
                      empty, empty };
uint8_t* love[] = { heartBig, heartSmaller, heartSmallest, heartSmaller, heartBig };
uint8_t* bedankt[] = { bedankt1,bedankt2,bedankt3,bedankt4,bedankt5,bedankt6,bedankt7,bedankt8,bedankt9,bedankt10,bedankt11,bedankt12,bedankt13,bedankt14,bedankt15,bedankt16,bedankt17,bedankt18,bedankt19,bedankt20,bedankt21,bedankt22,bedankt23,bedankt24,bedankt25,bedankt26,bedankt27,bedankt28,bedankt29,bedankt30,bedankt31,bedankt32,bedankt33,bedankt34,bedankt35,bedankt36,bedankt37,bedankt38,bedankt39,bedankt40,bedankt41,bedankt42,bedankt43,bedankt44,bedankt45,bedankt46,bedankt47,bedankt47 };

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  LED_Matrix.displayAll();
  delay(500);
  LED_Matrix.clear();
}

void loop()
{
  for (int i=0; i < 20; i++) {
    LED_Matrix.displayPic(pacman[i]);
    delay(250);
  
    digitalWrite(trigPin, LOW); //Low high and low level take a short time to TrigPin pulse
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    float cm = pulseIn(echoPin, HIGH) / 58.0; // get range and convert to cm
    
    if (cm < 5) {
      emptyScreen();
     displayRandomHappyMessage();
     // Reset counter
     i=0;
    }
  }
}

void displayRandomHappyMessage() {
  int number = random(3);
  switch(number) {
    case 0: displayHeart();
      break;
    case 1: displaySmiley();
      break;
    case 2: displayBedankt();
      break;
  }
}

void displaySmiley() {
  for (int i=0; i < 10; i++) {
    LED_Matrix.displayPic(happy[i]);
    delay(300);
  }
}

void displayBedankt() {
  for (int i=0; i < 47; i++) {
    LED_Matrix.displayPic(bedankt[i]);
    delay(100);
  }
}

void displayHeart() {
  for (int j=0; j < 7; j++) {
    for (int i=0; i < 5; i++) {
      LED_Matrix.displayPic(love[i]);
      delay(150);
    }
  }
}  

void displayPacman() {
  for (int i=0; i < 18; i++) {
    LED_Matrix.displayPic(pacman[i]);
    delay(250);
  }
}  

void emptyScreen() {
    LED_Matrix.displayPic(empty);
}
