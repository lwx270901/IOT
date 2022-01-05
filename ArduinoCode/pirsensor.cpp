#include "pirsensor.h"

static int state = 0;
static int pir_counter = 0;

void pir_init()
{
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(PIR_SENSOR, OUTPUT);
}
void increase_pir_counter()
{
  pir_counter++;
}

void fsm_for_pir()
{
  switch(state)
  {
    case 0://bth
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
    if(digitalRead(PIR_SENSOR))
    {
      state = 1;
      pir_counter = 0;
      digitalWrite(m11, HIGH);
      digitalWrite(m12, LOW);
    }
    break;
    case 1: //timer for change to low low
    if(pir_counter == 5)
    {
      state = 2;
      digitalWrite(m11, LOW);
      digitalWrite(m12, LOW);
      pir_counter = 0;
    }
    break;
    case 2:
    if(pir_counter == 3)
    {
      state = 3;
      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      pir_counter = 0;
    }
    if(digitalRead(PIR_SENSOR))
    {
      pir_counter = 0;
    }
    break;
    case 3:
    if(pir_counter == 5)
    {
      state = 0;
      pir_counter = 0;
    }
    if(digitalRead(PIR_SENSOR))
    {
      state = 1;
      pir_counter = 0;
      digitalWrite(m11, HIGH);
      digitalWrite(m12, LOW);
    }
    break;
  }
  
}
