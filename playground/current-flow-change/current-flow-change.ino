void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);

}

void loop() {
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  delay(500);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
}
