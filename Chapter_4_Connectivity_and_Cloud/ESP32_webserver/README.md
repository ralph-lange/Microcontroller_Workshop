# ESP32 als Webserver

Dieses Programm öffnet ein eigenes WLAN und stellt unter [http://192.168.1.1/](http://192.168.1.1/) einen minimalistischen Webserver bereit, dessen Webseite ein Dummy-Messwert zeigt. Der Dummy-Messwert bzw. die ganze Webseite wird sekündlich aktualisiert.

## Aufbau

Da ein Dummy-Messwert verwendet wird, ist kein Aufbau notwendig. Es kann das ESP32 DevKit oder auch der ESP32C3 Mini verwendet werden.

## Hinweise/Erläuterungen

Mit den Konstanten `WIFI_SSID` und `WIFI_PASSWORD` am Anfang von [ESP32_webserver.ino](ESP32_webserver.ino) kannst du deinem WLAN einen individuellen Namen und Passwort geben.

Mit dem Smartphone oder Laptop kann man sich leicht mit dem neuen WLAN verbinden und die Webseite unter [http://192.168.1.1/](http://192.168.1.1/) aufrufen. Auf dem Smartphone muss eventuell die Mobilfunk-Datenverbindung abgeschaltet werden, damit der Webserver korrekt gefunden wird.

## Aufgaben/Erweiterungen

* Könnt ihr den anderen Teams erklären, wie dieses Programm funktioniert und für welche Anwendungsfälle ein solches Stand-alone-WLAN nützlich sein könnte?
* Kannst du das Programm mit einem Programm aus Kapitel 3 kombinieren, so dass ein richtiger Messwert ausgegeben wird?
* Wenn man die Webseite in [website.h](website.h) mit Links oder Schaltflächen erweitert, so kann man über die Variable `uri` in `processHTTPRequest` auch den Klick auf einen Link / eine Schaltfläche identifizieren und zum Beispiel einen Ausgang des ESP32 schalten.
