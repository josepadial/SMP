#include "tarjeta.h"
#use delay(clock=48000000)
#include "vel_angular.h"
#include "lcd03.h"


void main() {
signed int8 m;
char msg[21];

lcd_init();
led_off();

set_tris_a(0x00);
set_tris_b(0x13);
set_tris_c(0x00);
set_tris_d(0x1F);
set_tris_e(0x00);

gyro_config();

lcd_clear();
while(1){
//	lcd_clear();
	m = gyro_read16();
	sprintf(msg,"%4d deg/s\r", m);
	lcd_print(msg);
	delay_ms(100);
}

}
