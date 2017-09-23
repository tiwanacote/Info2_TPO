/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author 
*	\date 23-09-2017 09:54:18
*/












int vector_count = 0 ;int first_char = 0 ;int vecto_G_size = 0 ;int VECTOR_G = 0 ;int VECTOR_C = 0 ;int is_digit = 0 ;int vector_size = 0 ;int in_range = 0 ;int msg_ok = 0 ;int error = 0 ;
#include "funciones.h" 

//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details 
*	\author 
*	\date 23-09-2017 09:54:18
*/
void maquina_estado()
{
		static int estado = SEGMENT_MSG;

		switch(estado)
		{
			case SEGMENT_MSG:
			
				if((first_char==g))
				{
					vector_size=9;
					vector_count=vector_count+1;

					estado = DIGIT_VALIDATION;
		
				}
				if((first_char==c))
				{
					vector_size=22;
					vector_count=vector_count+1;

					estado = DIGIT_VALIDATION;
		
				}

				break;
			
			case DIGIT_VALIDATION:
			
				if((first_char==g) && (is_digit==1))
				{
					
					estado = RANGE_VALIDATION;
		
				}
				if((first_char==c) && (is_digit==1))
				{
					
					estado = CARGAR_VECTOR;
		
				}
				if((is_digit==0) && (first_char==g))
				{
					msg_ok=0;
					error=1;

					estado = ERROR_1_G;
		
				}
				if((is_digit==0) && (first_char==c))
				{
					msg_ok=0;
					error=3;

					estado = ERROR_3_C;
		
				}

				break;
			
			case RANGE_VALIDATION:
			
				if((in_range==1))
				{
					
					estado = CARGAR_VECTOR;
		
				}
				if((in_range==0))
				{
					msg_ok=0;
					error=2;

					estado = ERROR_2_G;
		
				}

				break;
			
			case CARGAR_VECTOR:
			
				if((vector_count<vector_size))
				{
					cargar_vector(vector_count ();
					 token)();

					estado = SEGMENT_MSG;
		
				}
				if((vector_count==vector_size) && (first_char==g))
				{
					msg_ok=1();
					estado = A_MOVER_MOTORES;
		
				}
				if((vector_count==vector_size) && (first_char==c))
				{
					msg_ok=2();
					estado = A_CARGAR_CONFIG;
		
				}

				break;
			
			case ERROR_1_G:
			

				break;
			
			case ERROR_2_G:
			

				break;
			
			case A_MOVER_MOTORES:
			

				break;
			
			case A_CARGAR_CONFIG:
			

				break;
			
			case ERROR_3_C:
			

				break;
			
			default: estado = SEGMENT_MSG;
		}


}

//Funciones asociadas a los eventos

//Funciones asociadas a las acciones

/**
*	\fn void vector_count=0(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:18
*/
void vector_count=0(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void vector_size=9(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:18
*/
void vector_size=9(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void vector_count=vector_count+1(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:18
*/
void vector_count=vector_count+1(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void vector[vector_count](void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:18
*/
void vector[vector_count](void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void msg_ok=1(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:18
*/
void msg_ok=1(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void msg_ok=2(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:18
*/
void msg_ok=2(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void in_range=0(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:18
*/
void in_range=0(void)
{
	

	//Codigo propio de la funcion



	

}

