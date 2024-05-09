#include <Wire.h>
#include <SparkFun_I2C_Mux_Arduino_Library.h>

QWIICMUX myMux;

void setup()
{
    Serial.begin(115200);
    delay(2000);

    Wire.setPins(7, 6);

    Serial.println();
    Serial.println("Qwiic Mux Shield Read Example");

    Wire.begin();

    if (myMux.begin(0x70) == false)
    {
        Serial.println("Mux not detected. Freezing...");
        while (1)
            ;
    }
    Serial.println("Mux detected");

    myMux.setPort(1); // Connect master to port labeled '1' on the mux

    byte currentPortNumber = myMux.getPort();
    Serial.print("CurrentPort: ");
    Serial.println(currentPortNumber);

    Serial.println("Begin scanning for I2C devices");
}

void loop()
{
    Serial.println();

    byte nDevices = 0;
    for (byte port = 1; port <= 8; port++) {
        Serial.print("Scanning port ");
        myMux.setPort(port); // Connect master to port labeled '1' on the mux
        Serial.println(port);

        for (byte address = 1; address < 127; address++)
        {
            Wire.beginTransmission(address);
            byte error = Wire.endTransmission();

            if (error == 0)
            {
                Serial.print("I2C device found at address 0x");
                if (address < 0x10)
                    Serial.print("0");
                Serial.print(address, HEX);
                Serial.println();

                nDevices++;
            }
            else if (error == 4)
            {
                Serial.print("Unknown error at address 0x");
                if (address < 0x10)
                    Serial.print("0");
                Serial.println(address, HEX);
            }
        }
    }

    if (nDevices == 0)
        Serial.println("No I2C devices found");
    else
        Serial.println("Done");

    delay(1000);
}