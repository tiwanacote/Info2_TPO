/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author 
*	\date 23-09-2017 09:54:06
*/






int contm1 = 0 ;int ninguna = 0 ;int m0 = 0 ;int Flagcorriente = 0 ;
#include "funciones.h" 

//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details 
*	\author 
*	\date 23-09-2017 09:54:06
*/
void maquina_estado()
{
		static int estado = TRANSFORMAR;

		switch(estado)
		{
			case TRANSFORMAR:
			
				if((ninguna==0))
				{
					m0max=ang_to_m0();
					Feed_to_m1cont()();
					contm1=0;

					estado = CONTANDO;
		
				}

				break;
			
			case CONTANDO:
			
				if((contm1<contm1max))
				{
					contm1=contm1+1();
					estado = CONTANDO;
		
				}
				if((contm1==contm1max) && (m0<m0max))
				{
					m0=m0+DELTA();
					estado = MOVER;
		
				}
				if((contm1==contm1max) && (m0>m0max))
				{
					m0=m0-DELTA();
					estado = MOVER;
		
				}

				break;
			
			case MOVER:
			
				if((m0!=m0max))
				{
					
					estado = CONTANDO;
		
				}
				if((m0==m0max) || (Flagcorriente==1))
				{
					
					estado = SALIR;
		
				}

				break;
			
			case SALIR:
			

				break;
			
			default: estado = TRANSFORMAR;
		}


}

//Funciones asociadas a los eventos

/**
*	\fn int ang_to_m0(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:06
*/
int ang_to_m0(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

//Funciones asociadas a las acciones

/**
*	\fn void M0MAX(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:06
*/
void M0MAX(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void m0max=ang_to_m0()(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:06
*/
void m0max=ang_to_m0()(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void Feed_to_m1cont()(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:06
*/
void Feed_to_m1cont()(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void contm1=contm1+1(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:06
*/
void contm1=contm1+1(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void m0=m0+DELTA(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:06
*/
void m0=m0+DELTA(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void m0=m0-DELTA(void)
*	\brief Resumen
*	\details Detalles
*	\author 
*	\date 23-09-2017 09:54:06
*/
void m0=m0-DELTA(void)
{
	

	//Codigo propio de la funcion



	

}

