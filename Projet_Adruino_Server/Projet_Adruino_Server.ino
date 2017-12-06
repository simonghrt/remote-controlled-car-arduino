#include <ArduinoRobot.h>
#include <Wire.h>

//Bien passer à écrire Robot.analogRead() et pas analogRead() !!!!!

long left_wheel,right_wheel;
int ind1,ind2;
int left_pin=D7,right_pin=M1;

void setup() {
  Robot.begin();
  pinMode(left_pin, INPUT);
  pinMode(right_pin, INPUT);
}

void loop() {
  left_wheel = Robot.analogRead(left_pin);
  right_wheel = Robot.analogRead(right_pin);
  //Serial.print(Robot.analogRead(left_pin));
  //Serial.print(",");
  //Serial.print(Robot.analogRead(right_pin));
  //Serial.println("");
  
  Robot.motorsWrite(left_wheel,right_wheel);
}

