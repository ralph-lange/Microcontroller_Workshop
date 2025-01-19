#include <Wire.h>  // Standard library from ESP32 platform.
#include <Adafruit_SH110X.h>  // Library 'Adafruit SH110X' V2.1.11 by Adafruit


const int DISPLAY_WIDTH = 128;
const int DISPLAY_HEIGHT = 64;
const uint8_t DISPLAY_I2C_ADDRESS = 0x3c;
const int SPHERE_RADIUS = 7;

Adafruit_SH1106G display = Adafruit_SH1106G(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire);


void setup() {
  Serial.begin(115200);
  delay(100);  // Wait for 0.1s for display to power up.
  display.begin(DISPLAY_I2C_ADDRESS);
}


void loop() {
  static int posX = DISPLAY_WIDTH / 2;
  static int speedX = 2;  // Speed in pixels per frame.

  display.clearDisplay();
  if (posX <= SPHERE_RADIUS || posX >= DISPLAY_WIDTH - SPHERE_RADIUS) {
    speedX = -speedX;
  }
  posX += speedX;
  display.fillCircle(posX, 30, SPHERE_RADIUS, SH110X_WHITE);
  display.display();  // Flush data to display.
  delay(20);  // Update display at 50Hz.
}
