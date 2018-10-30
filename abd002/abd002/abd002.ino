#include <Wire.h>
#include <BH1750.h>
#define LED_BUILTIN 13
BH1750 lightMeter;
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
  int i; 
  int k;
  int a=0;
  int lux[100];
  int j[100];
  j[0]=0;
  //for(k=1; k<100; k++)
  //{
    
    //lux[0]=0;
    
  //}
    
    
  Serial.print("Light: ");
 
  Serial.println(" lx");
  for(k=0; k<100; k++)
  {
    for(i=0; i<100; i++)
    {

      //Serial.println(i);
      lux[i]= lightMeter.readLightLevel();
      //Serial.println(lux[i]);
      delay(200);
   
      if(i=99)
      {
        j[k+1]=lux[i];
        Serial.print("i=");  
        Serial.println(i);
      }
   
      if(i=0)
      {
        a=lux[i]-j[k];
        Serial.print("i="); 
        Serial.println(i);
      }
      else
      {
        Serial.print("i="); 
        Serial.println(i);
        a=lux[i]-lux[i-1];
        if(lux[i]>2400)                // or if(lux[i]>2400 && (lux[i]-lux[i-1])>50)
        {
                     if(a>50 && i!=0)
                     {
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
              
                       
  }              
}            
          
      
         


