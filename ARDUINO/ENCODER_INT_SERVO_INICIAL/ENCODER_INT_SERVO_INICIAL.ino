/******************************************************************
* Programa: Ejemplo de uso del encoder junto al Servo SG90
*
* Objetivo:
*   Mostrar los aspectos básicos del funcionamiento del Encoder
*
* Aspectos a destacar:
*   -Controlar un servo motor
* Info:
*   https://www.luisllamas.es/arduino-encoder-rotativo/
*   
* Versión: 0.1 del 8 de marzo de 2017
* Autor: Mauricio Dávila
* Revisión: -
*
* *******************************************************************/
#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor;

const int channelPinA = 2;
const int channelPinB = 3;
 
const int timeThreshold = 5;
long timeCounter = 0;
 
const int maxSteps = 179;
volatile int ISRCounter = 0;
int counter = 0;
 
bool IsCW = true;

/** \brief  Se invoca una sola vez cuando el programa empieza. 
*          Se utiliza para inicializar los modos de trabajo 
*          de los pines, el puerto serie, etc... 
* \param void
* \return void
*/
void setup()
{
  pinMode(channelPinA, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(channelPinA), doEncodeA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(channelPinB), doEncodeB, CHANGE);

  servoMotor.attach(9); 
}
 
void loop()
{
  if (counter != ISRCounter)
  {
    counter = ISRCounter;
    Serial.println(counter);
    servoMotor.write(180-counter);
  }
  delay(100);
}

/** \brief  Contiene el programa que se ejecutará cíclicamente
*          
* \param void
* \return void
*/
void doEncodeA()
{
 if (millis() > timeCounter + timeThreshold)
 {
    if (digitalRead(channelPinA) == digitalRead(channelPinB))
    {
      IsCW = true;
      if (ISRCounter + 1 <= maxSteps) ISRCounter++;
    }
    else
    {
      IsCW = false;
      if (ISRCounter - 1 > 0) ISRCounter--;
    }
    timeCounter = millis();
  }
}
 
void doEncodeB()
{
  if (millis() > timeCounter + timeThreshold)
  {
      if (digitalRead(channelPinA) != digitalRead(channelPinB))
      {
          IsCW = true;
          if (ISRCounter + 1 <= maxSteps) ISRCounter++;
      }
      else
      {
          IsCW = false;
          if (ISRCounter - 1 > 0) ISRCounter--;
      }
      timeCounter = millis();
  }
}
