#include <Wire.h>  // Standard library from ESP32 platform.
#include <Adafruit_SH110X.h>  // Library 'Adafruit SH110X' V2.1.11 by Adafruit


const int DISPLAY_WIDTH = 128;
const int DISPLAY_HEIGHT = 64;
const uint8_t DISPLAY_I2C_ADDRESS = 0x3c;  // Hardware address of the display (a number between 0 and 127).

Adafruit_SH1106G display = Adafruit_SH1106G(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire);


void setup() {
  Serial.begin(115200);
  delay(100);  // Wait for 0.1s for display to power up.
  display.begin(DISPLAY_I2C_ADDRESS);
}


void loop() {
  display.clearDisplay();

  int uptime = millis() / 1000;  // Uptime of ESP32 in seconds.

  display.drawLine(0, 10, 5, 35, SH110X_WHITE);

  display.drawRoundRect(25, 30, 35, 25, 7, SH110X_WHITE);

  display.drawCircle(100, 55, 7 + uptime % 8, SH110X_WHITE);

  display.drawPixel(0, 60, SH110X_WHITE);
  display.drawPixel(2, 60, SH110X_WHITE);
  display.drawPixel(4, 60, SH110X_WHITE);
  display.drawPixel(8, 60, SH110X_WHITE);
  display.drawPixel(16, 60, SH110X_WHITE);

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(25, 15);
  display.printf("Up time: %ds", uptime);

  int motionX = abs(static_cast<int>(millis() / 20) % 40 - 20);  // Relative motion in x between 0 and 20.
  display.fillRect(95 + motionX, 0, 10, 5, SH110X_WHITE);

  display.display();  // Flush data to display.

  delay(20);  // Update display at approx. 50Hz.
}
