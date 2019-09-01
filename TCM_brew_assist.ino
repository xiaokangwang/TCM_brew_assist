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
#include "memory.h"




PeripheralArray pa;
void setup() {
  Serial.begin(9600);
  InitPeripheral(&pa);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();
  delay(500);

  if (irrecv.decode(&results)) //if the ir receiver module receiver data
  {
    Serial.print("irCode: "); //print"irCode: "
    Serial.print(results.value, HEX); //print the value in hexdecimal
    Serial.print(", bits: "); //print" , bits: "
    Serial.println(results.bits); //print the bits
    irrecv.resume(); // Receive the next value
  }*/
}
