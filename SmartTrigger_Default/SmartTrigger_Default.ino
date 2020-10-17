#include <stdlib.h>
#include <stdio.h>
#include <string.h>

  //GPOUT KARRERA AND INPUT_PULLUP ARDUINO
  int Serv1 = 10;
  int Serv2 = 12;
  
  //GPOUT ARDUINO AND SEALEVEL
  int Play = A0;
  int Stop_CueNext = A2;

void setup()
{  
  Serial.begin(9600);
  pinMode(Serv1, INPUT_PULLUP);
  pinMode(Serv2, INPUT_PULLUP);

  pinMode(Play, OUTPUT);
  pinMode(Stop_CueNext, OUTPUT);

  int p1= digitalRead(Serv1);
  int p2 = digitalRead(Serv2);
}

void loop()
{
    int p1= digitalRead(Serv1);
    int p2 = digitalRead(Serv2);
    String myString1 = String(p1);
    String myString2 = String(p2);
    if (myString1 == "1"){ myString1 = "OFF";} else{myString1="ON";}
    if (myString2 == "1"){ myString2 = "OFF";} else{myString2="ON";}
    
    Serial.println("Server 1: " + myString1);
    Serial.println("Server 2: " + myString2);
    if (p1 != 1 || p2 != 1)
    {
        Serial.println("PLAY"); //debug    
        digitalWrite(Play, HIGH);
        digitalWrite(Stop_CueNext, LOW);   
    }
    else
    {
        Serial.println("STOP_CUE_NEXT"); //debug
        digitalWrite(Play, LOW);
        digitalWrite(Stop_CueNext, HIGH);   
    }    
    delay(333);
}
