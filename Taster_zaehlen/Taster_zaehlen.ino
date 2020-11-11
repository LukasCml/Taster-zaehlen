/*
   Programm:          Taster Zählen
   Letzte Änderung:   11.11.20
   Programmierer:     LC

   Hardware:      Arduino UNO / Taster 1 an Pin 11 , Taster 2 an Pin 12 / Beide Pull-Down
*/

#include <OneButton.h>

OneButton button1(11, false);                             // Taster 1 erstellen und dem Pin 11 zuweisen
OneButton button2(12, false);                             // Taster 2 erstellen und dem Pin 12 zuweisen

#define Taster1 11
#define Taster2 12

bool taster1gedrueckt = false;
bool taster2gedrueckt = false;

int wert = 0;



void setup()
{
  Serial.begin(9600);
  pinMode(Taster1, INPUT);
  pinMode(Taster2, INPUT);
  button1.attachClick(taster1);
  button2.attachClick(taster2);
}

void loop()
{
  button1.tick();
  button2.tick();
  {
    Serial.println(wert);
  }
  delay(10);
}


void taster1()
{
 wert++;
}



void taster2()
{
  wert--;
}
