#include "interrupciones.h"


const int led = 13;  // the pin with a LED
const int ledVerde = 8;  // the pin with a LED
int ledState = LOW;    // El LED empieza apagado
int ledState3 = LOW;    // El LED empieza apagado
byte f_timerInterrupt1 = 0;
byte f_timerInterrupt3 = 0;

void setup(void)
   {
       pinMode(led, OUTPUT);
       pinMode(ledVerde, OUTPUT);
       Timer1.initialize(500000);         // Tiempo en micro Segundos
       Timer1.attachInterrupt(timerInt1); // Activa la interrupcion y la asocia a la función que la atiende "timerInt"

       Timer3.initialize(200000);         // Tiempo en micro Segundos
       Timer3.attachInterrupt(timerInt3); // Activa la interrupcion y la asocia a la función que la atiende "timerInt"

       
       digitalWrite(ledVerde, HIGH);
   }


   void loop(void)
   {
       if(f_timerInterrupt1 == 1)
       {
          digitalWrite(led, ledState);  // cambio de estado el led (le asigno HIGH o LOW dependiendo del valor que tomó en la ISR
          f_timerInterrupt1=0;
       }

       if(f_timerInterrupt3 == 1)
       {
          digitalWrite(ledVerde, ledState3);  // cambio de estado el led (le asigno HIGH o LOW dependiendo del valor que tomó en la ISR
          f_timerInterrupt3=0;
       }
   }
