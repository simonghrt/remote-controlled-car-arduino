
/*#include <BridgeClient.h>
#include <Bridge.h>*/
#include <Servo.h>

//IPAddress ip_server(172,20,10,12);  //IP Address of Server 
int calX, calY, valX, valY,val_potar;
const int VRx = 0; // A0
const int VRy = 1; // A1
const int A_potar = 3; //A3
const int D_servo = 2;
const int A_RED_LED = 11; //A11
const int A_YELLOW_LED = 13; //A13


Servo myservo; // Servo instance


void setup() {
  
  pinMode(13,OUTPUT);
  
  digitalWrite(13,LOW);
  Serial.begin(9600);
  digitalWrite(13,HIGH);//Init done !*/

  calX = analogRead(VRx); 
  calY = analogRead(VRy);

  myservo.attach(D_servo);
  
}

void loop() {
  /*BridgeClient client;// Construct the client
  
  if(client.connect(ip_server,5555)) //return 1 if connection established ; 0 else
      client.write(42);//return 1 if sent ; 0 else
    //client.write(const uint8_t *buf, size_t size)//écrit buf dans le buffer de transmision
  
  client.stop();*/

  // Mesure des valeurs en X et Y
  valX = analogRead(VRx)- calX;
  valY = analogRead(VRy)- calY;
  val_potar = analogRead(A_potar);

  // Affichage des valeurs lues
  Serial.print("--- Nouvelles lectures --- ");
  Serial.println("Valeur X : ");
  Serial.println((int)(valX));
  Serial.print("Valeur y : ");
  Serial.println((int)(valY));
  Serial.print("Valeur Potar : ");
  Serial.println((int)(val_potar));
  
  myservo.writeMicroseconds(10*valX);

  analogWrite(A_RED_LED,val_potar/4);
  analogWrite(A_YELLOW_LED,val_potar/4);
  
  delay(500);
}


