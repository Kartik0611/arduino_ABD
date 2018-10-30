#include <Wire.h>
#include <BH1750.h>
#define LED_BUILTIN 13
BH1750 lightMeter;
int count=0;
int bubsize=0;
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
  int lux1; 
  int lux2;
  //for(k=1; k<100; k++)
  //{
    
    //lux[0]=0;
    
  //}
    


  
 lux1= lightMeter.readLightLevel();
 lux2= lightMeter.readLightLevel();
 //delay(100);
 Serial.println(lux1);
 Serial.println(lux2);
 delay(150);


 if((lux1-lux2)>100)
 {
                          digitalWrite(LED_BUILTIN, HIGH);
                          delay(200); 
                          digitalWrite(LED_BUILTIN, LOW);  
                          delay(200); 
                          count=count+1;  
                          Serial.print("count");             
                          Serial.println(count);
 }
 
 delay(150);
}            
          
      
         


