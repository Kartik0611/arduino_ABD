#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
#include <BH1750.h>
#define LED_BUILTIN 13
BH1750 lightMeter;
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); // pass in a number for the sensor identifier (for your use later)
int i=0;
int j=0;

void setup(void) 
{
   
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));

  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin();
  if (tsl.begin()) 
  {
    Serial.println(F("Found a TSL2591 sensor"));
  } 
  else 
  {
    Serial.println(F("No sensor found ... check your wiring?"));
    while (1);
  }
  tsl.setGain(TSL2591_GAIN_LOW);    // 1x gain (bright light)
  tsl.setTiming(TSL2591_INTEGRATIONTIME_200MS);  // shortest integration time (bright light) , can also be st to 100MS
}


void loop(void) 
{ 
  while(true)
  {
    uint16_t x = tsl.getLuminosity(TSL2591_VISIBLE);
    Serial.print(F("[ ")); Serial.print(millis()); Serial.print(F(" ms ] "));
    Serial.print(F("Luminosity: "));
    Serial.println(x, DEC);
    delay(200);

    if(x>1800)   // Set to required threshold
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
                          j=j+1;
                          delay(100); 
                          
  
  
    } 
                  
    else
    {
                          if(j!=0)
                          {
                          Serial.print("size : ");
                          Serial.println(j);
                          }     
                          j=0;
                          digitalWrite(LED_BUILTIN, LOW);
                          delay(100); 
                          
  
     }
  
  }            
}         
      
         


