/******************************************************************
* Programa: Ejemplo de uso de las salidas digitales
*
* Objetivo:
*   Mostrar los aspectos básicos de las salidas digitales
*  Mostrar la rotacion de bits y las mascaras 
*
* Aspectos a destacar:
*   -unsigned char vs char
*   -carga de numeros como binarios
*   -mascaras a nivel de bit
*
* Versión: 0.1 del 12 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/

int outPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
char outMask[] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000};


unsigned char knightLight = 0b00000001;
bool directionUp = true;


/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup()
{
  for(int p = 0; p < 8; p++) {
    pinMode(outPins[p], OUTPUT);
  }
}

/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop() {
  
    for(int p = 0; p < 8; p++) 
    {
      if(knightLight & outMask[p]) 
        {
          digitalWrite(outPins[p], HIGH);
        }
        else
        {
          digitalWrite(outPins[p], LOW);
        }
    }
  delay(500);
  
    if(knightLight == 0b10000000)
    {
      directionUp = false;
    }
  
    if(knightLight == 0b00000001)
    {
      directionUp = true;
    }
  
    if(directionUp)
    {
    knightLight = knightLight << 1;
    }
    else
    {
    knightLight = knightLight >> 1;
    }     
  
      
}
