#ifndef GAS_H
#define GAS_H



#include <Arduino.h>
#include <avr/interrupt.h>
#include <Wire.h>

#define gas 12
#define red 11
#define yellow 10
#define green 7



extern int gas_counter;




void init_gas();
void gas_loop();
void increase_gas_counter();





#endif
