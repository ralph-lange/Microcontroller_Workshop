const int LED_PINS[] = {16, 17, 5};
const int BUTTON_PIN = 23;
const int COLOR_CHANGE_PERIOD = 500;  // in [ms].


void setup() {
  Serial.begin(115200);

  for (int color = 0; color <= 2; ++color) {
    pinMode(LED_PINS[color], OUTPUT);
    digitalWrite(LED_PINS[color], HIGH);
  }

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}


void loop() {
  static int selectedColor = 0;  // Index from 0 to 2.
  static int timestampOfLastColorChange = 0;  // in [ms].

  if (millis() > timestampOfLastColorChange + COLOR_CHANGE_PERIOD && digitalRead(BUTTON_PIN) == LOW) {
      selectedColor = (selectedColor + 1) % 3;
      Serial.printf("Changed color index to %d.\n", selectedColor);
      timestampOfLastColorChange = millis();
  }

  for (int color = 0; color <= 2; ++color) {
    bool activateColor = (selectedColor == color);
    digitalWrite(LED_PINS[color], !activateColor);
  }
  delay(10);
}
