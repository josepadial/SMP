#include "mismov.h"
#use delay (clock=48000000)

void main() {
   led_on();
   delay_ms(3000);
   DELANTE();
   led_off();
   while(1){
      if(ULTRA_SONIDOS_IZQUI(30)){
         led_on();
      }
      else if(ULTRA_SONIDOS_FRENTE(30)){
         PARAR();
         //led_on();
         delay_ms(1000);
         //DERECHA(600);
      }
      else if(ULTRA_SONIDOS_DERE(30)){
         led_on();
      }
      else
         DELANTE();
   }
}
