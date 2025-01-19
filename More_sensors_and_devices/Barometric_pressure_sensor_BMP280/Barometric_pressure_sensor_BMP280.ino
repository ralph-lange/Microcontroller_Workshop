#include <Adafruit_BMP280.h>  // Library 'Adafruit BMP280 Library' V2.6.8 by Adafruit.

Adafruit_BMP280 sensor;


void setup() {
  Serial.begin(115200);
  sensor.begin();
}


void loop() {
  float temperature = sensor.readTemperature();
  Serial.printf("Temperature: %3.1f °C\n", temperature);

  float pressure = sensor.readPressure() / 100.0;  // Divide by 100 to convert from pascals to hectopascals, i.e., millibar.
  Serial.printf("Luftdruck: %3.1f hPa\n", pressure);

  delay(1000);
}