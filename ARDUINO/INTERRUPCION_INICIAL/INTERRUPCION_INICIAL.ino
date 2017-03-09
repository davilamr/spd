/******************************************************************
* Programa: Ejemplo de uso de interrupciones
*
* Objetivo:
*   Mostrar los aspectos básicos del funcionamiento de las interrupciones
*
* Aspectos a destacar:
*   -Qué entradas tienen interrupciones
*   -Casos de uso
*   
* Info:
*   https://www.luisllamas.es/arduino-encoder-rotativo/
*   
* Versión: 0.1 del 8 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/

#define PIN_INT_A 2
#define PIN_INT_B 3
/** \brief  Se invoca una sola vez cuando el programa empieza. 
*          Se utiliza para inicializar los modos de trabajo 
*          de los pines, el puerto serie, etc... 
* \param void
* \return void
*/
void setup()
{
  Serial.begin(9600);
  pinMode(PIN_INT_A, INPUT_PULLUP);
  pinMode(PIN_INT_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_INT_A), send_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_INT_B), send_B, CHANGE);
}

/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */ 
void loop()
{
}

/** \brief  Envia por el puerto serie
*          
* \param void
* \return void
*/
void send_A()
{
  Serial.println("INT PIN 2");
  delay(500);
}

/** \brief  Envia por el puerto serie
*          
* \param void
* \return void
*/
void send_B()
{
  Serial.println("INT PIN 3");
  delay(500);
}
 
