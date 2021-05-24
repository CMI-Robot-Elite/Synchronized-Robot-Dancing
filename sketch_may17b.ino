#include <Console.h>

const int ledPin = 13; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into

void setup() {

  // initialize serial communication:

  Bridge.begin();

  Console.begin();

  while (!Console){

    ; // wait for Console port to connect.

  }

  Console.println("You're connected to the Console!!!!");

  // initialize the LED pin as an output:

  pinMode(ledPin, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {

  // see if there's incoming serial data:

  if (Console.available() > 0) {

    // read the oldest byte in the serial buffer:

    incomingByte = Console.read();

    // if it's a capital H (ASCII 72), turn on the LED:

    if (incomingByte == 'H') {

      digitalWrite(ledPin, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      analogWrite(10, 255);
      

    }

    // if it's an L (ASCII 76) turn off the LED:

    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      analogWrite(10, 0);

    }

  }

  delay(100);
}
