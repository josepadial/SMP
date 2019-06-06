
#ifndef _GYRO_
#define _GYRO_

#include <math.h>

#define GYROW 0xD0
#define GYROR 0xD1


void gyro_config(){
	i2c_start();
	i2c_write(GYROW);
	delay_us(50);
	i2c_write(0x18);
	i2c_stop();
}

signed int8 gyro_read16(){
signed int16 data;
unsigned int8 d1, d2;
float ve;
signed int8 vel;

	i2c_start();
	i2c_write(GYROR);
	delay_us(50);
	d1 = i2c_read();
	delay_us(50);
	d2 = i2c_read(0);
	i2c_stop();
	data = d1 & 0xFF;
	data = data << 8;
	data = data | d2;

	data = data - 21515;
	ve = ((float) data) / 10.4;
	vel = (signed int8) ve;

	return vel;
}

#endif
