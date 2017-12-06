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
  myPort = new Serial(this, "COM7", 9600);
  int start = millis();
  while (millis() - start < 1200);
} 

void draw() { 
  c = s.available();//get the next client with a message
  if (c != null && myPort.available() == 0) {  
    input = c.readString();
    input+="\n";
    myPort.clear();
    print(input);
    myPort.write(input);
    int start = millis();
    while (millis() - start < 1200);
    delay(200);
    /*if(input.charAt(0) == 'A'){
      myPort.write(65);
      println("A");   
    }
    
    else{
      myPort.write(66);  
      println("B");
    }*/
  }
}

void mousePressed() {
  exit();
}