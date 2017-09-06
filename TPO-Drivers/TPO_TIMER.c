/*
 * TPO_TIMER.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Maximiliano
 */

#include "../../../../Documents/Info_II/Info2_TPO/TPO-Headers/Infotronic.h"

void TIMER0_IRQHandler (void)
{

	static uint32_t cont_match0 = 0;
	static uint8_t vector[8]; // Agregar #define CANT_MOTORES 8
	uint32_t pos_m0 = 54, pos_m1 = 500;


	T0IR = ( 1 << IRMR0 );	// Borro flag del Match 0

	cont_match0++;

	if(cont_match0 == pos_m0)
	{
	vector[5] = 0; // P0.21
	SetPIN( 0 , 21 , 0 );
	}
	if(cont_match0 == pos_m1)
	{
	vector[6] = 0;  // P0.22
	SetPIN( 0 , 22 , 0 );
    }

	//SetPINes( 0 , vector );
	//SetPIN( 0 , 22 , 0 );

	if(cont_match0 == 2000 )  // llego al final del ciclo de 20ms
	{
		cont_match0 = 0;
		vector[5] = 1;  // Puede ir MEMSET, Averiguar!!!
		vector[6] = 1;
		//SetPINes( 0 , vector );   // Levato el pulso
		SetPIN( 0 , 22 , 1 );
		SetPIN( 0 , 21 , 1 );

	}

/*
 *
 * Mueve el servo de 0° a 180° cada algunos segundos
 *
	static uint32_t cont_match0 = 0;
	static uint32_t cont_motor = 0;
	static uint32_t flag_a = 0;

	if( T0IR & ( 1 << IRMR0 ) )	// Si interrumpio Match 0
	{
		T0IR = ( 1 << IRMR0 );	// Borro flag del Match 0
		cont_match0++;

		if(cont_match0 == 54 && flag_a==0)	// 54 = (2,7% x 20ms) / 0.01ms   0.01 son aproximadamente las 1033 cuentas
		// Llegamos al 2.7%
		{
			SetPIN( 0 , 22 , 0 ) ;	// puerto = 0 , pin =  22  , estado = 0
		}

		if(cont_match0 == 240 && flag_a==1)	// 54 = (2,7% x 20ms) / 0.01ms   0.01 son aproximadamente las 1033 cuentas
		// Llegamos al 2.7%
		{
			SetPIN( 0 , 22 , 0 ) ;	// puerto = 0 , pin =  22  , estado = 0
		}

		if(cont_match0 == 2000 )  // llego al final del ciclo de 20ms
		{
			cont_match0 = 0;
			SetPIN( 0 , 22 , 1 ) ;   // Levato el pulso
			cont_motor++;	// Para cambiar la posicion del motor (Solo prueba)
		}
		if(cont_motor==25)
		{

			if (flag_a==1)
				flag_a=0;
			else
				flag_a=1;

			cont_motor=0;
		}
	}

*/


}



