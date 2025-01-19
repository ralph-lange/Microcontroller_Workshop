const int TRIGGER_PIN = 4;
const int ECHO_PIN = 5;


void setup() {
  Serial.begin(115200);
  pinMode(TRIGGER_PIN, OUTPUT); 
  digitalWrite(TRIGGER_PIN, LOW); 
  pinMode(ECHO_PIN, INPUT);
}


void loop() {
  digitalWrite(TRIGGER_PIN, HIGH); 
  delay(10);
  digitalWrite(TRIGGER_PIN, LOW); 
  const int TIMEOUT_US = 100000;  // 100us.
  int duration_ms = pulseIn(ECHO_PIN, HIGH, TIMEOUT_US);  // in [ms].
  float distance = (duration_ms / 2.0) * 0.000330; // in [m].
  Serial.printf("%4.2f\n", distance);
  delay(100);
}
