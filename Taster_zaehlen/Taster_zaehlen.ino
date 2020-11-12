            /*
               Programm:          Taster Zählen
               Letzte Änderung:   11.11.20
               Programmierer:     LC
               Version:           1.0
               Bibliothek:        OneButton
            
               Hardware:      Arduino UNO / Taster 1 an Pin 11 , Taster 2 an Pin 12 / Beide Pull-Down
            */
            
            #include <OneButton.h>
            
            OneButton button1(2, false);             // Taster 1 erstellen und dem Pin 11 zuweisen
            OneButton button2(3, false);             // Taster 2 erstellen und dem Pin 12 zuweisen
            
            byte led[8] = {6, 7, 8, 9, 10, 11, 12, 13};
            
            int wert = 0;
            int index = -1;
            
            bool taster1Gedrueckt = false;
            bool taster2Gedrueckt = false;
            
            void setup()
            {
              Serial.begin(9600);
              button1.attachClick(Taster1);          // Sobald Taster 1 gedrückt wurde wird die Funktion Taster 1 ausgeführt
              button2.attachClick(Taster2);          // Sobald Taster 2 gedrückt wurde wird die Funktion Taster 2 ausgeführt
              for (byte i = 0; i < 8; i++)           // Ausgänge der LED's werden zugewiesen
              {
                pinMode (led[i], OUTPUT);
              }
            }
            
            void loop()
            {
              button1.tick();                        // Abfrage wann Taster 1 gedrückt wird
              button2.tick();                        // Abfrage wann Taster 2 gedrückt wird
              delay(10);
              if (taster1Gedrueckt == true)          // Schleife wird ausgeführt wenn Taster 1 gedrückt wurde
              {
                digitalWrite(led[index], LOW);       // In der Schleife soll zuerst der aktuelle Index auf LOW gesetzt                  
                wert++;                              // Dann wird der Index/Wert um 1 erhöht 
                index++;
                Serial.print("Zähler: ");
                Serial.println(wert);
                digitalWrite(led[index], HIGH);      // Anschließend wir dann der verminderte Index auf HIGH gesetzt
                taster1Gedrueckt = false;            // Merker wird wieder auf "false" gesetzt, damit die Schleife nur einmal durchläuft
              }
              else if (taster2Gedrueckt == true)     // Schleife wird ausgeführt wenn Taster 2 gedrückt wurde
              {
                digitalWrite(led[index], LOW);       // In der Schleife soll zuerst der aktuelle Index auf LOW gesetzt
                wert--;                              // Dann wird der Index/Wert um 1 vermindert
                index--;
                Serial.print("Zähler: ");
                Serial.println(wert);
                digitalWrite(led[index], HIGH);      // Anschließend wir dann der verminderte Index auf HIGH gesetzt
                taster2Gedrueckt = false;            // Merker wird wieder auf "false" gesetzt, damit die Schleife nur einmal durchläuft
              } 
            }
            
            void Taster1()                           // Funktion wird ausgeführt wenn Taster 1 gedrückt wurde
            {
              taster1Gedrueckt = !taster1Gedrueckt;  // Merker, dass Taster 1 gedrückt wurde wird negiert, damit
            }                                        // Schleife ausgeführt wird
            
            void Taster2()                           // Funktion wird ausgeführt wenn Taster 2 gedrückt wurde
            {
              taster2Gedrueckt = !taster2Gedrueckt;  // Merker, dass Taster 2 gedrückt wurde wird negiert, damit
            }                                        // Schleife ausgeführt wird
