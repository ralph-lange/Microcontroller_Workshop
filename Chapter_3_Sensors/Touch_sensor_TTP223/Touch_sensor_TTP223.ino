const int TOUCH_PIN = 4;
const int LED_PIN = 5;

volatile bool ledState = false;


void IRAM_ATTR handleTouchPress() {
  ledState = !ledState;
}


void setup() {
  Serial.begin(115200);
  pinMode(TOUCH_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(TOUCH_PIN), handleTouchPress, RISING);
  pinMode(LED_PIN, OUTPUT);
}


void loop() {
  digitalWrite(LED_PIN, ledState);
  Serial.printf("LED state: %d\n", ledState);
  delay(250); 
}
