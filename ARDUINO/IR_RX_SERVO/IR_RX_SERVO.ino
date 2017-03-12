/******************************************************************
* Programa: Ejemplo de uso del receptor IR + SERVO
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
#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor;

const int RECV_PIN = 12;

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
  servoMotor.attach(9); 
}

/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop() {
  if (irrecv.decode(&results)) {
    if (results.decode_type == NEC && results.value == 0xfd50af) 
    {
      Serial.println("UP");
      servoMotor.write(0); // Desplazamos a la posición 0º
    } 
    else if (results.decode_type == NEC && results.value == 0xfd10ef) 
    {
      Serial.println("DOWN");
      servoMotor.write(90); // Desplazamos a la posición 0º
    } 
    irrecv.resume(); // Habilito a recibir el proximo dato
  }
}

