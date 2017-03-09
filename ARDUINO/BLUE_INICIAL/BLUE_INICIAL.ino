/******************************************************************
* Programa: Ejemplo de uso del módulo Bluetooth HC-06
*
* Objetivo:
*   Mostrar los aspectos básicos de funcionamiento del módulo Bluetooth HC-06
*
* Aspectos a destacar:
*   -Recepcion de comandos via puerto serie 
*   -Interaccion con la App BT Serial Controller
*
* Versión: 0.1 del 8 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/

/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}


/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */ 
void loop()
{
  //Verifica si se recibio algo
  if(Serial.available() >= 1)
  {
    char valor = Serial.read(); 
    
    if(valor == 'E')
    {
      digitalWrite(13, HIGH);
    }
    else if(valor == 'A')
    {
      digitalWrite(13, LOW);
    }
  }
}
