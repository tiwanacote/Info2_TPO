/*
 * TPO_debug.c
 *
 *  Created on: Oct 14, 2017
 *      Author: maximilano
 */

#include <Infotronic.h>

// Para debug
extern int pos_fin[8];
int buf [3]={1000,500,1500};


void EINT3_IRQHandler( void )
{
	EXTINT |= ( 1 << EINT3 );	// borro el flag EINT3 de interrupcion externa 3 del registro EXTINT

	static int contador = 0;

	pos_fin[6]=buf[contador];


	contador++;

	if(contador==2)
		contador=0;



	// Solo para debuggg
	if( GetPIN( 0 , 24 , 1 ) )	// puerto = 0 , pin =  24 ; actividad = ALTO
			SetPIN( 0 , 24 , 0 );	// puerto = 0 , pin =  24 ; estado = 0
		else
			SetPIN( 0 , 24 , 1 );	// puerto = 0 , pin =  24 ; estado = 1



}
