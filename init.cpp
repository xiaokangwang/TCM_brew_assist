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
#include "init.h"

void InitPeripheral(struct PeripheralArray * pa) {
  pa->mlx.begin();
  pa->lcd.init();  //initialize the lcd
  pa->lcd.backlight();  //open the backlight
  pa->irrecv.enableIRIn(); //enable ir receiver module
};
