# MQTT-Publisher

Dieses Programm verbindet sich mit einem [MQTT](https://de.wikipedia.org/wiki/MQTT)-Server – auch „MQTT-Broker“ genannt, wie z.B. [Eclipse Mosquitto](https://mosquitto.org/) – und übermittelt auf dem *Topic* `name/dummy-value` sekündlich einen Dummy-Messwert zwischen 0 und 100.

## Aufbau

Da ein Dummy-Messwert verwendet wird, ist kein Aufbau notwendig. Es kann das ESP32 DevKit oder auch der ESP32C3 Mini verwendet werden.

## Hinweise/Erläuterungen

Setze die Konstanten `WIFI_SSID` und `WIFI_PASSWORD` am Anfang von [MQTT_publisher.ino](MQTT_publisher.ino) korrekt auf das hier verwendete WLAN. Passt ggf. auch `MQTT_SERVER_IP` an.

Wenn du deinen Laptop oder dein Smartphone mit demselben WLAN verbindest, so kannst du über geeignete Apps (z.B. [*MQTT Explorer*](http://mqtt-explorer.com/) für Windows oder [*IoT MQTT Panel*](https://play.google.com/store/apps/details?id=snr.lab.iotmqttpanel.prod) für Android) die Dummy-Messwerte des Topics verfolgen und auch plotten lassen.

## Aufgaben/Erweiterungen

* Könnt ihr den anderen Teams erklären, wie dieses Programm funktioniert und für welche Anwendungsfälle MQTT nützlich sein könnte?
* Kannst du das Programm mit einem Programm aus Kapitel 3 kombinieren, so dass ein richtiger Messwert ausgegeben wird?
* Man kann auf dem ESP32 auch einen MQTT-Subscriber erzeugen, der auf eingehende Nachrichten reagiert und einen Ausgang des ESP32 schaltet.
