#include "tarjeta.h"
#use delay (clock=48000000)
#define INF_16_BIT 65535
#define SR04_TRIGG PIN_A4
#define SR04_ECHO PIN_B3
//#use rs232(baud=9600, bits=8, parity=N,xmit=PIN_C4,rcv=PIN_C5)
 
// 50 cm * (59 ms / 1 cm) * (3uds /2ms) = 4425

int captura = 0;
long v_captura;

#INT_TIMER1
void check_time_out(){
   disable_interrupts(INT_CCP2);
   disable_interrupts(INT_TIMER1);         
   v_captura = INF_16_BIT;
   captura = 0;
}


#INT_CCP2
void capture(){
   if (captura == 0){
      //led_on();
      set_timer1(0);
      captura++;
      enable_interrupts(INT_TIMER1);   
      setup_ccp2(CCP_CAPTURE_FE);         
   }
   else{
      v_captura = CCP_2;
      captura = 0;
      disable_interrupts(INT_CCP2);
      disable_interrupts(INT_TIMER1);
   }
}

void pulseIn_ECHO_HIGH(){
   v_captura = 0;
   setup_ccp2(CCP_CAPTURE_RE);
   enable_interrupts(INT_CCP2);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
   while(v_captura == 0){
      led_on();
   }
}

void main(){
   
   enable_interrupts(GLOBAL);
   
   while(1){
      
  output_high(SR04_TRIGG);
      delay_ms(15);
      output_low(SR04_TRIGG);
      pulseIn_ECHO_HIGH();
      /*
      if(v_captura < 4425){
         led_off();
      }
      else{
         led_on();
      }
      */
      
   }

}

