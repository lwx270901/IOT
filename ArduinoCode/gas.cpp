#include "gas.h"


static int state = 0;
static int gas_counter = 0;
void init_gas()
{
  pinMode(gas, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}
void gas_loop()
{
  int value = digitalRead(gas);
  switch(state)
  {
    case 0:
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    if(value == HIGH)
    {
      state = 1;
      digitalWrite(green, LOW);
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      gas_counter = 0;
    }
    break;
    case 1:
    if(gas_counter == 3)
    {
      state = 2;
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      gas_counter = 0;
    }
    if(value == LOW)
    {
      state = 0;
    }
    break;
    case 2:
    if(value == LOW)
    {
      state = 0;
    }
    break;
    
  }
}



void increase_gas_counter()
{
  gas_counter++;
}
