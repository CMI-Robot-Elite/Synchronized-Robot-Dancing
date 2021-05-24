/* 13 Mai 2021
Programme final à transférer sur les cartes.
Il ne manque que la chorégraphie à réaliser */
#include <Console.h>
// Déclaration des constantes des broches
const byte in1a = 8;
const byte in2a = 9;
const byte pwma = 10;
const byte in1b = 4;
const byte in2b = 5;
const byte pwmb = 6;
const byte droit = 1;
const byte gauche = 2;
// Prototypages des fonctions
void avancer(int, int, int);
void choregraphie();
void setup() {
  pinMode(in1a, OUTPUT);
  pinMode(in2a, OUTPUT);
  pinMode(pwma, OUTPUT);
  pinMode(in1b, OUTPUT);
  pinMode(in2b, OUTPUT);
  pinMode(pwmb, OUTPUT);
  Bridge.begin(); Console.begin();
  // On attend que la console soit disponible
  while (!Console);
  Console.println("OK");
}
void loop() {
  String commande;
  if (Console.available() > 0) {
    char c = Console.read();
    if (c == '\n') {
      if(commande == "start") { choregraphie(); }
      commande = "";
    } else {
      commande += c;
    }
  } else {
    delay(10);
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
  avancer(gauche,255,1);
  avancer(droit,255,1);
  delay(1000);
  avancer(gauche,0,1);
  avancer(droit,0,1);
}
