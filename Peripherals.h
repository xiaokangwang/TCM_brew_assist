#ifndef Peripherals_H
#define Peripherals_H

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

#define IrReceiverPin 10

struct PeripheralArray {
  StepperWrapper sw = StepperWrapper(2, 3, 4, 5);
  Adafruit_MLX90614 mlx = Adafruit_MLX90614();
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // set the LCD address to 0x27  0x3F for a 16 chars and 2 line display
  IRrecv irrecv = IRrecv(IrReceiverPin);
};


#endif
