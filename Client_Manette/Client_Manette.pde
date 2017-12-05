import processing.serial.*;
import processing.net.*;

Server s; 
Client c;
char inBuffer;
String input;

Serial myPort;

void setup() { 
  size(450, 255);
  background(204);
  stroke(0);
  frameRate(5); // Slow it down a little
  //c = new Client(this,"172.20.10.54", 12345);  // IP Address of Server in Wifi network
  c = new Client(this,"127.0.0.1", 12345);  // IP Address of Server in localhost
  println(c.ip());
  myPort = new Serial(this, Serial.list()[1], 9600);
  myPort.bufferUntil('\n');
} 

void draw() { 
    if (myPort.available() > 0) {  
      input = myPort.readString();
      c.write(input);
      println(input);
    }
       
}

void mousePressed() {
  c.stop();
}