String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete
signed char val_left_wheel,val_right_wheel,wheel_direction;
int ind1,ind2;

void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
  pinMode(3, OUTPUT); /*D7 => left wheel*/
  pinMode(5, OUTPUT); /*/M1 => right wheel*/
  pinMode(7, OUTPUT); /*M0 => wheel direction*/
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); // LED : "L" à coter de la PIN13
}

void loop() {
  //écriture analogique ici
  if (stringComplete) {
    //Analog writing here
    analogWrite(3, val_left_wheel);
    analogWrite(5, val_right_wheel);
    digitalWrite(7, wheel_direction);
    // clear the string:
    inputString = "";
    stringComplete = false;
    digitalWrite(LED_BUILTIN, LOW);
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      ind1 = inputString.indexOf(',');  //finds location of first ,
      val_left_wheel = inputString.substring(0, ind1).toInt();   //captures first data String
      ind2 = inputString.indexOf(',',ind1+1);  //finds location of second ,
      val_right_wheel = inputString.substring(ind1+1,ind2).toInt();   //captures second data String
      wheel_direction = inputString.substring(ind2+1).toInt(); //captures third data String
      
      stringComplete = true;
      digitalWrite(LED_BUILTIN, HIGH);      
    }
  }
}
