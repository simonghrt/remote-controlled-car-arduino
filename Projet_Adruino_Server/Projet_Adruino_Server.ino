
#include <BridgeServer.h> 
#include <BridgeClient.h>
#include <Console.h>
#include <Bridge.h>

BridgeServer server;

void setup() {
  
  pinMode(13,OUTPUT);
  
  digitalWrite(13,LOW);
  Bridge.begin();
  digitalWrite(13,HIGH);
  
  server.begin();
  Console.begin();
}

void loop() {
  BridgeClient client = server.accept();
  if(client.connected()){
    
    client.println("Connected");
    Serial.println("Client: " + client);
    
    while(client.available()<1);
    Console.println(client.read()); // this should print out 42
    client.stop();
  }
}
