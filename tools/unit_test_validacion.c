/**
 * @file unit_test_validacion.c
 * @author Maximiliano
 * @date 7/8/2017
 * @brief Este archivo es solo de desarrollo. Permite probar las funciones de validaciones de strings que legan desde el puerto de comunicación
 * 
 * Compilación: gcc unit_test_validacion.c -o validacion
 * 
 * Run: ./validacion
 * 
 * 
 */


#include <stdio.h>

#define G01_LENGTH 14 
#define G02_LENGTH 4
#define C_LENGHT 15

#define G01_VAL_LENGTH 7 // Largo de los vectores que se utilizan para la validacion del string G01


int g01_validation_range (int *vector_in, int *min_pos_vector, int *max_pos_vector, int *G01_max_f_vector, int length);
int main2();
int main2(void)
{
	int resultado;
	
	/* ----------------------------------------------------------------
	 * Las siguientes variables deberán entrar cargadas en un vector.
	 * Aquí solo se definen para probar las func. que se desarrollan
	 * ---------------------------------------------------------------*/
	
	int d0 = 10;	// Posición en grados del dedo 0 - Pulgar
	int d1 = 10;
	int d2 = 20;
	int d3 = 30;
	int d4 = 40;
	int m  = 50;	// Posición en grados de la muñeca
	int c  = 90;	// Posición en grados del codo
	
	int fd0 = 100;	// Velocidad en grados por segundo del dedo 0 - Pulgar. Se usa en G01
	int fd1 = 200;
	int fd2 = 300;
	int fd3 = 400;
	int fd4 = 500;
	int fm  = 600;	// Velocidad en grados por segundo de la muñeca. Se usa en G01
	int fc  = 700;	// Velocidad en grados por segundo del codo. Se usa en G01
	
//	int f   = 350;	// Velocidad en grados por segundo general.Se usa solo en G02
	
	int G01_vector[G01_LENGTH]={d0,d1,d2,d3,d4,m,c,fd0,fd1,fd2,fd3,fd4,fm,fc};	// Vector de posición con velocidades independientes
	
	
	/* ----------------------------------------------------------------
	 * Estas variables se deberían cargar a partir del archivo de 
	 * configuración que se envíe desde la PC
	 * ---------------------------------------------------------------*/
	
	int min_pos_d0 = 0;			// Posición mínima en grados del dedo 0 - Pulgar
	int min_pos_d1 = 0;
	int min_pos_d2 = 0;
	int min_pos_d3 = 0;
	int min_pos_d4 = 0;
	int min_pos_m  = 0;			// Posición mínima en grados de la muñeca
	int min_pos_c  = 0;			// Posición mínima en grados del codo

	int max_pos_d0 = 180;		// Posición máxima en grados del dedo 0 - Pulgar
	int max_pos_d1 = 180;
	int max_pos_d2 = 180;
	int max_pos_d3 = 180;
	int max_pos_d4 = 180;
	int max_pos_m  = 180;		// Posición máxima en grados de la muñeca
	int max_pos_c  = 180;		// Posición máxima en grados del codo
	
	
	int max_f_d0 = 1000;	// Velocidad máxima en grados por segundo del dedo 0 - Pulgar. Se usa en G01
	int max_f_d1 = 1000;
	int max_f_d2 = 1000;
	int max_f_d3 = 1000;
	int max_f_d4 = 1000;
	int max_f_m  = 1000;	// Velocidad  máxima en grados por segundo de la muñeca. Se usa en G01
	int max_f_c  = 1000;	// Velocidad  máxima en grados por segundo del codo. Se usa en G01
	
	//int max_f   = 350;	// Velocidad en grados por segundo general.Se usa solo en G02
	
	int G01_min_pos_vector[G01_VAL_LENGTH] = {min_pos_d0, min_pos_d1, min_pos_d2, min_pos_d3, min_pos_d4, min_pos_m, min_pos_c};	// Vector de posiciones mínimas
	int G01_max_pos_vector[G01_VAL_LENGTH] = {max_pos_d0, max_pos_d1, max_pos_d2, max_pos_d3, max_pos_d4, max_pos_m, max_pos_c};	// Vector de posiciones máximas
	int G01_max_f_vector[G01_VAL_LENGTH]   = {max_f_d0, max_f_d1, max_f_d2, max_f_d3, max_f_d4, max_f_m, max_f_c};					// Vector de velocidades máximas
	
	/* ----------------------------------------------------------------*/
	

	resultado = g01_validation_range(G01_vector, G01_min_pos_vector, G01_max_pos_vector, G01_max_f_vector ,G01_VAL_LENGTH);
	
	if (resultado == 1)
		printf("HAY ERROR \n");
	else
		printf("Esta todo way... \n");
		
	return 0;
}




/** @brief 	Valida si en el vector G01 enviado los valores estan en 
 *  	   	rango o no. De no estarlo reconoce un error y devuelve 
 * 		   	un 0
 *		   
 *
 *  @param vector_in      : Vector de entrada a analizar si esta fuera de rango
 *  @param min_pos_vector : Vector de posiciones mínimas admitidas
 *  @param max_pos_vector : Vector de posiciones máximas admitidas
 *  @param max_f_vector   : Vector de velocidades máximas admitidas
 *  @param length         : Largo del vector a recorrer. Para el caso del G01 siempre sera la mitad del largo del vector G01
 *  @return Si hay error devuelve 1, de lo contrario 0
 */
int g01_validation_range (int *vector_in, int *min_pos_vector, int *max_pos_vector, int *max_f_vector, int length){
	
	
	
	
	
	int i=0;
	
	
	for (i = 0; i < length; ++i){ 
		printf("vector_in[%i]: %i < min_pos_vector[%i]: %i",i,vector_in[i], i , min_pos_vector[i]);
		if (vector_in[i] < min_pos_vector[i]){
			printf(" < ---------- ");
			return 1;
		}
		printf("\n");
	}
	
     
    printf("\n");
     
    for (i = 0; i < length; ++i) {
		printf("vector_in[%i]: %i > max_pos_vector[%i]: %i",i,vector_in[i], i ,max_pos_vector[i]);
		if (vector_in[i] > max_pos_vector[i]){
			printf(" < ---------- ");
			return 1;
		}
		printf("\n");
    } 
    
    printf("\n");
     
    for (i = G01_VAL_LENGTH; i < (G01_VAL_LENGTH * 2); ++i){
		printf("vector_in[%i]: %i > max_f_vector[%i]: %i",i,vector_in[i], i-G01_VAL_LENGTH , max_f_vector[i-G01_VAL_LENGTH]);
		if (vector_in[i] > max_f_vector[i-G01_VAL_LENGTH]){
			printf(" < ---------- ");
			return 1;
		}
		printf("\n");
	}

	
	return 0;	// Sin errores
}


