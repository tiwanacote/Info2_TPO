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
		is_moving = mover_motor( 6 , 54 , 1000, 10 , 1 );
	}

	return 0 ;
}
