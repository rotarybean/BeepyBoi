// BeepyBoi for Hopper
// This is a code for utilizing a proximity sensor and alarm on a granule bin to alert workers of a low hopper condition.  
// Creator: @rotarybean for Barrett Plastics
// Project started 7/1/2022, code written 7/14/2022
// version alpha v0.1
//
//------------------------@section Concept------------------------
// 3D printed housing which uses proximity sensor as mount
// Arduino Nano controls beeper module via relay, buttonpress disables beeper for 5 minutes
// Parts List:
// Arduino Uno, Nano, or Mega(ATMEGA2560)
// Pepperl+Fuchs 210621 Proximity Sensor
// Pepperl+Fuchs VAZ-HORN-70MM-85dBa
// 5v NC/NO relay (uses NC)
// Momentary button 
//
// Refer to included TinyCAD file for wiring diagram/pinout
// Sensor connector pinout:
// Pin 1 - 10-36v DC    BRN
// Pin 2 - NC           WHT
// Pin 3 - GND          BLU
// Pin 4 - <100mA Load  BLK
//
// Reference: https://arduinogetstarted.com/tutorials/arduino-button-relay for basic button/relay interaction
// Reference: https://arduinogetstarted.com/tutorials/arduino-led-blink for Relay time hold

//------------------------@section Version Notes------------------------
// v0.1 complete. Cake(?).
// Compile OK

//------------------------@section Declare Pins, Board------------------------
#include<arduino.h>
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int RELAY_PIN  = 3; // Arduino pin connected to relay's pin

//------------------------@section Setup------------------------
void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(RELAY_PIN, OUTPUT);        // set arduino pin to output mode
  pinMode(LED_BUILTIN, OUTPUT);
}
//------------------------@section Loop------------------------
void loop() {
  int buttonState = digitalRead(BUTTON_PIN); // read new state

  if (buttonState == LOW) {
    Serial.println("The button is being pressed");
    digitalWrite(RELAY_PIN, HIGH); // turn on
    digitalWrite(LED_BUILTIN, HIGH); // indicate button pressed
    delay(300000); // Wait 5 minutes, then return to normal state (relay NC)
  }
  else
  if (buttonState == HIGH) {
    Serial.println("The button is unpressed");
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(RELAY_PIN, LOW);  // turn off
  }
}