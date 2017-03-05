/******************************************************************
* Programa: Ejemplo de uso del LCD Keypad Shield
*
* Objetivo:
*   Mostrar los aspectos básicos de funcionamiento del LCD Keypad Shield
*   Manejar una entrada analógica
*
* Aspectos a destacar:
*   -Lectura de la entrada analogica 
*
* Versión: 0.3 del 5 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/

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

int read_LCD_buttons(void);

/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup(void)
{
  lcd.begin(16, 2); // inicializo la biblioteca indicando 16 caracteres por 2 lineas
}


/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop(void)
{
  int lcd_key = 0;
  lcd.setCursor(0,0);
  lcd.print("Boton_v2:"); // imprime por el lcd
  lcd.setCursor(9,1); // mueve el cursor a la segunda linea "1" y lo desplaza "9" espacios
  lcd.print(millis()/1000); // muestra el tiempo transcurrido desde el encendido
  lcd.setCursor(0,1); // mueve el cursor a la primer linea "0" y lo desplaza "0" espacios
  lcd_key = read_LCD_buttons(); // read the buttons
  
  switch (lcd_key) // depending on which button was pushed, we perform an action
  {
     case btnRIGHT:
     {
       lcd.print("RIGHT   ");
       break;
     }
     case btnLEFT:
     {
       lcd.print("LEFT   ");
       break;
     }
     case btnUP:
     {
       lcd.print("UP     ");
       break;
     }
     case btnDOWN:
     {
       lcd.print("DOWN   ");
       break;
     }
     case btnSELECT:
     {
       lcd.print("SELECT");
       break;
     }
     case btnNONE:
     {
       lcd.print("NONE   ");
       break;
     }
  }
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
