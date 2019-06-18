#include "mismov.h"
#use delay (clock=48000000)

const long int valor = 255;
int movimiento;
long int contador = valor;

void inicializarTimer0PWM(){ 
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_4 | RTCC_8_BIT); 
   enable_interrupts(INT_TIMER0); 
   enable_interrupts(GLOBAL); 
} 

#INT_TIMER0
void tmr0(){
   contador--;

   if(contador == 0){
      led_off();
      //PARAR();
      contador = valor;
   }
}

void main() {
   delay_ms(3000);
   inicializarTimer0PWM();
   led_on();
   //led_off();
   //DERECHA();
   while(1){
      //DELANTE();
   }
}
