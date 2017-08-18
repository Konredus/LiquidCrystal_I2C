//----------------------------------------------------------------------------
//    Con este codigo vamos a crear 8 caracteres especiales
//    y luego vamos a imprimirlos en nuestro LCD
//    Autor: Konrad Peschka 2017
//----------------------------------------------------------------------------

//incluyo las librerias necesarias para el i2c

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//creo cada uno de los caracteres especiales

uint8_t campana[8] = {0b00000100,
                      0b00001110,
                      0b00001110,
                      0b00001110,
                      0b00011111,
                      0b00000000,
                      0b00000100
                     };

uint8_t nota[8] = {0b00000010,
                   0b00000011,
                   0b00000010,
                   0b00001110,
                   0b00011110,
                   0b00001100,
                   0b00000000
                  };

uint8_t reloj[8] = {0b00000000,
                    0b00001110,
                    0b00010101,
                    0b00010111,
                    0b00010001,
                    0b00001110,
                    0b00000000
                   };

uint8_t corazon[8] = {0b00000000,
                      0b00001010,
                      0b00011111,
                      0b00011111,
                      0b00001110,
                      0b00000100,
                      0b00000000
                     };

uint8_t pato[8] = {0b00000000,
                   0b00001110,
                   0b00011101,
                   0b00001111,
                   0b00001111,
                   0b00000110,
                   0b00000000
                  };

uint8_t ok[8] = {0b00000000,
                 0b00000001,
                 0b00000011,
                 0b00010110,
                 0b00011100,
                 0b00001000,
                 0b00000000
                };

uint8_t cruz[8] = {0b00000000,
                   0b00011011,
                   0b00001110,
                   0b00000100,
                   0b00001110,
                   0b00011011,
                   0b00000000
                  };

uint8_t enter[8] = {0b00000001,
                    0b00000001,
                    0b00000101,
                    0b00001001,
                    0b00011111,
                    0b00001000,
                    0b00000100
                   };


LiquidCrystal_I2C lcd(0x3f, 16, 2); //defino direccion del LCD y que es del tipo 16x2
//recordar que para obtener las direccion tenemos que usar el codigo
//que viene en los ejemplos y se llama:  scanner_i2c Scanner_direccion_i2c

void setup()
{
  lcd.init();  //inicializo LCD
  lcd.backlight();  //activo la luz de backlight

  //creo y cargo los caracteres especiales en el LCD
  lcd.createChar(0, campana);
  lcd.createChar(1, nota);
  lcd.createChar(2, reloj);
  lcd.createChar(3, corazon);
  lcd.createChar(4, pato);
  lcd.createChar(5, ok);
  lcd.createChar(6, cruz);
  lcd.createChar(7, enter);
  //lcd.home();

}


void loop()
{
  lcd.clear();          //borro completamente la pantalla
  lcd.setCursor(0, 0);  //me ubico en el 0,0 de la pantalla
  lcd.print("Hola,sabias que?"); //imprimo Mensaje
  lcd.setCursor(0, 1);  //me ubico en el 0,1 de la pantalla
  lcd.print(" yo ");
  lcd.write(3);
  lcd.print(" arduino!");
  delay(5000);  //espero un tiempo

  lcd.clear();//borro completamente la pantalla
  lcd.setCursor(0, 0);  //me ubico en el 0,0 de la pantalla
  lcd.print("Otros Caracteres"); //imprimo texto
  lcd.setCursor(0, 1);
  for (int j = 0; j < 8; j++)  //este for esta para repetir ciclo 8 veces
  {
    lcd.write(j); //imprimo todos los caracteres especiales de a uno
  }

  delay(4000); //espero un tiempo
}
