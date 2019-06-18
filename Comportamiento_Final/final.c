#include "mismov.h"
#use delay (clock=48000000)
#define MOVIMIENTO_DELANTE 0
#define MOVIMIENTO_IZQUIERDA 1
#define MOVIMIENTO_DERECHA 2
#define MOVIMIENTO_ATRAS 3
#define MOVIMIENTO_PARAR 4

int contador;
int indice_movimiento = 0;
int num_movimientos;

int array_movimientos[5] ;
int array_tiempos[5];

int interrupcion = 0;
   


void inicializarTimer0PWM(){ 
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_4); 
   enable_interrupts(GLOBAL); 
} 

#INT_TIMER0
void tmr0(){
   if (contador != 0){
      switch(array_movimientos[indice_movimiento]){
         case MOVIMIENTO_DELANTE:
            DELANTE();
            break;
         case MOVIMIENTO_IZQUIERDA:
            IZQUIERDA();
            break;
         case MOVIMIENTO_DERECHA:
            DERECHA();
            break;
         case MOVIMIENTO_ATRAS:
            ATRAS();
            break;
         case MOVIMIENTO_PARAR:
            PARAR();
            break;
      }
      
      contador --;
   }
   else{
      indice_movimiento++;
      if (indice_movimiento == num_movimientos){
         disable_interrupts(INT_TIMER0);
         interrupcion = 0;
         indice_movimiento = 0;
      }
      else{
         contador = array_tiempos[indice_movimiento];
         PARAR();
         delay_ms(100);
      }
   }
   
}

void main() {
   //Delay inicial
   delay_ms(3000);
   
   inicializarTimer0PWM();
   
   while(1){
      if(!IN1 && interrupcion == 0){
         num_movimientos = 3;
         array_movimientos[0] = MOVIMIENTO_PARAR;
         array_movimientos[1] = MOVIMIENTO_ATRAS;
         array_movimientos[2] = MOVIMIENTO_IZQUIERDA;
         array_tiempos[0] = 15;
         array_tiempos[1] = 60;
         array_tiempos[2] = 254;
         contador = array_tiempos[0];
         interrupcion = 1;
         enable_interrupts(INT_TIMER0);
         
      }
      else if ((!IN2 || !IN3)){
         DELANTE();
      }
      
      else if (!IN4){
         DELANTE();
         IMPACTO();
      }
      
      else if (!IN5){
         ATRAS();
      }
      
      else if (ULTRA_SONIDOS_FRENTE(60)){
         DELANTE();
      }
      
      else if (ULTRA_SONIDOS_IZQUI(60) && interrupcion == 0){
         array_movimientos[0] = 1;
         array_tiempos[0] = 80;
         contador = array_tiempos[0];
         interrupcion = 1;
         enable_interrupts(INT_TIMER0);
      }
      else if (ULTRA_SONIDOS_DERE(60) && interrupcion == 0){
         array_movimientos[0] = MOVIMIENTO_DERECHA;
         array_tiempos[0] = 80;
         contador = array_tiempos[0];
         interrupcion = 1;
         enable_interrupts(INT_TIMER0);
      }
      
      else{
         DELANTE();
      }
      
   }
}
