/**
*	\file main.c
*	\brief Resumen del contenido del archivo
*	\details Descripcion detallada del archivo
*	\author 
*	\date 23-09-2017 09:53:22
*/

#include <maquina_estado.h>



extern int msg;extern int msg_ok;extern int is_moving;


void main()
{

//declaracion de variables
//inicializacion de perifericos

	inicializar() ;


	while(1)
	{

		maquina_estado();

	}
}
