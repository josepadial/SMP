#ifndef _MISMOV_
#define _MISMOV_

#include "tarjeta.h"
#include "srf02.h"
#use delay (clock=48000000)

void DELANTE(){
   M1_H();
   M2_A();
}

void ATRAS(){
   M1_A();
   M2_H();
}

void PARAR(){
   M1_P();
   M2_P();
}

void PARAR_I(){
   M4_P();
}

void DISPARAR(){
   M4_H();
}

void RECOGER(){
   M4_A();
}

void IMPACTO(){
   DISPARAR();
   delay_ms(50);
   PARAR_I();
   delay_ms(50);
   RECOGER();
   delay_ms(50);
   PARAR_I();
   delay_ms(50);
}

void DERECHA(){
   M1_A();
   M2_H();
}

void IZQUIERDA(){
   M1_A();
   M2_P();
}

int ULTRA_SONIDOS_FRENTE(int dist){
   //delay_ms(1);
   if(srf_measure_cm_frente() < dist) 
      return 1;
   else
      return 0;
}

int ULTRA_SONIDOS_DERE(int dist){
   //delay_ms(1);
   if(srf_measure_cm_dere() < dist) 
      return 1;
   else
      return 0;
}


int ULTRA_SONIDOS_IZQUI(int dist){
   //delay_ms(1);
   if(srf_measure_cm_izqui() < dist) 
      return 1;
   else
      return 0;
}

#endif
