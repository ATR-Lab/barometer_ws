#include <Wire.h>
#include <SFE_BMP180.h>

SFE_BMP180 bmp180;

int Altitude = 322; //current altitude in meters

void setup() {
  Serial.begin(9600);
  bool success = bmp180.begin();

  if (success) {
    Serial.println("BMP180 init success");
  }
}

void loop() {

  char status;
  double T, P;
  bool success = false;

  status = bmp180.startTemperature();

  if (status != 0) {
    delay(1000);
    status = bmp180.getTemperature(T);

    if (status != 0) {
      status = bmp180.startPressure(1);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);

        if (status != 0) {
          // float comp = bmp180.sealevel(P, Altitude);
          
          Serial.print("Pressure: ");
          // Serial.print(comp);
          Serial.print(P);
          Serial.println(" hPa");

          // Serial.print("Temperature: ");
          // Serial.print(T);
          // Serial.println(" C");
        }
      }
    }
  }
}
