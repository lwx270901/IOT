#ifndef PIRSENSOR_H
#define PIRSENSOR_H


#include <Arduino.h>
#include <avr/interrupt.h>
#include "lcdfile.h"
#include "timer.h"

#define PIR_SENSOR 3
#define m11 5
#define m12 4

extern int pir_counter;

void pir_init();
void fsm_for_pir();
void increase_pir_counter();

#endif
