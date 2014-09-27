#include <LiquidCrystal.h>

const int trigPin = 11;
const int echoPin = 10;
const int redLedPin = 6;
const int greenLedPin = 7;
const String notation = "cm";
const String emptyLCDLine = "                ";

LiquidCrystal lcd(0, 1, 2, 3, 4, 5);


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLedPin, OUTPUT);     
  pinMode(redLedPin, OUTPUT);     

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("NOT TOO CLOSE!");
}

void loop() {
  digitalWrite(trigPin, LOW); //Low high and low level take a short time to TrigPin pulse
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  float cm = pulseIn(echoPin, HIGH) / 58.0; // get range and convert to cm

  setRangeMessage(cm);
  setWarningMessage(cm);

  delay(1000);
}

void setWarningMessage(float cm) {
  lcd.setCursor(0,0);
  lcd.print(emptyLCDLine);
  lcd.setCursor(0,0);
  if (cm < 20) {
    lcd.print("INVASION!!!");
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  } else {
    lcd.print("NOT TOO CLOSE!");
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }
}

void setRangeMessage(float cm) {
  lcd.setCursor(0, 1);
  lcd.print(emptyLCDLine);
  lcd.setCursor(0, 1);

  cm = (int(cm * 100.0)) / 100.0;
  char tmp[10];
  dtostrf(cm, 1, 2, tmp);
  lcd.print(tmp);
}
