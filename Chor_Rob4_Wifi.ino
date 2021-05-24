#include "Bridge.h"
#include "YunServer.h"
#include "YunClient.h"
#include "SPI.h"


#include <Console.h>

// Déclaration des constantes des broches
const byte in1a = 8;
const byte in2a = 9;
const byte pwma = 10;
const byte in1b = 4;
const byte in2b = 5;
const byte pwmb = 6;
const byte droit = 2;
const byte gauche = 1;

// Prototypages des fonctions
void avancer(int, int, int);
void choregraphie();

YunServer server;

void setup() {
  pinMode(in1a, OUTPUT);
  pinMode(in2a, OUTPUT);
  pinMode(pwma, OUTPUT);
  pinMode(in1b, OUTPUT);
  pinMode(in2b, OUTPUT);
  pinMode(pwmb, OUTPUT);
  // Bridge startup
  pinMode(13,OUTPUT);
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
}

void loop() {
  YunClient client = server.accept();
  if (client) {
    process(client);
    client.stop();
  }
  delay(50);
}

void process(YunClient client) {
  String command = client.readStringUntil('/');
  if (command == "message") {
    messageCommand(client);
  }
}

void messageCommand(YunClient client) {
  String message = client.readStringUntil('/');
  client.print(F("Message"));
  client.print(F(" set to "));
  client.println(message);
  String key = "Message";
  Bridge.put(key, message);
  Serial.print(message);
  if(message == "start\r\n") {
    choregraphie();
  }
}

void avancer(int moteur, int puissance, int sens) {
  if (moteur == 1) {
    if (sens == 1) {
      analogWrite(pwma,puissance);
      digitalWrite(in1a,LOW); digitalWrite(in2a,HIGH);
    }
    else {
      analogWrite(pwma,puissance);
      digitalWrite(in1a,HIGH); digitalWrite(in2a,LOW);
    }
  }
  if (moteur == 2) {
    if (sens == 1) {
      analogWrite(pwmb,puissance);
      digitalWrite(in1b,LOW); digitalWrite(in2b,HIGH);
    }
    else {
      analogWrite(pwmb,puissance);
      digitalWrite(in1b,HIGH); digitalWrite(in2b,LOW);
    }
  }
}
void choregraphie() {
  //Avancer
  avancer(droit,128,1);avancer(gauche,128,1);
  delay(2500);
  //Reculer
  avancer(droit,128,0);avancer(gauche,128,0);
  delay(2500);
  //Virage
  avancer(droit,32,1);avancer(gauche,128,1);
  delay(4000);
  //Spin
  avancer(droit,255,1);avancer(gauche,255,0);
  delay(10000);
  //Arret
  avancer(droit,0,0);avancer(gauche,0,1);
}
