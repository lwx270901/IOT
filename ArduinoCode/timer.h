#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>
#include <avr/interrupt.h>
#include "lcdfile.h"
#include "pirsensor.h"
#include "gas.h"
#include "input_reading.h"
extern int timer1_counter;
extern int timer1_flag;
extern int timer2_counter;
extern int timer2_flag;




void setTimer1(int duration);
void setTimer2(int duration);
void timer1_run();
void timer2_run();
ISR (TIMER2_OVF_vect); //Chương trình ngắt Timer2
ISR (TIMER1_OVF_vect); //Chương trình ngắt Timer1
void timer_init();
#endif
