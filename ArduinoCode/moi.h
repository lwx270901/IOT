#ifndef MOI_H
#define MOID_H

#include <Arduino.h>
#include <avr/interrupt.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "timer.h"

#define sensor A0
#define led 13
#define motor 9


void init_moi();
void moi_loop();





#endif
