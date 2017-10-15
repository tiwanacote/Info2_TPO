/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author 
*	\date 23-09-2017 09:53:22
*/





int msg = 0 ;int msg_ok = 0 ;int is_moving = 0 ;
#include <maquina_estado.h> 
#include <global_variables.h>
#include <defines.h>




//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details 
*	\author 
*	\date 23-09-2017 09:53:22
*/


/*  Existira un buffer que guardará movimientos uno tras otro. Si llega un "stop", va al principio
 * de la cola, frena el sistema y borra el buffer para que entre la siguiente instrucción.
 * Paralelismo de persona que quiere cruzar la calle corriendo y se arrepiente porque viene un auto
 */


int pos_ini[8]={54,54,54,54,54,54,54,54};
int pos_fin[8]={1000,1000,1000,1000,1000,1000,1000,1000};
int vel[8]={15,15,15,15,15,15,15,15};
int acel[8]={1,1,1,1,1,1,1,1};

void maquina_estado()
{
	msg = 1; // SOLO DEBUGGING
	msg_ok=1;// SOLO DEBUGGING
		static int estado = LEER_MSG;

		switch(estado)
		{
			case LEER_MSG:
			
				if((msg==0))	// Flag: msg
				{
					
					estado = LEER_MSG;
		
				}
				if((msg==1))
				{
					validar_msg();
					estado = VALIDAR_MSG;
		
				}

				break;
			
			case VALIDAR_MSG:
			
				if((msg_ok==1))
				{
					
					estado = MOVER;
					cont_periodo =0; // Pone en cero el contador de período justo antes de mover

				}
				if((msg_ok==0))
				{
					error_report();
					estado = LEER_MSG;
		
				}
				if((msg_ok==2))
				{
					
					estado = CARGAR_CONFIG;
		
				}

				break;
			
			case MOVER:

				is_moving += mover_motor( MOTOR_DEDO_1   , pos_ini[MOTOR_DEDO_1]  , pos_fin[MOTOR_DEDO_1] , vel[MOTOR_DEDO_1]  , acel[MOTOR_DEDO_1] );
				is_moving += mover_motor( MOTOR_DEDO_2   , pos_ini[MOTOR_DEDO_2]  , pos_fin[MOTOR_DEDO_2] , vel[MOTOR_DEDO_2]  , acel[MOTOR_DEDO_2] );
				is_moving += mover_motor( MOTOR_DEDO_3   , pos_ini[MOTOR_DEDO_3]  , pos_fin[MOTOR_DEDO_3] , vel[MOTOR_DEDO_3]  , acel[MOTOR_DEDO_3] );
				is_moving += mover_motor( MOTOR_DEDO_4   , pos_ini[MOTOR_DEDO_4]  , pos_fin[MOTOR_DEDO_4] , vel[MOTOR_DEDO_4]  , acel[MOTOR_DEDO_4] );
				is_moving += mover_motor( MOTOR_DEDO_5   , pos_ini[MOTOR_DEDO_5]  , pos_fin[MOTOR_DEDO_5] , vel[MOTOR_DEDO_5]  , acel[MOTOR_DEDO_5] );
				is_moving += mover_motor( MOTOR_MUNIECA  , pos_ini[MOTOR_MUNIECA] , pos_fin[MOTOR_MUNIECA], vel[MOTOR_MUNIECA] , acel[MOTOR_MUNIECA] );
				is_moving += mover_motor( MOTOR_CODO     , pos_ini[MOTOR_CODO]    , pos_fin[MOTOR_CODO]   , vel[MOTOR_CODO]    , acel[MOTOR_CODO] );
				is_moving += mover_motor( MOTOR_EXTRA    , pos_ini[MOTOR_EXTRA]   , pos_fin[MOTOR_EXTRA]  , vel[MOTOR_EXTRA]   , acel[MOTOR_EXTRA] );

				if((is_moving >= 1))
				{
					
					estado = MOVER;
		
				}
				if((is_moving==0))
				{
					
					estado = LEER_MSG;
		
				}

				is_moving = 0;

				break;
			
			case CARGAR_CONFIG:
			
				if((msg_ok==2))
				{
					
					estado = LEER_MSG;
		
				}

				break;
			
			default: estado = LEER_MSG;
		}


}

//Funciones asociadas a los eventos

//Funciones asociadas a las acciones

/**
*	\fn void validar_msg(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:53:22
*/
void validar_msg(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void error_report(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:53:22
*/
void error_report(void)
{
	

	//Codigo propio de la funcion



	

}

