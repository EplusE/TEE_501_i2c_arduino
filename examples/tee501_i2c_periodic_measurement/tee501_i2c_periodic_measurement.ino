/*
Example script reading measurement values from the TEE501 sensor via I2C interface.

Copyright 2023 E+E Elektronik Ges.m.b.H.

Disclaimer:
This application example is non-binding and does not claim to be complete with regard
to configuration and equipment as well as all eventualities. The application example
is intended to provide assistance with the TEE501 sensor module design-in and is provided "as is".
You yourself are responsible for the proper operation of the products described.
This application example does not release you from the obligation to handle the product safely
during application, installation, operation and maintenance. By using this application example,
you acknowledge that we cannot be held liable for any damage beyond the liability regulations
described.

We reserve the right to make changes to this application example at any time without notice.
In case of discrepancies between the suggestions in this application example and other E+E
publications, such as catalogues, the content of the other documentation takes precedence.
We assume no liability for the information contained in this document.
*/



#include <tee501I2c.h>
#include <Wire.h>
tee501I2c tee(0x48);
#define REQUEST_INTERVAL_MS       100           //Time interval between measurements in ms
#define CSV_DELIMITER             ','


bool measurementReady;
float temperature, measurementTime;
unsigned char identification[8];
char errorString[200];
uint8_t errorcode; 


void setup() {
  Serial.begin(9600);               //Start Serial communication
  Wire.begin();                     //initialize I2C peripheral (SDA..A4, SCL..A5)
  delay(1000);
  tee.getErrorString(tee.findSensor(), errorString);
  Serial.println(errorString);
  errorcode = tee.changePeriodicMeasurementTime(2000);  // in ms 
  if(errorcode != 0)
  {
    tee.getErrorString(errorcode,errorString);
    Serial.println(errorString); 
  }
  else 
  {
     Serial.println("Changing the periodic measurement time was successful");  
  }
  tee.readPeriodicMeasurementTime(measurementTime);
  Serial.print("periodic measurement time is: ");
  Serial.print(measurementTime);
  Serial.println(" s");
  errorcode = tee.readIdentification(identification);
  if(errorcode != 0)
  {
    tee.getErrorString(errorcode,errorString);
    Serial.println(errorString); 
  }
  else 
  {
    Serial.print("Identificationnumber: ");
    for(int i = 0; i < 8; i++)
    {
      Serial.print(identification[i] < 16 ? "0" : "");
      Serial.print(identification[i],HEX);
    }
  }
  Serial.println("");
  tee.startPeriodicMeasurement();
  delay(2000); 
  Serial.println("temperature"); 
  delay(1000);
}


void loop() 
{ 
  errorcode = tee.newMeasurementReady(measurementReady);
  if(errorcode != 0)
  {
    
  }
  else
  {
    if(measurementReady)
    {
	  errorcode = tee.getPeriodicMeasurementTemp(temperature);
	  if(errorcode != 0)
      {
        tee.getErrorString(errorcode,errorString);
        Serial.println(errorString); 
      }
      else
      {
        Serial.print(temperature);
        Serial.println(" °C");         
      }
    }
  }
  delay(REQUEST_INTERVAL_MS);             //time until the next loop start 
}
