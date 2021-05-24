void setup() {
  Serial.begin(115200);
}

void loop() {
  char val;
  val=Serial.read();
  Serial.print(val);
}
