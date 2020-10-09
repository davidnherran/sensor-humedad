#include "LedControlMS.h" 

LedControl lc=LedControl(12,11,10,1);
 
const int humedad = A0;

byte Cara_datos[] = 
 
{B00111100,
 
B01000010,
 
B10100101,
 
B10000001,
 
B10100101,
 
B10011001,
 
B01000010,
 
B00111100};

byte Cara_tristelina[] = 
 
{B00111100,
 
B01000010,
 
B10100101,
 
B10000001,

B10011001,
 
B10100101,
 
B01000010,
 
B00111100};
 
void setup()
{
  pinMode(humedad, INPUT);
  lc.shutdown(0,false);
  lc.setIntensity(0,2);// Entre 1 y 15 
  lc.clearDisplay(0);
}
 
void loop()
{
  trans();
  delay(500);
 
  int SensorValue = analogRead(humedad); //take a sample
  Serial.print(SensorValue); Serial.print(" - ");
  
  if(SensorValue <= 901) 
  {
   Representar(Cara_datos,3000);
   delay(1000);
  }
  
  if(SensorValue >= 900) 
  {
   Representar(Cara_tristelina,3000);
   delay(1000);
  }

  lc.clearDisplay(0);
}
 
void trans(){ 
  
  for (int row=0; row<8; row++)
 
  {
 
    for (int col=0; col<8; col++)
 
    {
 
      lc.setLed(0,col,row,false);
 
      delay(25);
 
    }
 
  }
 
} 
 
void Representar(byte *Datos,int retardo)
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setColumn(0,i,Datos[7-i]);
  }
  delay(retardo);
}