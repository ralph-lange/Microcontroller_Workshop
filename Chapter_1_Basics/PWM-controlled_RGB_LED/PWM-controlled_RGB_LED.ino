const int RED_PIN = 16;
const int GREEN_PIN = 17;
const int BLUE_PIN = 5;


void setup() {
  for (int pin : {RED_PIN, GREEN_PIN, BLUE_PIN}) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}


void loop() {
  for (int pin : {RED_PIN, GREEN_PIN, BLUE_PIN}) {
    for (int i = 255; i >= 0; --i) {
      analogWrite(pin, i);
      delay(4);
    }
    for (int i = 0; i <= 255; ++i) {
      analogWrite(pin, i);
      delay(4);
    }
  }
}
