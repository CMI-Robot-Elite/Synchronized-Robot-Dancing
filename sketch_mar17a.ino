// Calcul de la vitesse du moteur à partir du capteur //

int nombreImpulsions = 0;
float vitesse = 0;
const unsigned long interrpm=15000;
unsigned long millisprev=0;

void setup() {
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
  // lancer le moteur //
  analogWrite(10, 128);
  analogWrite(9, 0);
  digitalWrite(8, HIGH);
  // On déclare une interruption dès que le signal sur la broche 2 (celle qui reçoit le signal du capteur optique) est montant
  attachInterrupt(0, incrementerImpulsions, RISING);
}



void loop() {
  // On lance la fonction calculerVitesse toutes les secondes)
  unsigned long  millisactu=millis();
  if (millisactu - millisprev >= interrpm){
    millisprev=millisactu;
    calculerVitesse();
  }
  // Serial.println(nombreImpulsions);
  // attachInterrupt(1, calculerVitesse, CHANGE);
}

void incrementerImpulsions() {
  nombreImpulsions++;
}

void calculerVitesse() {
  vitesse = nombreImpulsions / 10 * 4;
  nombreImpulsions = 0;
  Serial.print("Vitesse : ");
  Serial.println(vitesse);
}
