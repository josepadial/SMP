#include "tarjeta.h" 
#include "mismov.h" 
#use delay (clock=48000000) 


void inicializarTimer0PWM(){ 
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2|RTCC_8_BIT); 
   enable_interrupts(INT_TIMER0); 
   enable_interrupts(GLOBAL); 
}  
 
void main(){ 
   //inicializarTimer0PWM(); 
   int cont = 0;
   M1_A();
   M2_A();
   while(1){
      if(IN2 /*&& cont<2*/){
         IMPACTO();
         cont++;
      }
      /*else if(IN2 && cont>2){
         M1_A();
         M2_A();
         cont=0;
         delay_ms(500);
      }*/
         
   }  
}

