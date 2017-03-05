
#include "stdarg.h";
#include <stdio.h>;


void setup() {
  Serial.begin(9600);
}

void serialPrintf(char *text, ...)
{
  char aux[100];
  va_list ap;
  va_start(ap,text);
  vsprintf(aux,text,ap);
  va_end(ap);
  Serial.print(aux);
}


void loop() 
{
  char auxiliar[]= "JUAN";
  serialPrintf("HOLA %s\n",auxiliar);
  delay(1000);
}
