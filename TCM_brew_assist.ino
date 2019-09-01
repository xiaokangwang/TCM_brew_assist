#include <EEPROM.h>
#include <Wire.h>
#include <Servo.h>

#ifndef Adafruit_MLX90614_H
#define Adafruit_MLX90614_H
#include <Adafruit_MLX90614.h>
#endif

#include <IRremote.h>
#include <LiquidCrystal_I2C.h>
#include "stepper_wrapper.h"
#include "Peripherals.h"
#include "init.h"
//#include "memory.h"
#include "refresh.h"




PeripheralArray pa;
void setup() {
  Serial.begin(9600);
  InitPeripheral(&pa);
}

void loop() {
  refresh(&pa);


  // put your main code here, to run repeatedly:
  /*
    Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
    Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
    Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
    Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

    Serial.println();
    delay(500);

    */

    delay(500);
}
