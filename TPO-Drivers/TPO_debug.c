/*
 * TPO_debug.c
 *
 *  Created on: Oct 14, 2017
 *      Author: maximilano
 */

#include <Infotronic.h>
#include <global_variables.h>
//#include <stdio.h>

// Para debug
extern int pos_fin[8];
extern int pos_ini[8];
extern int is_moving;
int buf [4]={54,144,240}; //0°,90°,180°
//int buf_2 [4]={54,500,1000};


void EINT3_IRQHandler( void )
{
	EXTINT |= ( 1 << EINT3 );	// borro el flag EINT3 de interrupcion externa 3 del registro EXTINT

	static int contador = 0;
	//printf ("HOLA/n");

	pos_fin[5]=buf[contador];
	//pos_ini[6]=buf_2[contador];

	pos_ini[5]= pos_motor[5];

	cont_periodo = 0;	// MUY IMORTANTE: Cuando cae un mensaje nuevo se debe volver a hacer calculos desde mover_motor() con contador_periodo = 0

	contador++;

	if(contador==3)
		contador=0;



	// Solo para debuggg
	if( GetPIN( 0 , 24 , 1 ) )	// puerto = 0 , pin =  24 ; actividad = ALTO
			SetPIN( 0 , 24 , 0 );	// puerto = 0 , pin =  24 ; estado = 0
		else
			SetPIN( 0 , 24 , 1 );	// puerto = 0 , pin =  24 ; estado = 1



}
