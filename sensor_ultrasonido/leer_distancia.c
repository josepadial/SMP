#include "tarjeta.h"
#use delay (clock=48000000)
#define INF_16_BIT 65535
#define SR04_TRIGG PIN_A4
#define SR04_ECHO PIN_B3

// 50 cm * (59 ms / 1 cm) * (3uds /2ms) = 4425

int captura = 0;
long v_captura;

#INT_TIMER1
void check_time_out(){
	disable_interrupts(INT_CCP2);
	disable_interrups(INT_TIMER1);			
	v_captura = INF_16_BIT;
}


#INT_CPP2
void capture(){
	if (captura == 0){
		set_timer1(0);
		captura++;
		enable_interrupts(INT_TIMER1);	
		setup_cpp2(ccp_capture_fe);			
	}
	else{
		v_captura = CCP_2;
		disable_interrupts(INT_CCP2);
		disable_interrups(INT_TIMER1);
		captura = 0;
	}
}

void pulseIn_ECHO_HIGH(){
	setup_cpp2(ccp_capture_re);
	enable_interrupts(INT_CPP2);
	setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
	v_captura = 0;
	while(v_captura == 0){}
	disable_interrupts(INT_CPP2);
	disable_interrupts(INT_TIMER1);
}

void main(){
	
	enable_interrupts(GLOBAL);
	
	while(1){
		
		output_high(SR04_TRIGG);
		delay_ms(10);
		output_low(SR04_TRIGG);
		pulseIn_ECHO_HIGH();

		if (v_captura < 4425){
			//cerca
		}
		else{
			//lejos
		}
	}

}
