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
	uint32_t cont_motor0 = 2; // Esto va a ser movible. Es lo que debe cambiar con a velocidad

	if( T0IR & ( 1 << IRMR0 ) )	// Si interrumpio Match 0
			{
				T0IR = ( 1 << IRMR0 );	// Borro flag del Match 0
				cont_match0 = cont_match0 + 1;

				if (cont_match0 == cont_motor0)
					SetPIN( 0 , 22 , 0 ) ;	// puerto = 0 , pin =  22  , estado = 0
			}



	if( T0IR & ( 1 << IRMR1 ) )	// Si interrumpio Match 1
	{
		T0IR = ( 1 << IRMR1 ); 	// Borro flag del Match 1
		//// cont_match1++; Por ahora no lo necesito
		SetPIN( 0 , 22 , 1 ) ;	// puerto = 0 , pin =  22 , estado = 1
		cont_match0 = 0;
		////cont_match1 = 0; Por ahora no lo necesito
	}


}



    /* if( T0IR & ( 1 << IRMR0 ) )	// Si interrumpio Match 0
	{
    	T0IR = ( 1 << IRMR0 );	// Borro flag del Match 0
    	SetPIN( 0 , 22 , 0 ) ;	// puerto = 0 , pin =  22 ; estado = 0
	}*/




    /*if( T0IR & ( 1 << IRMR1 ) )	// Si interrumpio Match 1
    {
    	//T0IR = ( 1 << IRMR1 ); 	// Borro flag del Match 1
    	SetPIN( 0 , 22 , 1 ) ;	// puerto = 0 , pin =  22 ; estado = 1
    }
	}*/

