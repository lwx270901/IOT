#ifndef LCDFILE_H
#define LCDFILE_H

#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "timer.h"

void init_lcd();
void display_dht();
#endif
