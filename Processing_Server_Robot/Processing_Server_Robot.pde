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
  //myPort = new Serial(this, Serial.list()[0], 9600);
  myPort = new Serial(this, "COM11", 9600);
} 

void draw() { 
  c = s.available();//get the next client with a message
  if (c != null && myPort.available() == 0) {  
    input = c.readString();
    myPort.clear();
    print(input);
    delay(20);
    myPort.write(input);
  }
}

void mousePressed() {
  input = "0,0,0\n";
  myPort.clear();
  delay(1000);
  print(input);
  myPort.write(input);
  myPort.clear();
  exit();
}