//----------------------------------------------------------------------------
//    Este codigo se encarga de escanear todas las direccion i2c para
//    luego mostrarnos por el puerto serial cuales estan disponibles
//    Autor: Konrad Peschka 2017
//----------------------------------------------------------------------------
 
 //incluimos libreria wire que se encarga de la comunicacion i2c
#include <Wire.h>
 
 
void setup()
{
  Wire.begin();  //inicializa el WIRE
 
  Serial.begin(9600);  //inicializa comunicacion serial
  while (!Serial);     // Esto es solo para el Arduino Leonardo
  Serial.println("\nI2C Scanner");
}
 
 
void loop()
{
  byte error, address;
  int nDevices;
 
  Serial.println("Escaneando...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("Dispositivo I2C detectado en al direccion: 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Error desconocido en la direccion 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("Ningun dispositivo I2C encontrado!\n");
  else
    Serial.println("fin\n");
 
  delay(5000);           //espera 5 segundos hasta el proximo escaneo
}
