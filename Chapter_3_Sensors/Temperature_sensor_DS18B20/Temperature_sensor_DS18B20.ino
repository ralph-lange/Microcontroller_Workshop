#include <OneWire.h>  // Library 'OneWire' V2.3.8 by Jim Studt, Tom Pollard, et al.
#include <DallasTemperature.h>  // Library 'DallasTemperature' V3.9.0 by Miles Burton

const int ONE_WIRE_BUS = 4;
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);


void setup() {
  Serial.begin(115200);
  sensors.begin();
}


void loop() {
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  Serial.printf("%4.2f\n", temperature);
  delay(1000);
}
