//----------------------------------------------------------------------------
//    Este Codigo vamos a ver la forma de utilizar 2 LCD en simultaneo
//    Autor: Konrad Peschka 2017
//----------------------------------------------------------------------------

//declaro librerias necesarias para manejar LCD por i2c
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd1(0x26,16,2);  //defino LCD1 con su direccion
LiquidCrystal_I2C lcd2(0x27,16,2);  //defino LCD2 con su direccion
//recordar que para obtener las direccion tenemos que usar el codigo
//que viene en los ejemplos y se llama:  scanner_i2c Scanner_direccion_i2c
 
void setup()
{
  lcd1.init();        // inicializo lcd1
  lcd2.init();        // inicializo lcd1
 
  lcd1.backlight();  //activo luz backlight del lcd1
  lcd2.backlight();  //activo luz backlight del lcd2 
}
 
void loop()
{
     lcd1.setCursor(0,0);        //me posiciono en 0,0 del LCD1
     lcd1.print("Hola mundo!");  //imprimo mensaje en LCD1
     lcd1.setCursor(0,1);
     lcd1.print("Desde LCD #1");
     
     lcd2.setCursor(0,0);        //me posiciono en 0,0 del LCD2
     lcd2.print("Hola Mundo");   //imprimo mensaje en LCD2
     lcd2.setCursor(0,1);
     lcd2.print("Desde LCD #2");
}
