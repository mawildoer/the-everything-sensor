#include <Arduino.h>
#include <Wire.h>

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
}

void loop()
{
    Serial.println("Hello World");
    delay(1000);
}
