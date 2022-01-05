
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "timer.h"
#include "lcdfile.h"
#include "pirsensor.h"
#include "moi.h"
#include "gas.h"
#include "input_processing.h"



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setTimer1(10);
  timer_init();
  init_lcd();
  pir_init();
  init_moi();
  init_gas();
  pinMode(2, OUTPUT);
  pinMode(6, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(timer1_flag == 1)
  {
    display_dht();
    moi_loop();
    setTimer1(100);
  }
  fsm_for_input_processing ();
  fsm_for_pir();
  gas_loop();
}
