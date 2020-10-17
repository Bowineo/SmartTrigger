#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#pragma region Variaveis
  //GPOUT KARRERA AND INPUT_PULLUP ARDUINO
  int Titular_1 = 10;
  int Titular_2 = 12;
  //GPOUT CROSSOVER AND INPUT_PULLUP ARDUINO
  int Reserva_1 = 8;
  int Reserva_2 = 9;
  int Change_Over = 13;
  //GPOUT ARDUINO AND SEALEVEL
  int Play = A0;
  int Stop_CueNext = A2;
  int chg;
#pragma endregion 

void setup()
{  
  Serial.begin(9600);
  pinMode(Titular_1, INPUT_PULLUP);
  pinMode(Titular_2, INPUT_PULLUP);
  pinMode(Reserva_1, INPUT_PULLUP);
  pinMode(Reserva_2, INPUT_PULLUP);
  pinMode(Change_Over, INPUT_PULLUP);
  pinMode(Play, OUTPUT);
  pinMode(Stop_CueNext, OUTPUT);
}

String Read(int input, bool debbugOn)
  {
    if (debbugOn){
      String temp = "";
      switch (input){
      case 10:
      if (String(digitalRead(input)) == "1"){temp = "OFF";} else{ temp= "ON";}
      Serial.println("Servidor Titular 1: " + temp);
      return temp;
      case 12:
      if (String(digitalRead(input)) == "1"){ temp = "OFF";} else{ temp= "ON";}
      Serial.println("Servidor Titular 2: " + temp);
      return temp;
      case 8:
      if (String(digitalRead(input)) == "1"){ temp = "OFF";} else{ temp= "ON";}
      Serial.println("Servidor Reserva 1: " + temp);
      return temp;
      case 9:
      if (String(digitalRead(input)) == "1"){ temp = "OFF";} else{ temp= "ON";}
      Serial.println("Servidor Reserva 2: " + temp);
      return temp;
      }
    }
    else{
      if (String(digitalRead(input)) == "1"){ return "OFF";} else{ return "ON";}
    }
  }  

void Write(String device_1, String device_2, bool debbugOn)
  {
    if (debbugOn){
      if (device_1 != "OFF" || device_2 != "OFF"){
       Serial.println("PLAY");    
       digitalWrite(Play, HIGH);
       digitalWrite(Stop_CueNext, LOW);   
      }
      else{
       Serial.println("CUE_NEXT");
       digitalWrite(Play, LOW);
       digitalWrite(Stop_CueNext, HIGH);   
      }
    }
    else{
      if (device_1 != "OFF" || device_2 != "OFF"){
       digitalWrite(Play, HIGH);
       digitalWrite(Stop_CueNext, LOW);   
      }
    else{
       digitalWrite(Play, LOW);
       digitalWrite(Stop_CueNext, HIGH);   
      } 
    }
  }

void loop()
{
  String _Titular_1 = Read(Titular_1, true);
  String _Titular_2 = Read(Titular_2, true);
  String _Reserva_1 = Read(Reserva_1, true);
  String _Reserva_2 = Read(Reserva_2, true);
  chg = digitalRead(Change_Over);
  if ( chg == 1 ){
   Serial.println("Seleção Change over: TITULAR");
   Write(Titular_1, Titular_2, true);
  }
  else{
   Serial.println("Seleção Change over: RESERVA");
   Write(Reserva_1, Reserva_2, true);
  }
   delay(333);
}
