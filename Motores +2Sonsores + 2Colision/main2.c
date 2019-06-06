#include "tarjeta.h"
#use delay (clock=48000000)

#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7,PARITY=N,BITS=8)

// Movimientos de los motores
#define parar 0
#define adelante 1
#define atras 2
#define izquierda 3
#define derecha 4

#define estadoInicial 0
#define estadoLinea 1
#define echarOponente 2

int estrategia = adelante;
int velocidad = 90;
int valor = 0;
int duracion = 12;
int estado = estadoInicial;


void motoresParar(){
   M1_P();
   M2_P();
}


void motoresAdelante(){
   M1_A();
   M2_A();
}

void motoresDerecha(){
   M1_P();
   M2_A();
}

void motoresIzquierda(){
   M1_A();
   M2_P();
}

void motoresAtras(){
   M1_H();
   M2_H();
}

#INT_TIMER0
void tmr0_isr(){
      valor++;
      
      if (valor <= velocidad){
         switch(estrategia){
            case parar:
               motoresParar();
            break;
            
            case adelante:
               motoresAdelante();
            break;
            
            case derecha:
               motoresDerecha();
            break;
            
            case izquierda:
               motoresIzquierda();
            break;
            
            case atras:
               motoresAtras();
            break;
         }
      }else{
         motoresParar();
      }
      if(valor==0){
         if(duracion !=255){
            duracion--;
            if(duracion==0){
               // para sondear que hay por el campo de batalla
            }
     }
   }
}



void inicializarTimer0PWM(){
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2|RTCC_8_BIT);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
}



void main(){
   delay_ms(3000);
   inicializarTimer0PWM();
   estado = estadoInicial;
   estrategia = atras;
   
   while(1){
      if(estrategia != atras){
         delay_ms(2000);
      }
      
      if(!IN1){
         led_on();
         estrategia = derecha;
      }
      else if(!IN2){
         led_on();
         estrategia = atras;
      }
      else{
         led_off();
         estrategia = adelante;
      }
      if(IN3){
         led_on();
         estrategia = adelante;
      }
      else if(IN4){
         led_on();
         estrategia = adelante;
      }
      else{
         led_off();
         estrategia = atras;
      }
   }
}
