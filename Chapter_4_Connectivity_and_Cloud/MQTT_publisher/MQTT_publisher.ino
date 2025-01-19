#include <WiFi.h>  // Standard library from ESP32 platform.
#include <PubSubClient.h>  // Library 'PubSubClient' V2.8 by Nick O'Leary.

const char* WIFI_SSID = "My_WiFi_SSID";
const char* WIFI_PASSWORD = "My_WiFi_password";
const char* MQTT_SERVER_IP = "192.168.1.150";
const int MQTT_SERVER_PORT = 1883;
const char* MQTT_CLIENT_NAME ="name_ESP32";
const char* MQTT_TOPIC = "name/dummy-value";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);


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


void connectToMQTTServer(int timeout = 5000) {
  Serial.printf("Connecting to MQTT server '%s:%d' ...\n", MQTT_SERVER_IP, MQTT_SERVER_PORT);
  mqttClient.setServer(MQTT_SERVER_IP, MQTT_SERVER_PORT); 
  long startTime = millis();
  while (!mqttClient.connected() && millis() < startTime + timeout) {
    if (!mqttClient.connect(MQTT_CLIENT_NAME)) {
      Serial.printf("Attempt failed with reason '%d'!\n", mqttClient.state());
      delay(1000);
    }
  }
  if (mqttClient.connected()) {
    Serial.printf("Connection to MQTT server '%s:%d' established.\n", MQTT_SERVER_IP, MQTT_SERVER_PORT);
  } else {
    Serial.printf("Connection to MQTT server '%s:%d' failed!\n", MQTT_SERVER_IP, MQTT_SERVER_PORT);
  }
}


void setup() {
  Serial.begin(115200);
  connectToWiFi();
  connectToMQTTServer();
}


void loop() {
  double uptime = millis() / 1000.0;  // in [s].
  float dummyValue = 50 + 25 * sin(uptime / 100) + 10 * sin(uptime / 10) + 10 * sin(uptime);
  bool wasMessageSent = mqttClient.publish(MQTT_TOPIC, String(dummyValue).c_str());
  if (wasMessageSent) {
    Serial.printf("MQTT message with dummy value is %4.2f was sent successfully.\n", dummyValue);
  } else {
    Serial.printf("MQTT message with dummy value is %4.2f could not be sent.\n", dummyValue);
  }
  delay(1000);
}