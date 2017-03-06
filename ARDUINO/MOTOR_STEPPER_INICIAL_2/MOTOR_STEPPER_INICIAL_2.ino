/******************************************************************
* Programa: Ejemplo de uso del motor paso a paso
*
* Objetivo:
*   Mostrar los aspectos básicos de funcionamiento de un paso a paso
*
* Aspectos a destacar:
*   -Escritura de salidas digitales

*
* Versión: 0.1 del 6 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/
#include <Stepper.h>
int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 10,11,12,13);


/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup() {
  
}

/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop() 
{  
  myStepper.setSpeed(100);
  myStepper.step(200); 
  delay(1000);
}
