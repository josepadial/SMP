#include "tarjeta.h"
#use delay(clock=48000000)
#include "lcd03.h"

void main() {
char key;

lcd_init();
led_off();

set_tris_a(0x00);
set_tris_b(0x13);
set_tris_c(0x00);
set_tris_d(0x1F);
set_tris_e(0x00);

lcd_clear();
lcd_light_on();

while (1){

	key = lcd_key_pressed();
	
	if (key){
		lcd_print_char(key);
		delay_ms(150);
	}

}

}
