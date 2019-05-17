#include "tarjeta.h"
#use delay (clock=48000000)
#define INF_16_BIT 65535
#define SR04_TRIGG PIN_A4
#define SR04_ECHO PIN_B3
#use rs232(baud=9600, bits=8, parity=N, xmit=PIN_C4,rcv=PIN_C5)
 
// 50 cm * (59 ms / 1 cm) * (3uds /2ms) = 4425

int captura = 0;
long v_captura;



#INT_CCP2
void capture(){
   led_on();
}

void pulseIn_ECHO_HIGH(){
   setup_ccp2(CCP_CAPTURE_RE);
   enable_interrupts(INT_CCP2);
   set_timer1(0);
}

void main(){
   
   enable_interrupts(GLOBAL);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
   
   while(1){
      
      output_low(SR04_TRIGG);
      output_high(SR04_TRIGG);
      delay_ms(10);
      output_low(SR04_TRIGG);
      pulseIn_ECHO_HIGH();
   }

}

