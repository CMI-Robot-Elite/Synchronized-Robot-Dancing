#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1

SoftwareSerial mySerial(rxPin, txPin); // RX, TX
String leString; 

void setup() {
  Serial.begin(9600);   
  Serial.println("Goodbye world");

  mySerial.begin(9600);
  mySerial.println("Hello world bis");
}

void loop() {
  if(mySerial.available()) {
    leString = mySerial.read();
    Serial.println(leString);
  }
  if(Serial.available()) {
   leString = Serial.read();
   mySerial.println(leString);
  }
}
