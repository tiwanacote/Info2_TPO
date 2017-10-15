/*
 * global_variables.c
 *
 *  Created on: Sep 23, 2017
 *      Author: maximilano
 */

#include <global_variables.h>


// Inicializamos las variables

uint32_t cont_periodo = 0;							// Cuenta la catidad de períodos. En cada período debería cambiar el PWM y con ello la posición del servo
uint32_t pos_motor[8] = {54,54,54,54,54,54,54,54};	// Posición instantanea del motor expresado en número de cuentas. Se pone en 54 porque equivale al ángul 0 del servo
uint8_t flag_dead_time = 0;							// Avisa cuando aparece el tiempo muerto utilizable para poder hacer los cálculos de la siguiente posición
uint8_t flag_stop[8] = {0,0,0,0,0,0,0,0};			// Si se activa el flag por el sensor de corriente o por parada de emergencia entonces se frenan el motor



int pos_ini[8]={54,54,54,54,54,54,54,54};
int pos_fin[8]={500,500,500,500,500,500,500,500};
int vel[8]={15,15,15,15,15,15,15,15};
int acel[8]={1,1,1,1,1,1,1,1};
