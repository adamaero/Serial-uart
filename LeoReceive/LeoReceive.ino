// Leo receive

String receivedData = "";
boolean newData = false;

void setup() 
{
  Serial.begin(9600);
  while (!Serial);  
  Serial1.begin(38400);
  Serial1.setTimeout(100); // adjust as needed
  Serial1.println("Waiting for data...");
}

void loop() 
{
  if (Serial1.available() > 0) 
  {
    char incomingChar = Serial1.read();
    
    if (incomingChar == ',') 
    {
      Serial.print("Received data: ");
      Serial.println(receivedData);
      receivedData = ""; // Reset the received data string
      newData = false;
    } 
    else 
    {
      receivedData += incomingChar; // Append the character to the received data string
      newData = true;
    }
  }
}
