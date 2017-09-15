/*
===============================================================================
 TPL2 - Timer / counter como contador
===============================================================================
*/
#include "Infotronic.h"

int main(void)
{
	Inicializar ( );
	
	uint8_t is_moving = 0;

	while( 1 )
	{
		// Para aumentar --- > ATENCIÓN: Cambiar pos_motor[8] = {54,54,54,54,54,54,54,54};
		//is_moving = mover_motor( 6 , 54 , 1000, 10 , 1 ); //(motor,pos_ini,pos_final , vel , acel)

		// Para decrementar --- > ATENCIÓN: Cambiar pos_motor[8] = {1000,1000,1000,1000,1000,1000,1000,1000};
		is_moving = mover_motor( 6 , 1000 , 54, 10 , 1 ); //(motor,pos_ini,pos_final , vel , acel)
	}

	return 0 ;
}
