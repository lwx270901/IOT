#include "input_reading.h"
// we aim to work with more than one buttons
static int buttonBuffer = 1;
static int debounceButtonBuffer1= 1;
static int debounceButtonBuffer2 = 1;
static int debounceButtonBuffer3 = 1;
// chong rung 3 lan
static int flagForButtonPress2s = 0;
static int counterForButtonPress2s = 0;

void button_reading ()
{
  debounceButtonBuffer3 = debounceButtonBuffer2;
  debounceButtonBuffer2 = debounceButtonBuffer1;
  debounceButtonBuffer1 = digitalRead(6);
  if(debounceButtonBuffer1 == debounceButtonBuffer2 && debounceButtonBuffer2 == debounceButtonBuffer3)
  {
    buttonBuffer = debounceButtonBuffer1;
    if( buttonBuffer == LOW )
    {
      // if a button is pressed , we start counting
      if( counterForButtonPress2s  < 200 )
      {
        counterForButtonPress2s++;
      }
      else
      {
        // the flag is turned on when 1 second has passed
        // since the button is pressed .
        flagForButtonPress2s = 1;
      }
    }
    else
    {
      counterForButtonPress2s = 0;
      flagForButtonPress2s = 0;
    }
  }
}


int is_button_pressed(  )
{
  return  buttonBuffer == LOW;
}

int is_button_pressed_2s()
{
  return ( flagForButtonPress2s  == 1);
}
