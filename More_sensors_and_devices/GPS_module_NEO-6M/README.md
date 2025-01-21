# GPS-Modul NEO-6M

Das GPS-Modul NEO-6M ist ein (inzwischen älterer) typischer GPS-Empfänger, der das NMEA-Protokoll unterstützt.

## Aufbau

Schließe das NEO-6M wie folgt an den ESP32 an: GND an GND, TX an Pin 16, RX an Pin 17 und VCC and 3V3.

![Foto des Aufbaus](setup.jpg)

## Datenblatt

Siehe [www.u-blox.com/en/product/neo-6-series](https://www.u-blox.com/en/product/neo-6-series).

## Hinweise/Erläuterungen

Es dauert einige Minuten bis das GPS-Modul alle notwendigen Bahndaten (den *Almanach*) von den GPS-Satelliten empfangen hat, um eine Position zu berechnen. Geräten mit Internetverbindung (z.B. Smartphone) geht das schneller, weil sie Almanach über Internet-Dienste empfangen können.
