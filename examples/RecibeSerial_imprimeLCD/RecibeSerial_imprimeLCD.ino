//----------------------------------------------------------------------------
//    Este Codigo recibe texto por el puerto serie y lo imprime en LCD
//    Autor: Konrad Peschka 2017
//----------------------------------------------------------------------------

//defino librerias necesarias para establecer comunicacion i2c con la pantalla
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2); //configuramos la pantalla con su direccion y el tipo
//recordar que para obtener las direccion tenemos que usar el codigo
//que viene en los ejemplos y se llama:  scanner_i2c Scanner_direccion_i2c

void setup()
{
  lcd.init();        //inicializamos LCD
  lcd.backlight();   //activamos luz backlight
  Serial.begin(9600); //establecemos velocidad de comunicacion del puerto serie
  lcd.clear();   //borramos todo lo que esta escrito en el LCD
}

void loop()
{
  //entra en el if solo cuando llega algo por puerto serie
  if (Serial.available())
  {
    delay(100);    //esperamos un tiempo
    lcd.clear();   //borramos todo lo que esta escrito en el LCD
    while (Serial.available() > 0) //hace el WHILE mientras haya algo en el Buffer serial
    {
      lcd.write(Serial.read());  //imprimimos en LCD
    }
  }
}
