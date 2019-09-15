// Test file for Git
// Marcus Arnett
// 9/14/2019

#include <Wire.h>
#include <SFE_BMP180.h>

SFE_BMP180 baro;

void setup() {
     Serial.begin(9600);
     bool success = baro.begin();

     if (success) {
     	Serial.println("Baro init is a go.");
	}
}

void loop() {
     char status;
     double T, P;
     bool success = false;

     status = baro.startTemperature();

     if (status != 0) {
     	delay(1000);
	status = baro.getTemperature(T);

	if (status != 0) {
	   status = baro.startPressure(1);

	   if (status != 0) {
	      delay(status);
	      status = baro.getPressure(P, T);

	      if (status != 0) {
	      	 Serial.print("The Pressure is: );
		 Serial.print(P);
		 serial.println(" hPa");
	      }
	   }
	}
     }
}