#include "timer.h"
int timer1_counter = 0;
int timer1_flag = 1;
int timer2_counter = 0;
int timer2_flag = 1;
int TIMER_CYCLE = 10;


void setTimer1(int duration)
{
  timer1_counter = duration / TIMER_CYCLE;
  timer1_flag = 0;
}
void timer1_run()
{
  if( timer1_counter > 0)
  {
    timer1_counter --;
    if( timer1_counter == 0) timer1_flag = 1;
  }
  increase_pir_counter();
  increase_gas_counter();
}
ISR (TIMER2_OVF_vect) // Su dung cho nut nhan
{
  timer2_run();
  TCNT2 = 100;
}


void setTimer2(int duration)
{
  timer2_counter = duration / TIMER_CYCLE;
  timer2_flag = 0;
}
void timer2_run()
{
  if( timer2_counter > 0)
  {
    timer2_counter --;
    if( timer2_counter == 0) timer2_flag = 1;
  }
  button_reading();
}

ISR (TIMER1_OVF_vect) // Su dung cho lcd
{
  timer1_run();
  TCNT1= 49911; //Giá trị tính toán phía trên
}



void timer_init()
{
  cli(); //Tắt ngắt toàn cục
  TCCR1A = 0; //Reset Timer1
  TCCR1B = 0;      
  TIMSK1 = 0;
  //Setup Timer1 1s
  TCCR1B |= (1 << CS12)|(1 << CS10) ; //Chọn prescaler 1024 CS12=1,CS10=1 xem bảng phía trên
  TCNT1= 49911; //Giá trị tính toán phía trên
  TIMSK1 |= (1 << TOIE1); //Overflow interrupt enable
 
  TCCR2A = 0; //Reset Timer2
  TCCR2B = 0;      
  TIMSK2 = 0;
  //Setup Timer2 10ms
  TCCR2B |= (1 << CS22)|(1 << CS21)|(1 << CS20) ; //Chọn prescaler 1024 CS22=1,CS21=1, CS20=1 xem bảng phía trên
  TCNT2 = 100; //Giá trị tính toán phía trên
  TIMSK2 |= (1 << TOIE2); //Overflow interrupt enable
  sei(); //Cho phép ngắt toàn cục
}
