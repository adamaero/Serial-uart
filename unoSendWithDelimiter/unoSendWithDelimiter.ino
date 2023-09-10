// Uno send

void setup() {
  Serial.begin(38400);
}

void loop() {
  int integersToSend[] = {12345, 67890, 54321, 9876, 123};
  for (int i = 0; i < 5; i++) {
//    Serial.write((byte*)&integersToSend[i], sizeof(int)); // send as int
    Serial.print(integersToSend[i]);  // send as char
    delay(1000);
    Serial.write(',');
  }
}
