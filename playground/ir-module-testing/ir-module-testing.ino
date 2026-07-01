void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensorInput1 = analogRead(A0);
  int sensorInput2 = analogRead(A1);
  Serial.print(sensorInput1);
  Serial.print("_");
  Serial.print(sensorInput2);
}
