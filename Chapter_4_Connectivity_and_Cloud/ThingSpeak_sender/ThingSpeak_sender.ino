#include <WiFi.h>  // Standard library from ESP32 platform.
#include <HTTPClient.h>  // Standard library from ESP32 platform.

const char* WIFI_SSID = "My_WiFi_SSID";
const char* WIFI_PASSWORD = "My_WiFi_password";
const char* THING_SPEAK_API_KEY = "";
const long THING_SPEAK_UPDATE_PERIOD = 15000;  // ThingSpeak limits updates to 15s, i.e., 15000ms.

WiFiClient wifiClient;
long timestampOfNextUpdate = 0;  // in [ms].


void connectToWiFi(int timeout = 5000) {
  Serial.printf("Connecting to WiFi '%s' ...\n", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() < startTime + timeout) {
    delay(100);
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.printf("Connected to '%s' with IP address %s.\n", WIFI_SSID, WiFi.localIP().toString().c_str());
  } else {
    Serial.printf("Connection to WiFi '%s' failed!\n", WIFI_SSID);
  }
}


bool sendHTTPRequest(String url) {
  boolean success = false;
  Serial.printf("Updating ThingSpeak with URL '%s' ...\n", url.c_str());
  HTTPClient http;
  http.begin(url.c_str());
  int response = http.GET();
  if (response == 200) {
    success = true;
    Serial.printf("Update transmitted successfully.\n");
  } else {
    Serial.printf("Update failed: HTTP error code is %d.\n", response);
  }
  http.end();
  return success;
}


void setup() {
  Serial.begin(115200);
  connectToWiFi();
}


void loop() {
  double uptime = millis() / 1000.0;  // in [s].
  float dummyValue = 50 + 25 * sin(uptime / 100) + 10 * sin(uptime / 10) + 10 * sin(uptime);

  if (millis() > timestampOfNextUpdate){
    String url = String("https://api.thingspeak.com/update?api_key=") + THING_SPEAK_API_KEY + "&field1=" + String(dummyValue);
    bool success = sendHTTPRequest(url);
    if (success) {
      timestampOfNextUpdate = millis() + THING_SPEAK_UPDATE_PERIOD;
    }
  }

  delay(1000);
}