/*
===============================================================================
 TPL2 - Timer / counter como contador
===============================================================================
*/
#include "Infotronic.h"

extern uint32_t pos_motor[8]; //solo para debug
extern uint32_t cont_periodo;
int main(void)
{
	Inicializar ( );
	
	uint8_t is_moving = 1;




	while( 1 )
	{
		//is_moving = 1;
		// Para aumentar --- > ATENCIÓN: Cambiar pos_motor[8] = {54,54,54,54,54,54,54,54};
	//	while (is_moving)
		//	is_moving = mover_motor( 6 , 54 , 1000, 15 , 1 ); //(motor,pos_ini,pos_final , vel , acel)

		cont_periodo =0;
				while (is_moving)
				{
					is_moving = mover_motor( 6 , 54 , 1000, 15 , 1 );

				}

	//	for(int i = 0; i<8 ; i++)
		//	pos_motor[i]=1000;

		is_moving = 1;
		// Para decrementar --- > ATENCIÓN: Cambiar pos_motor[8] = {1000,1000,1000,1000,1000,1000,1000,1000};
		cont_periodo =0;
		while (is_moving)
		{
			is_moving = mover_motor( 6 , 1000 , 54, 15 , 1 ); //(motor,pos_ini,pos_final , vel , acel)
		}

		is_moving = 1;
		//for(int i = 0; i<8 ; i++)
			pos_motor[5]=54;



	}

	return 0 ;
}
