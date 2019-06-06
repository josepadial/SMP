#include "tarjeta.h"
#use delay (clock=48000000)
 
// 50 cm * (59 ms / 1 cm) * (3uds /2ms) = 4425

int captura = 0;
long v_captura;

long calcular_distancia(){

    long tiempo;
    output_high(PIN_A4);
    delay_us(10);
    output_low(PIN_A4);

    //esperar a flanco de subida echo
    while(!PIN_B3){}
    set_timer1(0);
    //esperar a flanco de bajada echo
    while(PIN_B3){}
    tiempo = get_timer1();

    return tiempo / 117.0;

}

void main(){
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
   output_low(PIN_A4);
   delay_us(10);
   long distancia;

   while(1){
       distancia = calcular_distancia();
       if (distancia <  25){
           led_on();
       }
   }


}