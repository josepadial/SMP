#include "tarjeta.h"
#use delay(clock=48000000)
#include "srf02.h"
#include "lcd03.h"


void main() {
unsigned int16 m;
char msg[21];

lcd_init();
led_off();

set_tris_a(0x00);
set_tris_b(0x13);
set_tris_c(0x00);
set_tris_d(0x1F);
set_tris_e(0x00);

while(1){
   led_on();
   delay_ms(500);
   m = srf_measure_cm();
   if(m > 50) 
      led_off();
   delay_ms(500);
}

}
