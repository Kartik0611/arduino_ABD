/* TSL2591 Digital Light Sensor */
/* Dynamic Range: 600M:1 */
/* Maximum Lux: 88K */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
#define LED_BUILTIN 13

// Example for demonstrating the TSL2591 library - public domain!

// connect SCL to I2C Clock
// connect SDA to I2C Data
// connect Vin to 3.3-5V DC
// connect GROUND to common ground

Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); // pass in a number for the sensor identifier (for your use later)
int i=0;

void setup(void) 
{
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
    int x = tsl.getLuminosity(TSL2591_VISIBLE);
    Serial.print(F("[ ")); Serial.print(millis()); Serial.print(F(" ms ] "));
    Serial.print(F("Luminosity: "));
    Serial.println(x);
    delay(200);

    if(x>3180)   // Set to required threshold
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
