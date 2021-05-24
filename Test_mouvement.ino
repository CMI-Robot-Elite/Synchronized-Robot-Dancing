/* Test robot*/
/*Le 01/03/21*/
const byte In1A=8;
const byte In2A=9;
const byte PWMA=10;
const byte In1B=4;
const byte In2B=5;
const byte PWMB=6;

void setup() {
  pinMode(PWMA,OUTPUT);
  pinMode(In1A,OUTPUT);
  pinMode(In2A,OUTPUT);
  pinMode(PWMB,OUTPUT);
  pinMode(In1B,OUTPUT);
  pinMode(In2B,OUTPUT);
}

void loop() {
  analogWrite(PWMA,255);
  digitalWrite(In1A,HIGH);
  digitalWrite(In2A,LOW);
  analogWrite(PWMB,255);
  digitalWrite(In1B,HIGH);
  digitalWrite(In2B,LOW);

}
