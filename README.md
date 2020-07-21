# FunktionenSchieben  

Verwendeter Mikrocontroller:
- ESP32 (genauer das Modell "Himalaya", ein Modell mit LiPo Laderegler empfehlenswert)

Verwendete Bibliotheken:  
- https://github.com/pololu/vl53l0x-arduino  

- https://github.com/Dorsel89/phyphox-arduino 

# Hardware Installation
Der Distanzsensor wird in diesem Projekt über die Schnittstelle I2C wie folgt angeschlossen:

ESP32 <-> VL53L0X board  
3.3V <-> VIN  
GND <-> GND  
GPIO 21 <-> SDA (zusätzlich ist ein Pull-Up Widerstand oft nötig -> 2.2kOhm von SDA auf 3.3V) 
GPIO 22 <-> SCL (zusätzlich ist ein Pull-Up Widerstand oft nötig -> 2.2kOhm von SCL auf 3.3V) 

Die Pin-Nummer beziehen sich auf den ESP32 Hiamalaya. Eine PinList für den ESP32 Himalaya findet sich in der Datei "ESP32 Himalaya PinList.pdf" in diesem Repository.

# Software Installation:
- In der Arduino IDE kann über "Sketch" -> "Bibliothek einbinden" ->  "Bibliotheken Verwalten" der Bibliotheksverwalter geöffnet werden. Darüber lässt sich ide vl5310x Bibliothek von polulu finden und installieren. Die phyphox Bibliothek ist zum aktuellen Stand (Juli 2020) noch nicht über den Bibliotheksverwalter zu finden. Die Bibliothek kann aber aus dem oben verlinkten Repository heruntergeladen werden (als Zip Datei). Anschließend kann die Bibliothek in der Arduino IDE über "Sketch" -> "Bibliothek einbinden" -> ".Zip Bibliothek hinzufügen" installiert werden.

- Zusätzlich muss noch der Boardtreiber für einen ESP32 Mikrocontroller installiert werden. Dazu in der Arduino-IDE auf "Werkzeuge" - > "Board" - > "Boardverwalter" klicken und in das Suchfeld nach "ESP32" eintippen und die vorgeschlagene Bibliothek installieren.

Sobald die verwendeten Bibliotheken installiert sind kann der verwendete ESP32 unter "Werkzeuge" -> "Board" ausgewählt werden und der Arduino Sketch übertragen werden.
