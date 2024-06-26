# The Everything Sensor!

A collective dev board for all the things our hearts desired.

## Features

 - BME280 (Temperature, Humidity, Pressure)
 - LIS2DH12TR (Accelerometer)
 - TMC2209 (Stepper Motor Driver)
 - HX711 (Load Cell Amplifier)
 - ATGM336H_5N31 (GPS)
 - SGP40_D_R4 (VOC Sensor)
 - MAX31856MUDT (Thermocouple Amplifier)
 - NAU7802 (Load Cell Amplifier)
 - TCA9548APWR (I2C Multiplexer)

 AND both an RP2040 and ESP32-S2 microcontroller!

## Getting Started

The `firmware` directory uses PlatformIO to support multiple build configurations, with different scripts to test different sensors.


## Known Bugs

### `1987a17`

- The `RP2040` USB balance resistors, meant to be `27Ω`, are actually `27kΩ`. This is fixed in the dependency for later builds
- The `TCA9548APWR` reset isn't tied high. This is fixed in the dependency for later builds
