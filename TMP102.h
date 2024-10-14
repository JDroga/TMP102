#ifndef TMP102_H
#define TMP102_H

#include "mbed.h"

#define TMP102_DEFAULT_ADDR 0x48  // Dirección I2C por defecto del TMP102

class TMP102 {
public:
    TMP102(I2C *i2c, int addr = TMP102_DEFAULT_ADDR);  // Constructor con dirección por defecto
    float readTemperature();                           // Método para leer la temperatura

private:
    I2C *i2c;        // Comunicación I2C
    int address;     // Dirección I2C del TMP102
};

#endif
