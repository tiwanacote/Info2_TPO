/*
===============================================================================
 TPL2 - Timer / counter como contador
===============================================================================
*/
#include "Infotronic.h"

int main(void)
{
	Inicializar ( );
	
	while( 1 )
	{
		mover_motor( 6 , 54 , 1000, 10 , 1 );
	}

	return 0 ;
}
