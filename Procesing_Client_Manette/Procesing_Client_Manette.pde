import processing.serial.*;
import processing.net.*;

Server s; 
Client c;
char inBuffer,mouse=1;
String input;

Serial myPort;

void setup() { 
  size(450, 255);
  background(204);
  stroke(0);
  frameRate(5); // Slow it down a little
  c = new Client(this,"172.20.10.9", 12345);  // IP Address of Server in Wifi network
  // c = new Client(this,"127.0.0.1", 12345);  // IP Address of Server in localhost
  println(c.ip());
  myPort = new Serial(this, Serial.list()[0], 9600);
  //myPort = new Serial(this, "COM11", 9600);
  myPort.bufferUntil('\n');
} 

void draw() { 
  if(mouse==1){
    if (myPort.available() > 0) {  
      input = myPort.readString();
      c.write(input);
      println(input);
    }
    myPort.clear();
  }
       
}

void mousePressed() {
  exit();
}