#include <GxEPD2_BW.h>  // Library 'GxEPD2' V.1.6.1 by Jean-Marc Zingg.
#include <Fonts/FreeSansBold24pt7b.h>

const int PIN_BUSY = 27;
const int PIN_RST = 33;
const int PIN_DC = 25;
const int PIN_CS = 26;
const int PIN_CLK = 18;  // = SCK
const int PIN_DIN = 23;  // = MOSI
                                                                      
GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(PIN_CS, PIN_DC, PIN_RST, PIN_BUSY));


void setup() {
  Serial.begin(115200);

  Serial.printf("Initializing display ...");
  display.init();
  Serial.printf(" done.\n");
}


void loop() {
  display.setFullWindow();
  display.setRotation(2);
  display.setTextColor(GxEPD_BLACK);

  Serial.printf("Drawing string 'Test!', line, and circle.\n");
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setFont(&FreeSansBold24pt7b);
    display.setCursor(0, 64);
    display.print("Test!");
    display.drawLine(10, 100, 190, 120, GxEPD_BLACK);
    display.fillCircle(30, 170, 25, GxEPD_BLACK);
  } while (display.nextPage());
  Serial.printf("Powering off the display ...");
  display.powerOff();
  Serial.printf(" done.\n");

  delay(10000);

  Serial.printf("Drawing blank screen.\n");
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
  } while (display.nextPage());
  Serial.printf("Powering off the display ...");
  display.powerOff();
  Serial.printf(" done.\n");

  delay(10000);

  ESP.restart();
}
