// Uno send

void setup() {
  Serial.begin(9600);
  
  int integersToSend[] = {1, 22, 30, 4, 50};
  for (int i = 0; i < 5; i++) 
  {
    Serial.print(integersToSend[i]);  // send as characters
    delay(1000);
  }
}

void loop() {}
