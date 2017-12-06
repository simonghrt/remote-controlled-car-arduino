#include <ArduinoRobot.h>
#include <Wire.h>

//Bien passer à écrire Robot.analogRead() et pas analogRead() !!!!!

signed long left_wheel,right_wheel;
char direction_wheel;
int ind1,ind2;
int left_pin=D7,right_pin=M1,wheel_direction=M0;

void setup() {
  Robot.begin();
  pinMode(left_pin, INPUT);
  pinMode(right_pin, INPUT);
  pinMode(wheel_direction,INPUT);
}

void loop() {
  left_wheel = Robot.analogRead(left_pin);
  right_wheel = Robot.analogRead(right_pin);
  direction_wheel = Robot.digitalRead(wheel_direction);
  Serial.print(Robot.analogRead(left_pin));
  Serial.print(",");
  Serial.print(Robot.analogRead(right_pin));
  Serial.print(",");
  Serial.print(Robot.digitalRead(wheel_direction));
  Serial.println("");
  if(direction_wheel == 0){ // move forward
    left_wheel = left_wheel;
    right_wheel = right_wheel;
  }
  else{ //move backward
    left_wheel = -left_wheel;
    right_wheel = -right_wheel;
  }
  Robot.motorsWrite(left_wheel,right_wheel);
}

