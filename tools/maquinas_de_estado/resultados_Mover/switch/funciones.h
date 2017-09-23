/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author 
*	\date 23-09-2017 09:54:06
*/

//Declaracion de constantes
#define TRUE  1
#define FALSE  0

//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define 	TRANSFORMAR	0
#define 	CONTANDO	1
#define 	MOVER	2
#define 	SALIR	3

//Prototipos de los eventos
int ang_to_m0(void);

//Prototipos de las acciones
void M0MAX(void);
void m0max=ang_to_m0()(void);
void Feed_to_m1cont()(void);
void contm1=contm1+1(void);
void m0=m0+DELTA(void);
void m0=m0-DELTA(void);
