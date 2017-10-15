/*
 * global_variables.h
 *
 *  Created on: Sep 23, 2017
 *      Author: maximilano
 */

//#ifndef TPO_HEADERS_GLOBAL_VARIABLES_H_
//#define TPO_HEADERS_GLOBAL_VARIABLES_H_

//#endif /* TPO_HEADERS_GLOBAL_VARIABLES_H_ */

#include <Infotronic.h>

extern uint32_t cont_periodo;	// Cuenta la catidad de períodos. En cada período debería cambiar el PWM y con ello la posición del servo
extern uint32_t pos_motor[8];	// Posición del motor expresado en número de cuentas. Si es 56, entonces luego de 56 Mach0 se pone en cero la salida.
extern uint8_t flag_dead_time;	// Avisa cuando aparece el tiempo muerto utilizable para poder hacer los cálculos de la siguiente posición
extern uint8_t flag_stop[8];	// Si se activa el flag por el sensor de corriente o por parada de emergencia entonces se frenan el motor


extern int pos_ini[8];
extern int pos_fin[8];
extern int vel[8];
extern int acel[8];
