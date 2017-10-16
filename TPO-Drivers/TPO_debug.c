/*
 * TPO_debug.c
 *
 *  Created on: Oct 14, 2017
 *      Author: maximilano
 */

#include <Infotronic.h>
//#include <stdio.h>

// Para debug
extern int pos_fin[8];
extern int pos_ini[8];
int buf [4]={500,1000,54};
int buf_2 [4]={54,500,1000};


void EINT3_IRQHandler( void )
{
	EXTINT |= ( 1 << EINT3 );	// borro el flag EINT3 de interrupcion externa 3 del registro EXTINT

	static int contador = 0;
	//printf ("HOLA/n");

	pos_fin[6]=buf[contador];
	pos_ini[6]=buf_2[contador];


	contador++;

	if(contador==3)
		contador=0;



	// Solo para debuggg
	if( GetPIN( 0 , 24 , 1 ) )	// puerto = 0 , pin =  24 ; actividad = ALTO
			SetPIN( 0 , 24 , 0 );	// puerto = 0 , pin =  24 ; estado = 0
		else
			SetPIN( 0 , 24 , 1 );	// puerto = 0 , pin =  24 ; estado = 1



}
