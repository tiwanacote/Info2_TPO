/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author 
*	\date 23-09-2017 09:54:18
*/

//Declaracion de constantes
#define TRUE  1
#define FALSE  0

//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define 	SEGMENT_MSG	0
#define 	DIGIT_VALIDATION	1
#define 	RANGE_VALIDATION	2
#define 	CARGAR_VECTOR	3
#define 	ERROR_1_G	4
#define 	ERROR_2_G	5
#define 	A_MOVER_MOTORES	6
#define 	A_CARGAR_CONFIG	7
#define 	ERROR_3_C	8

//Prototipos de los eventos

//Prototipos de las acciones
void vector_count=0(void);
void vector_size=9(void);
void vector_count=vector_count+1(void);
void vector[vector_count](void);
void msg_ok=1(void);
void msg_ok=2(void);
void in_range=0(void);
