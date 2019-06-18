#include "mismov.h"
#use delay (clock=48000000)

void inicializarTimer0PWM(){ 
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2|RTCC_8_BIT); 
   enable_interrupts(INT_TIMER0); 
   enable_interrupts(GLOBAL); 
}  

void main() {
   inicializarTimer0PWM();
   led_on();
   delay_ms(3000);
   led_off();
   DELANTE();
   while(1){
   
   }
}
