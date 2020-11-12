/*
   Programm:          Taster Zählen
   Letzte Änderung:   11.11.20
   Programmierer:     LC

   Hardware:      Arduino UNO / Taster 1 an Pin 11 , Taster 2 an Pin 12 / Beide Pull-Down
*/

#include <OneButton.h>

OneButton button1(1, false);                             // Taster 1 erstellen und dem Pin 11 zuweisen
OneButton button2(2, false);                             // Taster 2 erstellen und dem Pin 12 zuweisen

int wert = 0;


void setup()
{
  Serial.begin(9600);
  button1.attachClick(taster1);                           // Sobald Taster 1 gedrückt wird, wird die Funktion taster1() ausgeführt
  button2.attachClick(taster2);                           // Sobald Taster 2 gedrückt wird, wird die Funktion taster2() ausgeführt
}

void loop()
{
  button1.tick();                                         // Erfassung des Taster1-Klick
  button2.tick();                                         // Erfassung des Taster2-Klick
  delay(10);
}


void taster1()
{
  wert++;                                                 // Sobald der Taster 1 gdrückt wurde, wird die variable "wert" um 1 addiert
  Serial.print("Zähler: ");                               // Gleichzeitig wird der Zählerstand mithilfe der variable "wert" im seriellen Monitor angezeigt
  Serial.println(wert);
}



void taster2()
{
  wert--;                                                 // Sobald der Taster 2 gdrückt wurde, wird die variable "wert" um 1 subtrahiert
  Serial.print("Zähler: ");                               // Gleichzeitig wird der Zählerstand mithilfe der variable "wert" im seriellen Monitor angezeigt
  Serial.println(wert);
}
