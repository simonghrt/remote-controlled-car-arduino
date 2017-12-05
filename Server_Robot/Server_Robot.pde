import processing.serial.*;
import processing.net.*;

Server s; 
Client c;
char inBuffer;
String input;

Serial myPort;

void setup() { 
  size(450, 255);
  s = new Server(this, 12345);  // Start a simple server on a port
  myPort = new Serial(this, Serial.list()[0], 9600);
} 

void draw() { 
  c = s.available();//get the next client with a message
  if (c != null) {  
    input = c.readString();
    
    if(input.charAt(0) == 'A'){
      myPort.write(65);
      println("A");    
    }
    
    else{
      myPort.write(66);  
      println("B");
    }
  }
}