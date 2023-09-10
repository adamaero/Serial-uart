#include <EEPROM.h>

const int EEPROM_SIZE = 100; // Define size of EEPROM available
int addr = 0; // EEPROM address pointer

unsigned long programStartTime;

void setup()
{
  Serial.begin(9600);
  while (!Serial);
    Serial1.begin(9600);

  programStartTime = millis(); // Record program start time

  // Initialize EEPROM data
  //  for (int i = 0; i < EEPROM_SIZE; i++) {
  //    EEPROM.write(i, 0);
  //  }
  displayEEPROMData();
}

void loop()
{
  if (Serial1.available())
  {
    int receivedData = Serial1.read();

    if (receivedData >= 1 && receivedData <= 60)
    {
      byte receivedValue = static_cast<byte>(receivedData); // Convert to byte

      // Calculate the timestamp based on program start time
      unsigned long currentTime = millis() - programStartTime;

      // Store the received timestamp and value in EEPROM
      EEPROM.put(addr, currentTime);
      addr += sizeof(currentTime);
      EEPROM.put(addr, receivedValue);
      addr += sizeof(receivedValue);

      displayEEPROMData();
    }
  }

  if (addr >= EEPROM_SIZE) {
    addr = 0; // Wrap around if the EEPROM is full
  }

}

void displayEEPROMData() {
  // Display all positions stored in EEPROM
  Serial.println("EEPROM:");

  for (int i = 0; i < EEPROM_SIZE; i += sizeof(unsigned long) + sizeof(byte)) {
    unsigned long timestamp;
    byte value;
    EEPROM.get(i, timestamp);
    EEPROM.get(i + sizeof(timestamp), value);

    // Display position data with timestamp in HH:MM:SS format
    Serial.print(String(i / (sizeof(unsigned long) + sizeof(byte)) + 1) + ": ");
    Serial.println(String(timestamp) + ", " + String(value));
  }
}
