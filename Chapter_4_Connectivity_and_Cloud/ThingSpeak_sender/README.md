# ThingSpeak-Sender

Dieses Programm verbindet sich mit der Cloud-Plattform [ThingSpeak](https://thingspeak.com/) und übermittelt alle 15 Sekunden einen Dummy-Messwert zwischen 0 und 100 an diese.

## Aufbau

Da ein Dummy-Messwert verwendet wird, ist kein Aufbau notwendig. Es kann das ESP32 DevKit oder auch der ESP32C3 Mini verwendet werden.

## Hinweise/Erläuterungen

Setze die Konstanten `WIFI_SSID` und `WIFI_PASSWORD` am Anfang von [ThingSpeak_sender.ino](ThingSpeak_sender.ino) korrekt auf das hier verwendete WLAN.

Logge dich mit deinem Account auf [https://thingspeak.com/](https://thingspeak.com/) ein, erstelle einen neuen Channel und benenne das *Field 1* in `dummyValue` um. Kopiere anschließend den *Write API Key* aus dem Tab *API Keys* und füge diesen in die Konstante `THING_SPEAK_API_KEY` ein.

## Aufgaben/Erweiterungen

* Könnt ihr den anderen Teams erklären, wie dieses Programm funktioniert und für welche Anwendungsfälle ThingSpeak nützlich sein könnte?
* Kannst du das Programm mit einem Programm aus Kapitel 3 kombinieren, so dass ein richtiger Messwert ausgegeben wird?
* In den Tabs *Private View* und *Public View* kannst du eigene Visualisierungen für die Messwerte erstellen. Unter *Sharing* kann der Channel so eingestellt werden, dass die *Public View* auch ohne Login einsehbar ist.
