
/*#include <BridgeClient.h>
#include <Bridge.h>*/
#include <Servo.h>

//IPAddress ip_server(172,20,10,12);  //IP Address of Server 
int calX, calY, valX, valY, val_potar;
const int VRx = 0; // A0
const int VRy = 1; // A1
const int A_potar = 3; //A3
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
}

void loop() {

  // Mesure des valeurs en X et Y
  valX = analogRead(VRx)- calX; // -255 to 255
  valY = analogRead(VRy)- calY; // -255 to 255
  val_potar = analogRead(A_potar); // 0 to 1023

  // Calculs direction
  int vitG, vitD; // -255 to 255 (à la fin des calculs)
  int dir; // 0 : avance; 1 : recule

  // Détermination des directions du robot
  if (valX == 0) {
    dir = 0;
  } else if (valX > 0) {
    dir = 0;
  } else {
    dir = 1;
    // Si on a X négatif, on prend la valeur absolue par la suite puisqu'on a en direction 1
    valX = -valX;  
  }

  // Si valeurs très faibles, on considère que c'est nul
  if (valX < 4) {
    vitG = 0;
    vitD = 0;
  } else {
    // Calcul des vitesses en utilisant X et Y
    vitG = valX + (255 - max(0, valY));
    vitD = valX + (255 - max(0, -valY));

    // On prend en compte la valeur du potar
    vitG = vitG + (val_potar/2);
    vitD = vitD + (val_potar/2);
  
    // Correction pour être bien 0 et 255
    vitG = vitG / 4;
    vitD = vitD / 4;
  
    // Correction supplémentaire car ça allait trop vite
    vitG = vitG - min(vitG, 30);
    vitD = vitD - min(vitD, 30);
  }


  analogWrite(A_RED_LED,vitG);
  analogWrite(A_YELLOW_LED,vitD);

  String str = String(vitG) + String(",") + String(vitD) + String(",") + String(dir);

  Serial.println(str);
  
  delay(100);
}


