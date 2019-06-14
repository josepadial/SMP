#include "tarjeta.h"
#use delay(clock=48000000)

#define old_add 0xe0
#define new_add 0xe4

void main() {
   led_on();
   delay_ms(3000);
   led_off();
   
   
   i2c_start();
   delay_us(50);
   i2c_write(old_add);
   delay_us(50);
   i2c_write(0x00);
   delay_us(50);
   i2c_write(0xa0);
   delay_us(50);
   i2c_stop();
   
   delay_us(50);
   
   i2c_start();
   delay_us(50);
   i2c_write(old_add);
   delay_us(50);
   i2c_write(0x00);
   delay_us(50);
   i2c_write(0xaa);
   delay_us(50);
   i2c_stop();
   
   delay_us(50);
   
   i2c_start();
   delay_us(50);
   i2c_write(old_add);
   delay_us(50);
   i2c_write(0x00);
   delay_us(50);
   i2c_write(0xa5);
   delay_us(50);
   i2c_stop();
   
   delay_us(50);
   
   i2c_start();
   delay_us(50);
   i2c_write(old_add);
   delay_us(50);
   i2c_write(0x00);
   delay_us(50);
   i2c_write(new_add);
   delay_us(50);
   i2c_stop();
   
   led_on();
   
   while(1){
   }
   
}

