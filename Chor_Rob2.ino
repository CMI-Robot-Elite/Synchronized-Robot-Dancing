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
const byte droit = 2;
const byte gauche = 1;

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


  choregraphie();
}

void loop() {
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
  delay(4000);
  //Reculer
  avancer(droit,128,0);avancer(gauche,128,0);
  delay(4000);
  //Triangle
  avancer(droit,128,1);avancer(gauche,110,1);
  delay(5000);
  avancer(droit,128,0);avancer(gauche,128,0);
  delay(4000);
  avancer(droit,128,1);avancer(gauche,110,1);
  delay(5000);
  //Virage
  avancer(droit,128,1);avancer(gauche,128,1);
  delay(5000);
  //Spin
  avancer(droit,255,1);avancer(gauche,255,0);
  delay(6000);
  //Arret
  avancer(droit,0,0);avancer(gauche,0,1);
}
