/******************************************************************
* Programa: Ejemplo de uso del LCD junto al puerto Serie
*
* Objetivo:
*   Mostrar los aspectos básicos del funcionamiento del Puerto Serie
*
* Aspectos a destacar:
*   -Escritura por el puerto serie
*   -Lectura por el puerto serie
*   -Escritura por LCD
*   -Lectura por el LCD
*
* Versión: 0.1 del 5 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/

#include "stdarg.h";
#include <LiquidCrystal.h>

#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5
#define MEGA

#ifdef MEGA
  LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Pines utilizados en la Mega2560
#else
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pines utilizados en la UNO
#endif

void serialPrintf(char *text, ...);
void serialScanf(char *text);
int read_LCD_buttons(void);

char msgs[5][15] = {"Right","Up","Down","Left","Select" };

/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup() {
  Serial.begin(9600); // Setea la velocidad del puerto Serie
  lcd.begin(16, 2); // inicializo la biblioteca indicando 16 caracteres por 2 lineas
}


/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop() 
{
  char rxBuffer[50];
  int lcd_key = 5;

  serialPrintf("\nPULSE UN BOTON\n");
  while(lcd_key == btnNONE)
  {
    lcd_key = read_LCD_buttons(); // read the buttons
  }
  serialPrintf("Se pulso -> %s\n",msgs[lcd_key]);
  
  serialPrintf("Ingrese un texto y finalice con el caracter -\n");
  serialScanf(rxBuffer);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print(rxBuffer); // imprime por el lcd

  
}

/** \brief  Emula el funcionamiento del printf.
 * \param Recibe un texto seguido por argumentos variables
 * \return void
 */
void serialPrintf(char *text, ...)
{
  char aux[100];
  va_list ap;
  va_start(ap,text);
  vsprintf(aux,text,ap);
  va_end(ap);
  Serial.print(aux);
}

/** \brief  Emula el funcionamiento del scanf.
 * \param Recibe un array char donde guardar los bytes que recibe por el puerto
 * \return void
 */
void serialScanf(char *text)
{
  char byteRecibido = 0;
  int i=0;
  
  while(byteRecibido != '-')
  {
    if (Serial.available() > 0) 
    {
      byteRecibido = Serial.read();
      text[i] = byteRecibido;
      i++;
    }
  }
  text[i-1] = '\0';
}

/** \brief  Realiza la lectura de la entrada analogica y determina según su valor
 *          a que botón hace referencia.
 * \param void
 * \return int: Que representa el botón pulsado
 */
int read_LCD_buttons(void)
{
  int lcd_key = btnNONE; // el valor inicial es NONE
  int adc_key_in = 0;
  adc_key_in = analogRead(0); // lectura de la entrada analogica

  if (adc_key_in > 1000)
    lcd_key = btnNONE; 
  else if (adc_key_in < 50) 
    lcd_key = btnRIGHT;
  else if (adc_key_in < 195) 
    lcd_key = btnUP;
  else if (adc_key_in < 380) 
    lcd_key = btnDOWN;
  else if (adc_key_in < 555)  
    lcd_key = btnLEFT;
  else if (adc_key_in < 790) 
    lcd_key = btnSELECT;

  return lcd_key; 
}
