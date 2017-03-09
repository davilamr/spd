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
int stepsPerRevolution = 1024;
Stepper motor(stepsPerRevolution, 10,11,12,13);

/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup() 
{
  motor.setSpeed(20); 
}

/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop() 
{  
    int steps = -1024;
    motor.step(steps);
    delay(5000);

    steps = 200;
    motor.step(steps);
    delay(1000); //Semicolon added
}
