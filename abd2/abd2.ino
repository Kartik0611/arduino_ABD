#include <Wire.h>
#include <BH1750.h>
#define LED_BUILTIN 13
BH1750 lightMeter;
int i=1;
int count=0;

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
  float lux[100];
  lux[0]=0;
  //Serial.print("Light: ");
 
  //Serial.println(" lx");
  
  
  lux[i]= lightMeter.readLightLevel();
  delay(200);
  Serial.println(lux[i]);
  delay(200);
  
 
  if((lux[i]>2400) && (lux[i]-lux[i-1])>50)
             
              
               {
                   digitalWrite(LED_BUILTIN, HIGH);
                   delay(200); 
                   digitalWrite(LED_BUILTIN, LOW);  
                   delay(200); 
                   count=count+1;  
                   //Serial.print("count");             
                   Serial.println(count);
                }
            
          i=i+1;    
                       
}              
              
          
      
         


