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
  //c = s.available();//get the next client with a message
  if (/*c != null &&*/ myPort.available() == 0) {  
    //input = c.readString();
    input = "127,0\r\n";
    myPort.clear();
    delay(500);
    print(input);
    myPort.write(input);
    print("send !\n");
    delay(500);
  }
}

void mousePressed() {
  exit();
}