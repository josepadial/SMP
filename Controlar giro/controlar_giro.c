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
   delay_ms(3000);
   while(1){
      PARAR();
      delay_ms(500);
      DELANTE();
      delay_ms(1000);
      PARAR();
      delay_ms(500);
      DERECHA(2500);
      PARAR();
      delay_ms(500);
      IZQUIERDA(2500);
      PARAR();
      delay_ms(500);
      ATRAS();
      delay_ms(1000); 
   }  
}

