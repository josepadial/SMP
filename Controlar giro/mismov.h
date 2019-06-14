#ifndef _MISMOV_
#define _MISMOV_

#include "tarjeta.h"
//#include "srf02.h"
#use delay (clock=48000000)

void DELANTE(){
   M1_H();
   M2_H();
}

void ATRAS(){
   M1_A();
   M2_A();
}

void PARAR(){
   M1_P();
   M2_P();
}

void DISPARAR(){
   M3_H();
   M4_H();
}

void RECOGER(){
   M3_A();
   M4_A();
}

void IMPACTO(){
   DISPARAR();
   delay_ms(250);
   PARAR();
   delay_ms(700);
   RECOGER();
   delay_ms(250);
   PARAR();
   delay_ms(500);
}

void DERECHA(long int t){
   PARAR();
   delay_ms(400);
   M1_P();
   M2_A();
   delay_ms(t);
   PARAR();
   delay_ms(250);
}

void IZQUIERDA(long int t){
   PARAR();
   delay_ms(400);
   M1_A();
   M2_P();
   delay_ms(t);
   PARAR();
   delay_ms(250);
}

/*int ULTRA_SONIDOS_FRENTE(int dist){
   delay_ms(1);
   if(srf_measure_cm_frente() < dist) 
      return 1;
   else
      return 0;
}

int ULTRA_SONIDOS_DERE(int dist){
   delay_ms(1);
   if(srf_measure_cm_dere() < dist) 
      return 1;
   else
      return 0;
}


int ULTRA_SONIDOS_IZQUI(int dist){
   delay_ms(1);
   if(srf_measure_cm_izqui() < dist) 
      return 1;
   else
      return 0;
}*/


#endif
