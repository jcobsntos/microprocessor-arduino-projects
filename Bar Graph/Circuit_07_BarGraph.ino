/*
  CoMotion MakerSpace 2018
  Edited by: Ramon Qu
  Arduino 101 Basic Workshop
  7 - LED bar graph

  Turns on a series of LEDs based on the value of an analog sensor.
  This is a simple way to make a bar graph display. Though this graph
  uses 10 LEDs, you can use any number by changing the LED count
  and the pins in the array.

  This method can be used to control any series of digital outputs that
  depends on an analog input.

  The circuit:
   * LEDs from pins 2 through 11 to ground

 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/BarGraph
 */

// these constants won't change:
const int analogPin = A0;   // the pin that the potentiometer is attached to
const int ledCount = 10;    // the number of LEDs in the bar graph

int ledPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};   // an array of pin numbers to which LEDs are attached


void setup() {
  // loop over the pin array and set them all to output:
  for (int led = 0; led < ledCount; led++) {
    pinMode(ledPins[led], OUTPUT);
  }
}

void loop() {
  // read the potentiometer:
  int sensorReading = analogRead(analogPin);
  // map the result to a range from 0 to the number of LEDs:
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);

  // loop over the LED array:
  for (int led = 0; led < ledCount; led++) {
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (led < ledLevel) {
      digitalWrite(ledPins[led], HIGH);
    }
    // if the array element's index is greater than or equal to ledLevel,
    // turn the pin for this element off:
    else {
      digitalWrite(ledPins[led], LOW);
    }
  }
}

  

