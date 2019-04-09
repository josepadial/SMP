#include "tarjeta.h" 
#use delay (clock=48000000) 


void inicializarTimer0PWM(){ 
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2|RTCC_8_BIT); 
   enable_interrupts(INT_TIMER0); 
   enable_interrupts(GLOBAL); 
}  
 
void main(){ 
   //inicializarTimer0PWM(); 
    
   while(1){
      if(!IN1){
         M1_H();
         M2_H();
         M3_H();
         M4_H();
      }
      else{
         M1_H();
         M2_A();
         M3_H();
         M4_A();
      }
   }
}
