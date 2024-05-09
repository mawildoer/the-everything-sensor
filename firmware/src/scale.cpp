#include <Wire.h>

#include "SparkFun_Qwiic_Scale_NAU7802_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_NAU7802
#include <SparkFun_I2C_Mux_Arduino_Library.h>

QWIICMUX myMux;

NAU7802 myScale; // Create instance of the NAU7802 class

void setup()
{
  Serial.begin(115200);
  Serial.println("Qwiic Scale Example");

  Wire.setPins(7, 6);
  Wire.begin();

  if (myMux.begin(0x70) == false)
  {
    while (1)
    {
      Serial.println("I2C mux not detected. Freezing...");
      delay(1000);
    }
  }

  // Port 2 is the Nau7802
  myMux.setPort(2);

  if (myScale.begin() == false)
  {
    while (1)
    {
      Serial.println("Scale not detected. Please check wiring. Freezing...");
      delay(1000);
    }
  }
  Serial.println("Scale detected!");
}

void loop()
{
  if (myScale.available() == true)
  {
    int32_t currentReading = myScale.getReading();
    Serial.print(">Reading: ");
    Serial.println(currentReading);
  }
}
