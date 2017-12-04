import processing.serial.*;
import processing.net.*;

Server s; 
Client c;
char inBuffer;
String input;

Serial myPort;

void setup() { 
  s = new Server(this, 12345);  // Start a simple server on a port
  myPort = new Serial(this, Serial.list()[0], 9600);
} 

void draw() { 
 // println(Serial.list()[0]);
  c = s.available();//get the next client with a message
  if (c != null) {  
    //println(20);
    input = c.readString();
    //println(30);
    myPort.write(1);
    println(input);
    //println(40);
  }
  //println(c);
}