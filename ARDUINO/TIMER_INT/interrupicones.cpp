#include "interrupciones.h"   
void timerInt1(void)
 /*
  * rutina de atención de la interrupción del timer. 
  * Cambia el estado del LED y prende un flag para atender en Loop
  */
   {   
 
    ledState = !ledState ;
    f_timerInterrupt1 = 1;
 
   }

   void timerInt3(void)
 /*
  * rutina de atención de la interrupción del timer. 
  * Cambia el estado del LED y prende un flag para atender en Loop
  */
   {   
 
    ledState3 = !ledState3 ;
    f_timerInterrupt3 = 1;
 
   }
