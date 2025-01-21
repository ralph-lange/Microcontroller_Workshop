#include <SPI.h>  // Standard library from ESP32 platform.
#include <MFRC522.h>  // Library 'MFRC522' V.1.4.11 by GithubCommunity.


MFRC522 rfidReader(21, 22);


void setup() {
  Serial.begin(115200);

  delay(50);
  SPI.begin();
  rfidReader.PCD_Init();
}


void loop() {
  if (!rfidReader.PICC_IsNewCardPresent()) {
    return;
  }

  if (!rfidReader.PICC_ReadCardSerial()) {
    return;
  }

  unsigned long cardId = 0;
  for (int i = 0; i < rfidReader.uid.size; ++i) {
    cardId = cardId | rfidReader.uid.uidByte[i];
    cardId = cardId << 8;
  }

   Serial.printf("Card ID is #%lx\n", cardId);
   delay(250);
}
