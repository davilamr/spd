#include <LiquidCrystal.h>

#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5

// Pines utilizados en la Mega2560
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Pines utilizados en la UNO
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  lcd.begin(16, 2); // inicializo la biblioteca indicando 16 caracteres por 2 lineas
}

// read the buttons
int read_LCD_buttons()
{
  int adc_key_in = 0;
  adc_key_in = analogRead(0); // kectura de la entrada analogica

  if (adc_key_in > 1000) 
    return btnNONE; 
  if (adc_key_in < 50) 
    return btnRIGHT;
  if (adc_key_in < 195) 
    return btnUP;
  if (adc_key_in < 380) 
    return btnDOWN;
  if (adc_key_in < 555) 
    return btnLEFT;
  if (adc_key_in < 790) 
    return btnSELECT;
    
  return btnNONE; // when all others fail, return this...
}

void loop()
{
  int lcd_key = 0;
  lcd.setCursor(0,0);
  lcd.print("Boton:"); // imprime por el lcd
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
