#include <Arduino.h>  // Standard library from ESP32 platform.


const int TICK_PIN = 16;

volatile uint32_t counter = 0;


void IRAM_ATTR handleTick() {
  ++counter;
}


void setup() {
  Serial.begin(115200);
  pinMode(TICK_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(TICK_PIN), handleTick, RISING);
}


void loop() {
  const float WINDOW = 1.0;  // Measurement window in seconds.
  const int DISC_HOLES = 20;  // Number of holes in the disc.
  counter = 0;
  delay(static_cast<long>(WINDOW * 1000.0));
  float frequency = static_cast<float>(counter) / WINDOW;
  float rps = frequency / DISC_HOLES;
  float rpm = rps * 60.0;
  Serial.printf("Speed:  %.2f/s  %.1f/min\n", rps, rpm);
}
