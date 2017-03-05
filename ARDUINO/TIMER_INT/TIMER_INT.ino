/******************************************************************
* Programa: Ejemplo de uso de la interrupción por Timer
*
* Objetivo:
*   Mostrar los aspectos básicos de funcionamiento de una interrupción
*
* Aspectos a destacar:
*   -+ 
*
* Versión: 0.1 del 5 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/

#include <LiquidCrystal.h>
#include "TimerOne.h"
#define MEGA


#ifdef MEGA
  LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Pines utilizados en la Mega2560
#else
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pines utilizados en la UNO
#endif

int cuenta = 0;

/** \brief  Se invoca cada vez que el timer cuenta el tiempo seteado
 * \param void
 * \return void
 */
void timerHandler(void)
{
  cuenta++;
}

/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup(void)
{
  lcd.begin(16, 2); // inicializo la biblioteca indicando 16 caracteres por 2 lineas
         
  Timer1.initialize(100000);         // Tiempo en micro Segundos => 100000us == 100ms == 0,1s
  Timer1.attachInterrupt(timerHandler); // Activa la interrupcion y la asocia a la función que la atiende "timerHandler"
  
}



/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop(void)
{
  lcd.setCursor(0,0);
  lcd.print("Tiempo INI: "); // imprime por el lcd
  lcd.print(millis()/1000); // muestra el tiempo transcurrido desde el encendido

  lcd.setCursor(0,1);
  lcd.print("Tiempo TIM: "); // imprime por el lcd
  lcd.print(cuenta); // muestra el tiempo transcurrido desde el encendido
  
}


