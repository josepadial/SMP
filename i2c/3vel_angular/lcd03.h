	
#ifndef _LCD03_
#define _LCD03_

#define LCD03W 0xC6
#define LCD03R 0xC7
#define COMMAND 0x00
#define FIFO 0x00
#define KEYL 0x01
#define KEYH 0x02

void lcd_init(){
	delay_ms(1000);
}

void lcd_clear(){
	i2c_start();
	i2c_write(LCD03W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(12);
	i2c_stop();
}

void lcd_light_on(){
	i2c_start();
	i2c_write(LCD03W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(19);
	i2c_stop();
}

void lcd_light_off(){
	i2c_start();
	i2c_write(LCD03W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(20);
	i2c_stop();
}

void lcd_print(char *p){
	i2c_start();
	i2c_write(LCD03W);
	delay_us(50);
	i2c_write(COMMAND);
	while (*p){
		delay_us(50);
		i2c_write(*p++);
	}
	i2c_stop();
}

void lcd_print_char(char c){
	i2c_start();
	i2c_write(LCD03W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(c);
	i2c_stop();
}

void lcd_send_command(unsigned int8 c){
	i2c_start();
	i2c_write(LCD03W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(c);
	i2c_stop();
}

unsigned int16 lcd_keyboard(){
unsigned int16 keyb, keyb2;

	i2c_start();
	i2c_write(LCD03W);
	delay_us(50);
	i2c_write(KEYL);
	delay_us(50);
	i2c_start();
	i2c_write(LCD03R);
	delay_us(50);
	keyb = i2c_read();
	keyb2 = i2c_read(0);
	keyb = keyb | (keyb2 << 8);
	i2c_stop();
	return keyb;
}

char lcd_key_pressed(){
unsigned int16 key;

	key = lcd_keyboard();
	if (key & 0x0001){
		return '1';
	}else if (key & 0x0002){
		return '2';
	}else if (key & 0x0004){
		return '3';
	}else if (key & 0x0008){
		return '4';
	}else if (key & 0x0010){
		return '5';
	}else if (key & 0x0020){
		return '6';
	}else if (key & 0x0040){
		return '7';
	}else if (key & 0x0080){
		return '8';
	}else if (key & 0x0100){
		return '9';
	}else if (key & 0x0200){
		return '*';
	}else if (key & 0x0400){
		return '0';
	}else if (key & 0x0800){
		return '#';
	}else{
		return '\0';
	}
}

unsigned int8 lcd_fifo(){
unsigned int8 tam;

	i2c_start();
	i2c_write(LCD03W);
	delay_us(50);
	i2c_write(FIFO);
	delay_us(50);
	i2c_start();
	i2c_write(LCD03R);
	delay_us(50);
	tam = i2c_read(0);
	i2c_stop();

	return tam;
}

#endif
