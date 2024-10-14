#include "TMP102.h"

TMP102::TMP102(I2C *i2c, int addr) : i2c(i2c), address(addr << 1) {  
    // El constructor usa I2C y la dirección del sensor TMP102 (shifted por el bit R/W)
}

float TMP102::readTemperature() {
    char cmd[2] = {0x00, 0x00};  // Comando para leer el registro de temperatura
    char data[2] = {0};    // Datos recibidos del sensor
    
    if (i2c->write(address, cmd, 1) != 0) {
        // Error en la escritura I2C
        return -999.0;  // Devuelve un valor de error si falla la escritura
    }

    if (i2c->read(address, data, 2) != 0) {
        // Error en la lectura I2C
        return -999.0;  // Devuelve un valor de error si falla la lectura
    }

    // Convertir los datos de temperatura a grados Celsius
    int16_t tempRaw = (data[0] << 4) | (data[1] >> 4);  // Combina los bytes en un valor de 12 bits
    if (tempRaw & 0x800) {  // Verifica si el número es negativo
        tempRaw |= 0xF000;  // Extiende el signo para números negativos
    }
    
    return tempRaw * 0.0625f;  // Conversión a grados Celsius
}
