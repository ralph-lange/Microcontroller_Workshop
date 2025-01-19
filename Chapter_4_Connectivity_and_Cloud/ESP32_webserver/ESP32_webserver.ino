#include <WiFi.h>  // Standard library from ESP32 platform.
#include <WiFiAP.h>
#include <WiFiClient.h>

#include "website.h"

const char* WIFI_SSID = "NameNetz";
const char* WIFI_PASSWORD = "11223344";
const IPAddress LOKALE_IP_ADRESSE(192, 168, 1, 1);
const IPAddress GATEWAY_IP_ADRESSE(192, 168, 1, 1);
const IPAddress SUBNETZ_MASKE(255, 255, 255, 0);
const int SERVER_PORT = 80;

float dummyValue = 0.0;
WiFiServer server(SERVER_PORT);


void setup() {
  Serial.begin(115200);
  WiFi.softAPConfig(LOKALE_IP_ADRESSE, GATEWAY_IP_ADRESSE, SUBNETZ_MASKE);
  WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);
  server.begin();
}


void processHTTPRequest(WiFiClient client, String request) {
  if (request.startsWith("GET ") && request.indexOf(" HTTP") > 4) {
    String uri = request.substring(4, request.indexOf(" HTTP"));
    Serial.printf("Received HTTP GET request for URI '%s'.\n", uri.c_str());

    if (uri == "/") {
      String website = WEBSITE;
      website.replace("[VALUE]", String(dummyValue, 2));
      website.replace("[UPTIME]", String((millis() / 1000.0), 1));    
      client.println("HTTP/1.1 200 OK");
      client.println("Content-type:text/html");
      client.println("Connection: close");
      client.println();
      client.println(website);
      client.println();
    } else {
      // Ignore all other requests.
    }
  }
}


String checkForHTTPRequest(WiFiClient client) {
  const int TIMEOUT = 250;
  String request = "";
  long startTime = millis();
  while (client.connected() && millis() < startTime + TIMEOUT) {
    if (client.available() > 0) {
      char c = client.read();
      if (c != '\r') {  // Ignore carriage return.
        request += c;
      }
      if (request.endsWith("\n\n")) {
        // A blank line marks the end of the request. Return the request.
        return request;
      }
    }
  }

  // No complete request found. Therefore return empty string.
  return "";
}


void loop() {
  double uptime = millis() / 1000.0;
  dummyValue = 50 + 25 * sin(uptime / 100) + 10 * sin(uptime / 10) + 10 * sin(uptime);
  Serial.printf("Dummy value is %4.2f.\n", dummyValue);

  WiFiClient client = server.available();
  if (client) {
    String request = checkForHTTPRequest(client);
    if (request != "") {
      // Serial.printf("Received HTTP request '%s'.\n", request.c_str());
      processHTTPRequest(client, request);
    }
    client.stop();
  }
  delay(250);
}
