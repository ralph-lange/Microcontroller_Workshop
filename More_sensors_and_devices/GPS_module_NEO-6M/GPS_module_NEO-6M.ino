#include <HardwareSerial.h>  // Standard library from ESP32 platform.
#include <TinyGPSPlus.h>  // Library 'TinyGPSPlus' V1.0.3 by Mikal Hart.


HardwareSerial gpsSerial(2);
TinyGPSPlus parser{};
String nmeaLine = "";
unsigned long nextStatusMessageTime = 0;


void setup() {
  Serial.begin(115200);

  delay(250);
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);
  Serial.printf("Initialized GPS.\n");
}


void loop() {
  bool hasNewNmeaLine = false;
  if (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    if (c == '$') {
      nmeaLine = "";
    }
    parser.encode(c);
    nmeaLine += c;
    if (c == '\n') {
      hasNewNmeaLine = true;
    }
  }

  if (hasNewNmeaLine) {
    Serial.print("NMEA line: ");
    Serial.println(nmeaLine.substring(0, nmeaLine.length() - 2));  // Remove trailing "\r\n" from NMEA line.
  }

  if (millis() > nextStatusMessageTime) {
    Serial.printf("Receiving data from %d satellite(s).\n", parser.satellites.value());
    if (parser.location.isUpdated()) {
      Serial.printf("New position fix:  Lat=%8.6f°  Lon=%8.6f°  Speed=%3.1f km/h\n", parser.location.lat(), parser.location.lng(), parser.speed.kmph());
    }
    nextStatusMessageTime = millis() + 1000;
  }
}
