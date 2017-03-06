/******************************************************************
* Programa: Ejemplo de uso del emisor IR, el led se debe conectar en 
*           el  PWM pin 3
*
* Objetivo:
*   Mostrar los aspectos básicos del emisor IR
*
* Aspectos a destacar:
*   -Envia un comando por IR

*
* Versión: 0.1 del 6 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/

#include "IRremote.h"


/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
IRsend irsend;
void setup()
{
  Serial.begin(9600);
}

/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop() {
  if (Serial.read() != -1) {
    for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xa90, 12); // Sony TV power code
      delay(40);
    }
  }
}
