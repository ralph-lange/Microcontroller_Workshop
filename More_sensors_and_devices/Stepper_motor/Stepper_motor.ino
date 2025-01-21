#include <vector>  // Standard C++ library.
#include <ESP32Servo.h>  // Library 'ESP32Servo' V3.0.6 by Kevin Harrington, John K. Bennett.

static const int servoPin = 16;
Servo servo1;


void setup() {
  Serial.begin(115200);
  servo1.attach(servoPin);
}


void loop() {
  std::vector<int> angles = {0, 30, 60, 80};
    for (int angle : angles) {
    servo1.attach(servoPin);
    servo1.write(angle);
    Serial.printf("%d°\n", angle);
    delay(500);
    servo1.detach();
    delay(1000);
  }
}
