#include <stdlib.h>
#include <stdio.h>
#include <string.h>

  //GPOUT KARRERA AND INPUT_PULLUP ARDUINO
  int Serv1 = 10;
  int Serv2 = 12;

  int Reser1 = 8;
  int Reser2 = 9;

  int Change_Over = 13;

  //GPOUT ARDUINO AND SEALEVEL
  int Play = A0;
  int Stop_CueNext = A2;

  int p1;
  int p2;
  int r1;
  int r2;
  int s;

  
void setup()
{  
  Serial.begin(9600);
  pinMode(Serv1, INPUT_PULLUP);
  pinMode(Serv2, INPUT_PULLUP);
  pinMode(Reser1, INPUT_PULLUP);
  pinMode(Reser2, INPUT_PULLUP);
  
  pinMode(Change_Over, INPUT_PULLUP);

  pinMode(Play, OUTPUT);
  pinMode(Stop_CueNext, OUTPUT);
}

void loop()
{
     p1 = digitalRead(Serv1);
     p2 = digitalRead(Serv2);
     r1= digitalRead(Reser1);
     r2 = digitalRead(Reser2);
     s = digitalRead(Change_Over);

    String myString1 = String(p1);
    String myString2 = String(p2);
    String myString3 = String(r1);
    String myString4 = String(r2);

     String myString5 = String(s);

    
    if (myString1 == "1"){ myString1 = "OFF";} else{myString1="ON";}
    if (myString2 == "1"){ myString2 = "OFF";} else{myString2="ON";}

    if (myString3 == "1"){ myString3 = "OFF";} else{myString3="ON";}
    if (myString4 == "1"){ myString4 = "OFF";} else{myString4="ON";}

Serial.println("chg : " + myString5);
    
    Serial.println("Server 1: " + myString1);
    Serial.println("Server 2: " + myString2);
    Serial.println("Server R. 1: " + myString3);
    Serial.println("Server R. 2: " + myString4);
    

   if ( s == 1 )
    {
      Serial.println("chg : TITULAR");
           if (r1 != 1 || r2 != 1)
      {
        Serial.println("PLAY"); //debug    
        digitalWrite(Play, HIGH);
        digitalWrite(Stop_CueNext, LOW);   
      }
     else
      {
        Serial.println("CUE_NEXT"); //debug
        digitalWrite(Play, LOW);
        digitalWrite(Stop_CueNext, HIGH);   
      }
    }
    else
    {
    Serial.println("chg : RESERVA");
     if (p1 != 1 || p2 != 1)
      {
        Serial.println("PLAY"); //debug    
        digitalWrite(Play, HIGH);
        digitalWrite(Stop_CueNext, LOW);   
      }
     else
      {
        Serial.println("CUE_NEXT"); //debug
        digitalWrite(Play, LOW);
        digitalWrite(Stop_CueNext, HIGH);   
      }    

    }

    delay(333);
}
