/******************************************************************
* Programa: Ejemplo de uso del receptor IR
*
* Objetivo:
*   Mostrar los aspectos básicos del receptor IR
*
* Aspectos a destacar:
*   -Lectura y Decodificación

*
* Versión: 0.1 del 6 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/

#include "IRremote.h"

const int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;


/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Comienzo a recibir por IR
  irrecv.blink13(true);
}

/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop() {
  if (irrecv.decode(&results)) {
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
    Serial.println(results.value, HEX);
    irrecv.resume(); // Habilito a recibir el proximo dato
  }
}
