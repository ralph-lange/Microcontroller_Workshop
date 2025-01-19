#include "Adafruit_VL53L0X.h"  // Library 'Adafruit_VL53L0X' V1.2.4 by Adafruit

const float OUT_OF_RANGE_DISTANCE = 5.0;  // 5m indicates an out-of-range measurement.

Adafruit_VL53L0X sensor = Adafruit_VL53L0X();


void setup() {
  Serial.begin(115200);

  delay(100);  // Give ToF sensor 100ms to start.
  sensor.begin();
}


void loop() {
  float distance = OUT_OF_RANGE_DISTANCE;

  VL53L0X_RangingMeasurementData_t data;
  sensor.rangingTest(&data, false);
  if (data.RangeStatus != 4) {
    distance = data.RangeMilliMeter / 1000.0;
  }

  Serial.printf("%5.3f\n", distance);
   
  delay(250);
}
