//----------------------------------------------------------------------------
//    Este es nuestro primer programa con el LCD donde aprenderemos a utilizar 
//    las funciones minimas y necesarias para imprimir algo en pantalla
//    Autor: Konrad Peschka 2017
//----------------------------------------------------------------------------

//Cargamos las librerias encesarias
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);  //fijamos la direccion del LCD y aclaramos que es del tipo 16x2

void setup()
{
  lcd.init();  //inicializamos LCD
  lcd.backlight(); //prendemos la luz de backlight
  
}

void loop()
{
  lcd.setCursor(0,0);  //nos ubicamos en al posicion 0,0 del LCD
  lcd.print("Hola Mundo!");  //imprimimos mensaje
  lcd.setCursor(0,1);
  lcd.print("Como estas?");
}
