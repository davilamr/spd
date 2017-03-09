/* Programa de configuracion del modulo HC 06 con Arduino
 * Cambia el nombre del dispositivo, el PIN y los baudios
 *
 * Escrito por Transductor
 * www.robologs.net
 */
char nombre[10] = "ArduinoR";
char password[10] = "0000";
char baud = '4'; //4 = 9600 baud
 
void setup()
{
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  delay(15000); //Esperar 15 segundos para conectar el modulo
  
  Serial.print("AT"); //Iniciar la configuracion
  delay(1000);
  
  Serial.print("AT+NAME"); Serial.print(nombre); //Cambiar el nombre
  delay(1000);
  
  Serial.print("AT+PIN"); Serial.print(password); //Cambiar contrasena
  delay(1000);    
  
  Serial.print("AT+BAUD"); Serial.print(baud); //Cambiar baudios
  delay(1000);
  
  digitalWrite(13, HIGH);
}
 
void loop(){}
