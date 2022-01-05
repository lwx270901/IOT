#include "input_processing.h"

enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED , BUTTON_PRESSED_MORE_THAN_2_SECOND } ;
enum ButtonState buttonState = BUTTON_RELEASED ;
static int ledstate = HIGH; 
void fsm_for_input_processing ()
{
  switch ( buttonState )
  {
    case BUTTON_RELEASED :
    if( is_button_pressed ())
    {
      buttonState = BUTTON_PRESSED ;
    }
    break;
    case BUTTON_PRESSED :
    if (!is_button_pressed ())
    {
      buttonState = BUTTON_RELEASED ;
      ledstate = !ledstate;
      digitalWrite(2,ledstate);
    }
    else
    {
      if( is_button_pressed_2s() )
      {
        buttonState = BUTTON_PRESSED_MORE_THAN_2_SECOND ;
        ledstate = !ledstate;
        digitalWrite(2,ledstate);
      }
    }
    break;
    case BUTTON_PRESSED_MORE_THAN_2_SECOND :
    if (! is_button_pressed ())
    {
      buttonState = BUTTON_RELEASED ;
    }
    
    // todo
    break;
  }
}
