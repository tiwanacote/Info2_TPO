/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author 
*	\date 23-09-2017 09:53:22
*/





int msg = 0 ;int msg_ok = 0 ;int is_moving = 0 ;
#include "funciones.h" 

//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details 
*	\author 
*	\date 23-09-2017 09:53:22
*/
void maquina_estado()
{
		static int estado = LEER_MSG;

		switch(estado)
		{
			case LEER_MSG:
			
				if((msg==0))
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
			
				if((is_moving==1))
				{
					
					estado = MOVER;
		
				}
				if((is_moving==0))
				{
					
					estado = LEER_MSG;
		
				}

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

