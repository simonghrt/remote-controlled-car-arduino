
#include <BridgeServer.h> 
#include <BridgeClient.h>
#include <Console.h>
#include <Bridge.h>

BridgeServer server;
const int LED=2;
int i=0; // variable de boucle

void setup() {
  
  pinMode(13,OUTPUT);
  pinMode(LED, OUTPUT); //met la broche en sortie
  
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

  for (i=0; i<=255;i++){ // boucle for compte de 0 à 255

  analogWrite(LED,i); // génère une impulsion sur la broche de largeur i = la luminosité augmente

  delay(10); // pause de 10 ms entre chaque "cran"

  } // fin de la boucle for

  for (i=0; i<=255;i++){ // boucle for compte de 0 à 255

  analogWrite(LED,255-i); // génère une impulsion sur la broche de largeur 255-i 
                        // = la luminosité baisse

  delay(10); // pause de 10 ms entre chaque "cran"

  }
}
