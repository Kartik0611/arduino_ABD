#include <Wire.h>
#include <BH1750.h>
#define LED_BUILTIN 13
BH1750 lightMeter;
int i=0;

void setup()
{
 
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));

}
void loop() 
{
  while(true)
  {
  int lux;
  lux= lightMeter.readLightLevel();
  Serial.println(lux);
  delay(150);
  if(lux>1800)
   {
  
                          digitalWrite(LED_BUILTIN, HIGH);
                          i=i+1;
                          delay(100); 
                          
  
  
  } 
                  
 else
  {
                          if(i!=0)
                          {
                          Serial.print("size : ");
                          Serial.println(i);
                          }     
                          i=0;
                          digitalWrite(LED_BUILTIN, LOW);
                          delay(100); 
                          
  
  }
  
}            
}         
      
         


