#include <DHT.h>
#include <DHT_U.h>

#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

int soundPin = A0;
float soundValue;
float voltage;
int waitTime =500;

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.print("Starting...");
  pinMode(soundPin, INPUT);
}

void loop() {
  soundValue = analogRead(soundPin); //lee el valor analogico
  voltage = (soundValue / 1024) * 5.0; //convert reading to voltage
  float decibelValue = map(soundValue , 0, 1024, 30, 130); //Map sensor value to decibels
 
  printElements("Analog Value: ", soundValue, waitTime);
  printElements("Voltage: ", voltage, waitTime);
  printElements("Decibels: ", decibelValue, waitTime);
}

void printElements(String title, float value, int awaitTime){
  lcd.print(title);
  lcd.print(value);
  delay(awaitTime);
  lcd.clear();
}
