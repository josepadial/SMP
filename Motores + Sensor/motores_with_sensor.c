#include "tarjeta.h" 
#use delay (clock=48000000) 


void inicializarTimer0PWM(){ 
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2|RTCC_8_BIT); 
   enable_interrupts(INT_TIMER0); 
   enable_interrupts(GLOBAL); 
}  
 
void main(){ 
   //inicializarTimer0PWM(); 
   led_off();
   
   while(1){
      if(!IN1){
         led_off();
      }
      else{
         led_on();
      }
   }
}
