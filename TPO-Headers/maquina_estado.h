/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author 
*	\date 23-09-2017 09:53:22
*/

//Declaracion de constantes
#define TRUE  1
#define FALSE  0

//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define 	LEER_MSG	0
#define 	VALIDAR_MSG	1
#define 	MOVER	2
#define 	CARGAR_CONFIG	3

//Prototipos de los eventos

//Prototipos de las acciones
void validar_msg(void);
void error_report(void);


#include <cinematica.h>
