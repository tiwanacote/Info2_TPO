/*
 * global_variables.c
 *
 *  Created on: Sep 23, 2017
 *      Author: maximilano
 */

#include <global_variables.h>


// Inicializamos las variables

uint32_t cont_periodo = 0;							// Cuenta la catidad de períodos. En cada período debería cambiar el PWM y con ello la posición del servo
uint32_t pos_motor[8] = {54,54,54,54,54,54,54,54};	// Posición del motor expresado en número de cuentas. Si es 56, entonces luego de 56 Mach0 se pone en cero la salida.
uint8_t flag_dead_time = 0;							// Avisa cuando aparece el tiempo muerto utilizable para poder hacer los cálculos de la siguiente posición
uint8_t flag_stop[8] = {0,0,0,0,0,0,0,0};			// Si se activa el flag por el sensor de corriente o por parada de emergencia entonces se frenan el motor

