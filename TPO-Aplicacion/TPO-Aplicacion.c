/*
===============================================================================
 TPL2 - Timer / counter como contador
===============================================================================
*/
#include "Infotronic.h"



#include <global_variables.h>
#include <maquina_estado.h>
#include <defines.h>
//extern uint32_t pos_motor[8]; //solo para debug
//extern uint32_t cont_periodo;

int main(void)
{
	Inicializar ( );
	
	uint8_t is_moving = 1;


/*
	while(1)
	{

		maquina_estado();

	}
*/

/*
 *
 *
 * ESTO FUNCIONA Y ES LO ULTIMO QUE HICIMOS CON JUAN
 *
 */
	while( 1 )
	{
		cont_periodo =0;
				while (is_moving)
				{
					//is_moving = mover_motor( 6  , 54 , 1000, 15 , 1 );

					is_moving = mover_motor( MOTOR_DEDO_1  , 54 , 1000, 15 , 1 );
					is_moving = mover_motor( MOTOR_DEDO_2  , 54 , 1000, 15 , 1 );
					is_moving = mover_motor( MOTOR_DEDO_3  , 54 , 1000, 15 , 1 );
					is_moving = mover_motor( MOTOR_DEDO_4  , 54 , 1000, 15 , 1 );
					is_moving = mover_motor( MOTOR_DEDO_5  , 54 , 1000, 15 , 1 );
					is_moving = mover_motor( MOTOR_MUNIECA , 54 , 1000, 15 , 1 );
					is_moving = mover_motor( MOTOR_CODO    , 54 , 1000, 15 , 1 );
					is_moving = mover_motor( MOTOR_EXTRA   , 54 , 1000, 15 , 1 );
				}
		is_moving = 1;
		// Para decrementar --- > ATENCIÓN: Cambiar pos_motor[8] = {1000,1000,1000,1000,1000,1000,1000,1000};
		cont_periodo =0;
		while (is_moving)
		{
			//is_moving = mover_motor( 6 , 1000 , 54, 15 , 1 ); //(motor,pos_ini,pos_final , vel , acel)

			is_moving = mover_motor( MOTOR_DEDO_1  , 1000, 54, 15 , 1 );
			is_moving = mover_motor( MOTOR_DEDO_2  ,  1000,54, 15 , 1 );
			is_moving = mover_motor( MOTOR_DEDO_3  ,  1000,54, 15 , 1 );
			is_moving = mover_motor( MOTOR_DEDO_4  ,  1000,54, 15 , 1 );
			is_moving = mover_motor( MOTOR_DEDO_5  ,  1000,54, 15 , 1 );
			is_moving = mover_motor( MOTOR_MUNIECA ,  1000,54, 15 , 1 );
			is_moving = mover_motor( MOTOR_CODO    ,  1000,54, 15 , 1 );
			is_moving = mover_motor( MOTOR_EXTRA   ,  1000,54, 15 , 1 );

		}

		is_moving = 1;
		pos_motor[5]=54;
	}


	return 0 ;
}
