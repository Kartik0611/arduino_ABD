#include <Wire.h>
#include <BH1750.h>
#define LED_BUILTIN 13
BH1750 lightMeter;
int count=-1;
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
  int i; 
  int a=0;
  int lux[100];
  lux[0]=0;
  Serial.print("Light: ");
 
  Serial.println(" lx");
  for(i=1; i<100; i++)
  {
   lux[i]= lightMeter.readLightLevel();
   Serial.println(lux[i]);
   delay(200);
   a=lux[i]-lux[i-1];
   if(lux[i]>2400){                // or if(lux[i]>2400 && (lux[i]-lux[i-1])>50)
               if(a>50){
                    digitalWrite(LED_BUILTIN, HIGH);
                    delay(200); 
                    digitalWrite(LED_BUILTIN, LOW);  
                    delay(200); 
                    count=count+1;  
                    Serial.print("count");             
                    Serial.println(count);
               }
   }
           
  }          
              
                       
}              
              
          
      
         


