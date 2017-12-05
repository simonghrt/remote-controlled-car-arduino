#include <ArduinoRobot.h>
#include <Wire.h>

char val;

void setup() {
  // initialize the robot
  Robot.begin();
  Serial.begin(9600);
  // initialize the screen
  Robot.beginTFT();
}
void loop() {

  if (Serial.available() > 0) { // If data is available to read,
    val = Serial.read(); // read it and store it in val

    
    
    

        
  }   
}
