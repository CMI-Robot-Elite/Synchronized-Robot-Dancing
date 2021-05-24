const byte in1a=8;
const byte in2a=9;
const byte pwma=10;
const byte in1b=4;
const byte in2b=5;
const byte pwmb=6;
const byte droit=1;
const byte gauche=2;
const unsigned long inter=1000;
const unsigned long inter1=2000;
unsigned long millisprev=0;
unsigned long millisprev1=0;
byte sens = 1;
byte sens1 = 1;


void avancer(int, int, int);

void setup() {
  pinMode(pwma,OUTPUT);
  pinMode(in1a,OUTPUT);
  pinMode(in2a,OUTPUT);
  pinMode(pwmb,OUTPUT);
  pinMode(in1b,OUTPUT);
  pinMode(in2b,OUTPUT);

}

void avancer(int moteur, int puissance, int sens){
  if (moteur==1){
    if (sens==1){
      analogWrite(pwma,puissance);
      digitalWrite(in1a,LOW);
      digitalWrite(in2a,HIGH);
    }
    else{
      analogWrite(pwma,puissance);
      digitalWrite(in1a,HIGH);
      digitalWrite(in2a,LOW);
    }
  }
  if (moteur==2){
    if (sens==1){
      analogWrite(pwmb,puissance);
      digitalWrite(in1b,LOW);
      digitalWrite(in2b,HIGH);
    }
    else{
      analogWrite(pwmb,puissance);
      digitalWrite(in1b,HIGH);
      digitalWrite(in2b,LOW);
    }
  }
}

void loop() {
  unsigned long millisactu= millis();
  if (millisactu-millisprev >= inter){
    millisprev=millisactu;
    avancer(gauche, 200, sens);
    sens=!sens;
  }
   if (millisactu-millisprev1 >= inter1){
   millisprev1=millisactu;
   avancer(droit, 200, sens1);
   sens1=!sens1;
  }
}
